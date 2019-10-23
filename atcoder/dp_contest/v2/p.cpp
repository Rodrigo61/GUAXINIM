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

#define MAXN 112345

const int mod = 1e9+7;

int n;
vi adj[MAXN];
int vis[MAXN][2];
ll dp[MAXN][2];

ll mul_mod(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}

ll add_mod(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

ll solve(int u, int p_black, int pu)
{
    if (adj[u].size() == 1 && pu != 0)
    {
        return p_black ? 1:2;
    }

    if (vis[u][p_black])
        return dp[u][p_black];
    vis[u][p_black] = 1;

    ll res = 1;
    ll res_b = 1;
    for (int v : adj[u])
    {
        if (v != pu)
        {
            res = mul_mod(res, solve(v, 0, u));
            res_b = mul_mod(res_b, solve(v, 1, u));
        }
    }        

    if (!p_black)
        res = add_mod(res, res_b);

    return dp[u][p_black] = res;
}

int main()
{
    scanf("%d", &n);

    if (n == 1)
        return !printf("2\n");

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    printf("%lld\n", solve(1, 0, 0));
    
}