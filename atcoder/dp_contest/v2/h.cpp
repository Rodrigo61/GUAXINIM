#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MAXN 1123

#define MOD 1000000007

int n, m;
int grid[MAXN][MAXN];
int vis[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll solve(int i, int j)
{
    if (i == n - 1 && j == m - 1)
        return 1;

    if (vis[i][j])
        return dp[i][j];
    vis[i][j] = 1;

    if (!grid[i][j]) return 0;

    return dp[i][j] = (solve(i + 1, j) + solve(i, j + 1)) % MOD;
}

int main()
{
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            scanf("%c", &c);
            grid[i][j] = c == '.';
        }
        scanf("\n");
    }

    printf("%lld\n", solve(0, 0));
    
}