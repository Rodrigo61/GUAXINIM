// http://ki.staszic.waw.pl/task.php?name=bombki
#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 1123

int N;
vii vals;
int dp[MAXN][MAXN];
int vis[MAXN][MAXN];

int solve(int idx, int can_use)
{
	if (can_use == 0)
		return 0;
	
	if (idx == N)
	{
		return INF;
	}
	
	if (vis[idx][can_use])
	{
		return dp[idx][can_use];
	}
	vis[idx][can_use] = 1;
	
	solve(idx, can_use - 1);
	
	int res = solve(idx + 1, can_use) ;
	int rec = solve(idx + 1, can_use - 1);
	if (rec <= vals[idx].fi)
		res = min(res, rec + vals[idx].se);
	
	return dp[idx][can_use] = res;
}

int main()
{
	scanf("%d", &N);
	vals.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &vals[i].fi, &vals[i].se);
	}
	sort(all(vals), [](pii &a, pii &b){
		return b.fi + b.se < a.fi + a.se;
	});
	
	//~ for (auto p : vals)
	//~ {
		//~ printf("%d %d\n", p.fi, p.se);
	//~ } printf("\n");
	
	solve(0, N);
	
	for (int i = N; i >= 0; i--)
	{
		if (dp[0][i] < INF)
		{
			printf("%d\n", i);
			break;
		}
	}
	
	//~ printf("  ");
	//~ for (int j = 0; j <= N; j++)
		//~ printf("%d ", j);
	//~ printf("\n");
	
	//~ for (int i = 0; i < N; i++)
	//~ {
		//~ printf("%d ", i);
		//~ for (int j = 0; j <= N; j++)
		//~ {
			//~ printf("%d ", dp[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	
}
