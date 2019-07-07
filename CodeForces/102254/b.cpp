#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl
#define MAXN 2123
#define vi vector<int>
#define pb push_back
#define INF 0x3f3f3f3f

string A, B;
int vis[MAXN][MAXN];
int dp[MAXN][MAXN];

int solve(int ia, int ib)
{
	if (ia == (int)A.size() || ib == (int)B.size())
	{
		return 0;
	}
	
	if (vis[ia][ib])
	{
		return dp[ia][ib];
	}
	vis[ia][ib] = 1;
	
	int res = 0;
	
	if (A[ia] == B[ib])
	{
		res = solve(ia + 1, ib + 1) + 1;
	}
	
	res = max(res, solve(ia + 1, ib));
	res = max(res, solve(ia, ib + 1));
	
	return dp[ia][ib] = res;
}

int main()
{
	cin >> A >> B;
	printf("%d\n", solve(0, 0));
}
