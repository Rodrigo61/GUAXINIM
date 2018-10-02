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

#define MAXN 1000001

int next_to[MAXN];
int vis[MAXN];
int N, K;
int cycles[MAXN];
int n_cycles;

void dfs(int u, int *n_found)
{
	db(u);
	if (*n_found < K)
	{
		*n_found += 1;
	}
	vis[next_to[u]] = 1;
	
	if (!vis[next_to[next_to[next_to[u]]]])
	{
		vis[next_to[u]] = 1;
		vis[next_to[next_to[u]]] = 1;
		
		dfs(next_to[next_to[u]], n_found);
	}
}

int get_max()
{
	int n_found = 0;
	fill(vis, vis + N + 1, 0);
	
	for (int i = 1; i <= N; i++)
	{
		if (!vis[i] && !vis[next_to[i]])
		{
			db(i);
			vis[i] = 1;
			vis[next_to[i]] = 1;
			dfs(i, &n_found);
		}
	}
	
	db(n_found);
	int ans = n_found * 2;
	ans += K - n_found;
	
	return min(ans, N);
}

int dfs2(int u)
{
	
	vis[u] = 1;
	
	if (!vis[next_to[u]])
	{
		return dfs2(next_to[u]) + 1;
	}
	
	return 1;
}

void calc_cycles()
{
	fill(vis, vis + N + 1, 0);
	
	for (int i = 1; i <= N; i++)
	{
		if (!vis[i])
		{
			cycles[n_cycles] = dfs2(i);
			db(cycles[n_cycles]);
			++n_cycles;
		}
	}
}

int get_min()
{
	calc_cycles();

	bitset<MAXN> dp(1);
	
	for (int i = 0; i < n_cycles; i++)
	{
		dp = (dp<<cycles[i])|dp;
	}
	
	if (dp[K] == 1)
	{
		return K;
	}
	else
	{
		return K + 1;
	}
	
}

int main() 
{
	scanf("%d %d", &N, &K);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &next_to[i]);
	}
	

	printf("%d ", get_min());
	printf("%d\n", get_max());
	
	return 0;
}
