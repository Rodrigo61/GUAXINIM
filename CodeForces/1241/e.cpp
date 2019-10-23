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

struct edge
{
    int u, v;
    ll w;
};

#define MAXN 512345
vi adj[MAXN];
vll W[MAXN];
int vis[MAXN][2];
ll dp[MAXN][2];
int n, k;
int vv;


ll solve(int u, int pu, int used_parent)
{
    if (adj[u].size() == 1 && pu != 0)
        return 0;
    
    if (vis[u][used_parent] == vv)
        return dp[u][used_parent];
    vis[u][used_parent] = vv;

    vector<pair<ll, ll>> recs;
    ll res = 0;
    for (int i = 0; i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        ll w = W[u][i];
        if (v != pu)
        {
            ll not_take = solve(v, u, 0);
            ll take = solve(v, u, 1) + w;
            res += not_take;
            recs.pb({not_take, take});
        }
    }
    

    sort(all(recs), [](pll a, pll b)
    {
        return a.se - a.fi > b.se - b.fi;
    });

    int t = used_parent ? k - 1: k;

    for (int i = 0; i < (int)recs.size() && i < t && recs[i].se > recs[i].fi; i++)
    {
        res += recs[i].se - recs[i].fi;        
    }
    
    return dp[u][used_parent] = res;
}

void clean()
{
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        W[i].clear();
    }
    
}


int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            ll w;
            scanf("%d%d%lld", &u, &v, &w);
            adj[u].pb(v);
            adj[v].pb(u);
            W[u].pb(w);
            W[v].pb(w);
            
        }
        ++vv;
        printf("%lld\n", solve(1, 0, 0));
        clean();
    }
    
}