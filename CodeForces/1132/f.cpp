#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

#define MAXN 512

int N;
string target;
char aux[MAXN];
vi positions[MAXN][MAXN];
int vis[MAXN][MAXN];
int dp[MAXN][MAXN];

int solve(int l, int r)
{
	if (l == r)
		return 1;
	if (l > r)
		return 0;
	
	if (vis[l][r])
	{
		return dp[l][r];
	}
	vis[l][r] = 1; 
	
	int res1 = solve(l + 1, r) + 1;
	int res2 = INF;
	for(int next_letter_pos : positions[l][r])
	{
		res2 = min(res2, solve(l + 1, next_letter_pos - 1) + solve(next_letter_pos, r));
	}
	
	return dp[l][r] = min(res1, res2);
}

void calc_positions()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = i + 1; k <= j; k++)
			{
				if (target[k] == target[i])
				{
					positions[i][j].pb(k);
				}
			}
		}
	}
	
}

int main()
{
	scanf("%d", &N);
	scanf("%s", aux);
	char last = 0;
	for (int i = 0; i < N; i++)
	{
		if (aux[i] != last)
			target.pb(aux[i]);
		last = aux[i];
	}
	db(target);
	N = target.size();
	calc_positions();
	printf("%d\n", solve(0, N - 1));
}
