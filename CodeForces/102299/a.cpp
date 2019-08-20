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
#define ub upper_bound
#define lb lower_bound

#define MAXN 51234
#define SQR 240

int vals[MAXN];
vi idxs[MAXN];
vi brute[SQR][SQR];

int main()
{
	int N, Q;
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
		idxs[vals[i]].pb(i);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < SQR; j++)
		{
			brute[j][vals[i] % j].pb(i);
		}
	}
	
	while (Q--)
	{
		int l, r, x, m;
		scanf("%d%d%d%d", &l, &r, &x, &m);
		--l, --r;
		if (m < SQR)
		{
			printf("%d\n", ub(all(brute[m][x]), r) - lb(all(brute[m][x]), l)) ;
		}
		else
		{
			int res = 0;
			for (int target = x; target < MAXN; target += m)
			{
				res += ub(all(idxs[target]), r) - lb(all(idxs[target]), l);
			}
			printf("%d\n", res);
		}
	}
	
}
