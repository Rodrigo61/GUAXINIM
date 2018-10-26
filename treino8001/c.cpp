#include<bits/stdc++.h>

using namespace std;

#include<unistd.h>

#define db(x) //cerr << #x << " = " << x << endl;

#define MAXN 1005

#define ll long long

#define EPS 1e-9

struct point{
	double x, y;
	point()
	{
		x = y = 0;
	}
	
	point(double X, double Y){
		x = X;
		y  = Y;
	}
	
};

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line{
	double a, b, c;
};

struct vec{
	double x, y;
	vec(double X, double Y){
		x = X;
		y = Y;
	}
};

vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y);
}

point translate(point p, vec v){
	return point(p.x + v.x, p.y + v.y);
}

double norm_sq(vec v){
	return v.x*v.x + v.y*v.y;
}

double dot(vec a, vec b){
	return a.x*b.x + a.y*b.y;
}

vec scale(vec v, double s){
	return vec(s*v.x, s*v.y);
}

double distToLine(point p, point a, point b){
	point c;
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab)/norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

double cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q, point r){
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

point pivot;

bool angleCmp(point a, point b){
	if(collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;	
	return atan2(d1y, d1x) - atan2(d2y, d2x) < 0;
}

double cross(point O, point A, point B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool cmp(point p1, point p2)
{
	if(fabs(p1.x-p2.x) > EPS)
		return p1.x < p2.x;
	return p1.y < p2.y;
}

vector<point> CH(vector<point> pts)
{
	point P;
	vector<point> H;
	sort(pts.begin(), pts.end(), cmp);
	for(int j = 0; j < 2; j++)
	{
		int start = H.size();
		for (int i = 0; i < pts.size(); i++)
		{
			P = pts[i];
			while (H.size() >= start + 2 && cross(H[H.size() - 2], H[H.size() - 1], P) < 0)
			{
				H.pop_back();
			}
			H.push_back(P);
			
		}
		H.pop_back();
		reverse(pts.begin(), pts.end());
	}
	
	return H;
}

//~ vector<point> CH(vector<point> P){
	//~ int i, j, n = (int)P.size();
	//~ if(n <= 3){
		//~ return P;
	//~ }
	
	//~ int P0 = 0;
	//~ for(i = 0; i < n; i++)
		//~ if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			//~ P0 = i;
	
	//~ point temp = P[0];
	//~ P[0] = P[P0];
	//~ P[P0] = temp;
	
	//~ pivot = P[0];
	//~ sort(++P.begin(), P.end(), angleCmp);
	
	//~ vector<point> S;
	//~ S.push_back(P[n-1]);
	//~ S.push_back(P[0]);
	//~ S.push_back(P[1]);
	//~ i = 2;
	//~ while(i < n){
		//~ j = (int)S.size() - 1;
		//~ if(ccw(S[j-1], S[j], P[i]))
			//~ S.push_back(P[i++]);
		//~ else
			//~ S.pop_back();
	//~ }
	//~ S.pop_back();
	//~ return S;
	
//~ }

vector<point> P;

double ar(int i, int j){
	//~ printf("i = %d j = %d\n", i, j);
	double ar = 0.0;
	int ini = i + 1, end = j - 1;
	int mid;
	while(ini < end){
		//~ printf("%d %d\n", ini, end);
		mid = (ini + end)/2;
		if(distToLine(P[mid + 1], P[i], P[j]) > distToLine(P[mid], P[i], P[j]))
			ini = mid + 1;
		
		else
			end = mid;
	}
	
	ar = distToLine(P[ini], P[i], P[j]);
	
	ini = j + 1;
	end = i + (P.size())/2 - 1;
	//printf("i = %d %d j = %d\n", i, (P.size())/2, j);
	while(ini < end){
		//~ printf("2: %d %d\n", ini, end);
		mid = (ini + end)/2;
		if(distToLine(P[mid + 1], P[i], P[j]) > distToLine(P[mid], P[i], P[j]))
			ini = mid + 1;
		
		else
			end = mid;
	}
	
	ar += distToLine(P[ini], P[i], P[j]);
	
	ar *= dist(P[i], P[j])/2.0;
	
	return ar;
	
}

int main(){
	int T;
	cin >> T;
	while((T--) > 0){
		//printf("ok\n");
		int n;
		cin >> n;
		vector<point> v(n);
		for(int i  = 0; i < n; i++){
			scanf("%lf %lf", &v[i].x, &v[i].y);
		}
		P = CH(v);
		n = P.size();
		
		for(int i = 0; i <n; i++)
			P.push_back(P[i]);
		
		double area = 0.0;
		
		for(int i = 0; i < n; i++){
			for(int j = i + 2; j < n; j++){
				area = max(area, ar(i, j));
			}
		}
		
		if(area - (round(area)) < 0.4)
			printf("%lld\n", (ll)area);
		else
			printf("%.1lf\n", area);
			
	}
	return 0;
}
