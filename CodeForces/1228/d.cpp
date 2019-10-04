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

vii edges;
set<int> adj[MAXN];
int where[MAXN];

bool bipartite(int u)
{
    bool res = true;
    for (int v : adj[u])
        if (where[v] == 0)
        {
            where[v] = where[u] == 2 ? 3:2;
            res &= bipartite(v);
        }
        else if (where[v] == where[u])
            return false;
    return res;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        edges.pb({u, v});
        adj[u].insert(v);
        adj[v].insert(u);
    }

    where[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (adj[i].find(1) == adj[i].end())
            where[i] = 1;
    }

    for (auto e : edges)
    {
        if (where[e.fi] == 1 && where[e.se] == 1)
            return !printf("-1\n");
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (where[i] == 0)
        {
            where[i] = 2;
            if (!bipartite(i))
                return !printf("-1\n");
        }
    }
    
    vi sz(4);
    for (int i = 1; i <= n; i++)
    {
        sz[where[i]]++;
    }
    
    if (sz[1]*sz[2]*sz[3] != 0 && sz[1]*sz[2] + sz[1]*sz[3] + sz[2]*sz[3] == m)
        for (int i = 1; i <= n; i++)
            printf("%d ", where[i]);
    else
        printf("-1\n");
}