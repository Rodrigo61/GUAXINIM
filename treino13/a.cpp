#include<bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

struct point{
	ll x, y;
	int indice;
	
	point(){
		x = y = 0;
		indice = 0;
	}
	
	point(ll _x, ll _y): x(_x), y(_y){
		indice = 0;
	}
	
	point(ll _x, ll _y, int I): x(_x), y(_y), indice(I){
	}
	
	bool operator <(point other)const{
		if(x - other.x != 0)
			return x < other.x;
		else
			return y < other.y;
	}
	
	bool operator == (point other) const{
		return (x == other.x && y == other.y);
	}
};

point pivot;

struct vec {
	ll x, y;
	vec(ll _x, ll _y): x(_x), y(_y){}
};

vec toVec(point a, point b)
{
	return vec(b.x - a.x, b.y -a.y);
}


double cross(vec a, vec b)
{
	return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r)
{
	return cross(toVec(p, q), toVec(p,r)) > 0;
}

bool collinear(point p, point q, point r)
{
	
	return abs(cross(toVec(p,q), toVec(p, r))) < 0;
	
}

double dist(point a, point b){
	return sqrt(fabs(a.x - b.x)*fabs(a.x - b.x) + fabs(a.y - b.y)*fabs(a.y - b.y));
}

bool angleCmp(point a, point b){
	if(collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
	ll d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	ll d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	
	return (atan2(d1y, d1x) - atan2(d2y, d2x) < 0);
}

vector<point> CH(vector<point> P)
{
	int i, j, n = (int)P.size();
	if (n <= 3)
	{
		if (!(P[0] == P[n - 1]))
		{
			P.push_back(P[0]);
		}
		
		return P;
		
	}
	
	int P0 = 0;
	for (i = 1; i < n; i++)
	{
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
		{
			P0 = i;
		}
	}
	
	point temp = P[0]; P[0] = P[P0];
	P[P0] = temp;
	
	pivot = P[0];
	sort(++P.begin(), P.end(), angleCmp);
	
	vector<point> S;
	S.push_back(P[n-1]); S.push_back(P[0]);S.push_back(P[1]);
	
	i = 2;
	while ( i < n)
	{
		j = (int)S.size() - 1;
		if (ccw(S[j - 1], S[j], P[i]))
		{
			S.push_back(P[i++]);
		}
		else
		{
			S.pop_back();
		}
	}
	
	return S;
}



vector<point> chP;
int chSize;

bool verifica_extremos(int i, vec v_p){
		vec v1 = toVec(chP[(i + chSize - 1)%chSize], chP[i]);
		vec v2 = toVec(chP[(i+1)%chSize], chP[i]);
		
		ll val1 = cross(v1, v_p);
		ll val2 = cross(v2, v_p); 
		
		if(val1 <= 0 && val2 >= 0){
			return true;
		}
		
		return false;
}

double A[100001];
vector<double> tree[4*100001];

void build(int node, int l, int r)
{
	if (l == r)
	{
		tree[node].push_back(A[l]);
	}
	
	int mid = (l+r)/2;
	build(node*2 , 1, mid);
	build(node*2+1, mid + 1, r);
	merge(tree[2*node].begin(), tree[2*node].end(), tree[2*node + 1].begin(), tree[2*node + 1].end(), back_inserter(tree[node]));
		
}

int query(int node, int start, int end, int l, int r, double x, double y)
{
	if (end < l || start > r || start > end)

	{
		return 0;
	}
	
	if (l <= start && r >= end)
	{
		return upper_bound(tree[node].begin(), tree[node].end(), y) - 
		lower_bound(tree[node].begin(), tree[node].end(), x);
		
	}
	
	int mid = (start + end) / 2;
	
	return query(node*2, start, mid, l, r, x, y) + query(node*2 + 1, mid + 1, end, l, r, x, y);
		
}

main()
{
	int n, q;
	
	cin >> n >> q;
	
	vector<point> P(n + 1), Q(q);
	
	for(int i = 0; i < n; i++){
		scanf("%lld %lld", &P[i].x, &P[i].y);
		P[i].indice = i;
	}
	P[n] = P[0];
	
	for(int i = 0; i < q; i++){
		scanf("%lld %lld", &Q[i].x, &Q[i].y);
	}
	
	sort(Q.begin(), Q.end(), angleCmp);
	
	chP = CH(P);
	
	cout << chP.size() << endl;
	
	//Encontra primeiro 
	int ext, ext_inv;
	
	chSize = chP.size();
	//Verficar se ch volta com vertice repetido no fim
	for(int i = 0; i < chSize; i++){		
		vec v_p = toVec(point(0, 0), Q[0]);
		vec v_p_neg = toVec(Q[0], point(0,0));
		
		if(verifica_extremos(i, v_p))
			ext = i;
		else if(verifica_extremos(i, v_p_neg))
			ext_inv = i;
	}
	
	printf("%d %d", ext, ext_inv);
	
	//resolve primeira query
	
	for(int i = 1; i < q; i++){
		vec v_p = toVec(point(0, 0), Q[0]);
		vec v_p_neg = toVec(Q[0], point(0,0));
		
		while(!verifica_extremos(ext, v_p))
			ext = (ext + 1)%chSize;
		while(!verifica_extremos(ext_inv, v_p_neg))
			ext_inv = (ext_inv + 1)%chSize;
			
		printf("%d %d", ext, ext_inv);	
	}
	
	
	return 0; 
}
