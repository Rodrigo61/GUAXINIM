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

#define MAXN 205
#define INF (ll) 1000000000000000

int N, K, X;
ll vals[MAXN];
int vis[MAXN][MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN];

ll solve(int id, int last, int remain)
{
	if (id == N + 1)
	{
		db(remain);
		if (remain == 0)
		{
			return 0;
		}
		else
		{
			return -INF;
		}
	}
	
	if (vis[id][last][remain])
	{
		return dp[id][last][remain];
	}
	vis[id][last][remain] = 1;
	
	ll res = 0;
	if (id - last >= K)
	{
		res = solve(id + 1, id, remain - 1) + vals[id];
	}
	else
	{
		res = solve(id + 1, id, remain - 1) + vals[id];
		res = max(res, solve(id + 1, last, remain));
	}
	
	dp[id][last][remain] = res;
	return res;
}

int main() 
{
	scanf("%d%d%d", &N, &K, &X);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	ll s = solve(0, 0, X);
	
	if (s >= 0)
	{
		printf("%lld\n", s);
	}
	else
	{
		printf("-1\n");
	}
	
	
	return 0;
}
