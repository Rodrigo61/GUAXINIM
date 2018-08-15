#include<bits/stdc++.h>
#define MAXN 1005

using namespace std;

typedef long long ll;

#define EPS 1e-9

struct point {
	ll x, y;
	point(){
		x = y = 0ll;
	}
	point(ll _x, ll _y): x(_x), y(_y){
	}
};

struct vec{
	ll x, y;
	vec(ll _x, ll _y): x(_x), y(_y){
	}
};

vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y);
}

ll cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q, point r){
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

ll dot(vec a, vec b){
	return a.x*b.x + a.y*b.y;
}

long double norm_sq(vec v){
	return (long double)(v.x*v.x + v.y*v.y);
}

long double angle(point a, point o, point b){
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob)/(long double)sqrt(norm_sq(oa)*norm_sq(ob)));
} 

bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

bool inPolygon(point pt, const vector<point> &P){
	if((int)P.size() == 0) return false;
	long double sum = 0;
	for(int i = 0; i < (int)P.size() - 1; i++){
		if(ccw(pt, P[i], P[i+1]))
			sum += angle(P[i], pt, P[i+1]);
		else
			sum -= angle(P[i], pt, P[i+1]);
		
	}
	//cout << sum << endl;
	return fabs(fabs(sum) - 2*acos(-1)) < EPS;  
}

bool inPol(point pt, const vector<point> &P){
	for(int i = 0; i < (int)P.size() - 1; i++){
		if(pt.x == P[i].x && pt.y == P[i].y)
			return 1;
		else if(collinear(P[i], pt, P[i+1]) && dot(toVec(pt, P[i]), toVec(pt, P[i+1])) < -EPS)
			return 1;
	}
	
	return inPolygon(pt, P);
}



int main(){
	int s, r, m;
	cin >> s >> r >> m;
	
	vector<point> S, R, M;
	point aux, fi;
	
	for(int i = 0; i < s; i++){
		scanf("%lld %lld", &aux.x, &aux.y);
		if(i == 0){
			fi.x = aux.x;
			fi.y = aux.y;
		}
		S.push_back(aux);
	}
	S.push_back(fi);
	
	for(int i = 0; i < r; i++){
		scanf("%lld %lld", &aux.x, &aux.y);
		if(i == 0){
			fi.x = aux.x;
			fi.y = aux.y;
		}
		R.push_back(aux);
	}
	R.push_back(fi);
	
	for(int i = 0; i < m; i++){
		scanf("%lld %lld", &aux.x, &aux.y);
		if(i == 0){
			fi.x = aux.x;
			fi.y = aux.y;
		}
		M.push_back(aux);
	}
	M.push_back(fi);
	
	int n;
	cin >> n;
	//printf("n = %d\n", n);
	for(int i = 0; i < n; i++){
		scanf("%lld %lld", &aux.x, &aux.y);
		if(!inPol(aux, M))
			printf("Outside\n");
		else if(!inPol(aux, R))
			printf("Maria\n");
		else if(!inPol(aux, S))
			printf("Rose\n");
		else
			printf("Sheena\n");
	}
}


