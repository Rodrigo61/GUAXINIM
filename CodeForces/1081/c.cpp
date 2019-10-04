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

#define MOD 998244353
#define MAXN 2123

int n, m, k;
int vis[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll solve(int idx, int diff_r)
{
    if (idx == n)
    {
        return diff_r == 0;
    }

    if (idx == 0)
    {
        return (solve(idx + 1, diff_r) * m) % MOD;
    }

    if (diff_r < 0) return 0;

    if (vis[idx][diff_r])
        return dp[idx][diff_r];
    vis[idx][diff_r] = 1;
    
    ll res = solve(idx + 1, diff_r);
    res = (res + (solve(idx + 1, diff_r - 1)  * (m - 1)) % MOD) % MOD;

    return dp[idx][diff_r] = res;
    
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    printf("%lld\n", solve(0, k));
}