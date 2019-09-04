#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 212345

ll N, A, B;
int vet[MAXN];
ll  dp[MAXN][2];
int vis[MAXN][2];
int t;

ll solve(int idx, int b)
{

	if (idx == N)
	{
		if (b == 1)
			return INF;
		return B;
	}
	
	if (b == 0 && vet[idx] == 1)
	{
		return INF;
	}
	
	if (vis[idx][b] == t)
		return dp[idx][b];
	vis[idx][b] = t;
	
	ll res = INF;
	
	if (vet[idx] == 0)
	{
		if (b == 0)
		{
			res = min(solve(idx + 1, 0) + A, solve(idx + 1, 1) + 2*A) + B;
		}
		else
		{
			res = min(solve(idx + 1, 1) + A, solve(idx + 1, 0) + 2 * A) + 2 * B;
		}
	}
	else
	{
		res = solve(idx + 1, 1) + A + 2 * B;
	}
	
	return dp[idx][b] = res;
	
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld\n", &N, &A, &B);
		for (int i = 0; i < N; i++)
		{
			char c;
			scanf("%c", &c);
			vet[i] = c - '0';
		}
		
		++t;
		printf("%lld\n", solve(0, 0));
		
	}
	
}
