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

#define MAXN 300
#define MOD 1000000007

int n, k;
int vis[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll comb[MAXN][MAXN];

void calc_comb()
{
    for(int i = 0; i < MAXN; i++)
    {
        comb[i][0] = 1;
    }
    for(int i = 1; i < MAXN; i++)
    {
        for(int j = 1; j < MAXN; j++)
        {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%MOD;
        }
    }
}

ll mult_m(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll sub_m(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll add_m(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll pow_dp[2][MAXN];
int pow_vis[2][MAXN];

ll pow_m(ll b, ll e) {
    ll a = k - b;
    int t = e;
    if (a == 0 || a == 1)
    {
        if (pow_vis[a][t])
        {
            return pow_dp[a][t];
        }
        pow_vis[a][t] = 1;
    }

	ll ans = 1;
	for (; e; b = mult_m(b, b), e /= 2)
		if (e & 1) ans = mult_m(ans, b);

    if (a == 0 || a == 1)
    {
        return pow_dp[a][t] = ans;
    }
	    
    return ans;
}

ll solve(int r, int c)
{
    if (vis[r][c])
        return dp[r][c];
    vis[r][c] = 1;

    if (c == 0)
    {
        return dp[r][c] = pow_m(sub_m(pow_m(k, n), pow_m(k - 1, n)), r);
    }

    if (r == 1)
    {
        return dp[r][c] = pow_m(k, n - c);
    }

    ll res = mult_m(solve(r - 1, c), sub_m(mult_m(pow_m(k, n - c), pow_m(k - 1, c)), pow_m(k - 1, n)));
    for (int i = 1; i <= c; i++)
    {
        res = add_m(res, mult_m(solve(r - 1, c - i), mult_m(comb[c][i], mult_m(pow_m(k, n - c), pow_m(k - 1, c - i)))));
    }
    
  return dp[r][c] = res;
}

int main()
{
    scanf("%d%d", &n, &k);
    calc_comb();
    printf("%lld\n", solve(n, n));
}