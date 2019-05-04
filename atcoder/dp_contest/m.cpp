#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 112
#define MAXK 112345 
#define ll long long
#define fi first
#define se second
#define pll pair<ll, ll>
#define MOD 1000000007

int N, K;
int vals[MAXN];
ll dp[MAXN][MAXK];
ll prefix[MAXN][MAXK];

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll sub(ll a, ll b)
{
	return (a - b + MOD) % MOD;
}

ll get_prefix(int row, int L, int R)
{
	ll result = prefix[row][R];
	
	if (L - 1 >= 0)
		return sub(result, prefix[row][L - 1]);
	return result;
}

//no candies should be left over.
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	memset(dp, 0, sizeof(dp));
	dp[N][0] = 1;
	for (int i = 0; i <= K; i++)
	{
		prefix[N][i] = 1;
	}
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 1;
				prefix[i][j] = 1;
			}
			else
			{
				int c = min(j, vals[i]);
				dp[i][j] = add(dp[i][j], get_prefix(i + 1, j - c, j));
				prefix[i][j] = add(prefix[i][j - 1], dp[i][j]);
			}
		}
	}
	
	//~ for (int i = 0; i < N; i++)
	//~ {
		//~ for (int j = 0; j <= K; j++)
		//~ {
			//~ printf("%d ", prefix[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	
	//~ printf("\n");
	//~ for (int i = 0; i < N; i++)
	//~ {
		//~ for (int j = 0; j <= K; j++)
		//~ {
			//~ printf("%d ", dp[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	
	printf("%lld\n", dp[0][K]);
	
	return 0;
}

