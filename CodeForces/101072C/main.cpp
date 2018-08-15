#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

#define MAXN 100005
#define MAXM 100005

int N, M;

struct Edge
{
	int u, v;
	ll w;
};

vector<int> G[MAXN], W[MAXN];

int p[MAXN], l[MAXN];
Edge e[MAXM];

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

void buildKruskal()
{
	for (int i = 0; i < N; i++)
	{
		p[i] = i;
		l[i] = 1;
	}
	
}

inline int id(int x)
{
	return (x != p[x] ? p[x] = id(p[x]) : p[x]);
}
 
inline ll kruskal() 
{
	int i, j, u, v;
	ll w;
	ll ans = 0;
	sort(e, e+M, cmp);
    for (i = 0, j = 1; i < M && j < N; i++) 
	{
        u = id(e[i].u);
		v = id(e[i].v);
		if(l[u] < l[v])
			swap(u, v);
		w = e[i].w;
        if (u != v)
		{
            p[v] = u;
            l[u] += l[v];
			j++;
			u = e[i].u;
			v = e[i].v;
			ans += w;
        }
    }
    
    return ans;
}


int main() 
{

	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		
		Edge a;
		a.u = u;
		a.v = v;
		a.w = w;
		
		e[i] = a;
	}
	
	buildKruskal();
	printf("%lld\n", kruskal());
	
	
	return 0;
}
