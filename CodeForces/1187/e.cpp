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

#define MAXN 212345

vi adj[MAXN];
ll res;
ll dp[MAXN];
ll sz[MAXN];

void dfs(int u, int pu)
{
    sz[u] = 1;
    dp[u] = 0;

    for (int v : adj[u])
        if (v != pu)
        {
            dfs(v, u);
            sz[u] += sz[v];
            dp[u] += dp[v];
        }
    
    dp[u] += sz[u];
}

void reroot(int u, int pu)
{
    res = max(res, dp[u]);

    for (int v : adj[u])
    {
        if (v != pu)
        {
            vll rollback = {dp[u], sz[u], dp[v], sz[v]};
            dp[u] -= sz[u];
            dp[u] -= dp[v];
            sz[u] -= sz[v];
            dp[u] += sz[u];

            dp[v] -= sz[v];
            dp[v] += dp[u];
            sz[v] += sz[u];
            dp[v] += sz[v];

            reroot(v, u);

            dp[u] = rollback[0];
            sz[u] = rollback[1];
            dp[v] = rollback[2];
            sz[v] = rollback[3];
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);
    reroot(1, 0);

    printf("%lld\n", res);
    
}