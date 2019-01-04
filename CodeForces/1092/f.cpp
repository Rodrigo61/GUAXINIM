#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
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

#define MAXN 200005
#define int long long

int N;
vi adj[MAXN];
int vals[MAXN];
int vis[MAXN], vis2[MAXN];
int down[MAXN];
int acu_down[MAXN];
int acu_up[MAXN];
int up[MAXN];

void dfs1(int u)
{
	vis[u] = 1;
	acu_down[u] = vals[u];
	for (int v : adj[u])
	{
		if (!vis[v])
		{
			dfs1(v);
			down[u] += down[v] + acu_down[v];
			acu_down[u] += acu_down[v];
		}
	}
}

void dfs2(int u, int top_total, int top_acu)
{
	top_total = top_total + top_acu;
	
	vis2[u] = 1;
	up[u] = top_total;
	
	top_total += down[u];
	top_acu += acu_down[u];
	
	for (int v : adj[u])
	{
		if (!vis2[v])
		{
			dfs2(v, top_total - (down[v] + acu_down[v]) ,top_acu - acu_down[v]);
		}
	}
}

main() 
{

	scanf("%lld", &N);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%lld%lld", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs1(1);
	dfs2(1, 0, 0);

	int maxi = 0;
	for (int i = 1; i <= N; i++)
	{
		maxi = max(maxi, down[i] + up[i]);
	}
	
	printf("%lld\n", maxi);
	
	return 0;
}
