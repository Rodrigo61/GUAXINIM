#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
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

int n, m;
vi adj[MAXN];
bool is_target[MAXN];
int vis1[MAXN];
int vis2[MAXN];

void dfs1(int u, int deep, int &max_deep, int &u_deeper)
{
    vis1[u] = 1;

    if (is_target[u] && deep > max_deep)
    {
        max_deep = deep;
        u_deeper = u;
    }

    for (auto v : adj[u])
    {
        if (!vis1[v])
        {
            db(v);
            dfs1(v, deep + 1, max_deep, u_deeper);
        }
    }
}

bool dfs2(int u, int tail, int path, int &target)
{
    vis2[u] = 1;

    bool res = false;

    if (u == tail)
        res =  true;

    for (int v : adj[u])
    {
        if (!vis2[v])
        {
            if (dfs2(v, tail, path - 1, target))
                res = true;
        }
    }

    if (path == 0 && res)
        target = u;


    return res;
}

pii get_target() {
    int max_deep = -1;
    int u_deeper = 0;
    dfs1(1, 0, max_deep, u_deeper);
    max_deep  = -1;
    int root = u_deeper;
    db(root);
    
    memset(vis1, 0, sizeof(vis1));
    dfs1(u_deeper, 0, max_deep, u_deeper);
    
    int tail = u_deeper;
    db(tail);

    db(max_deep);

    if (max_deep % 1) 
        return {-1, 0};

    int target = -1;
    int target_dist = max_deep / 2;
    db(target_dist);
    dfs2(root, tail, target_dist, target);

    return {target, target_dist};
}

int dist[MAXN];
int vis3[MAXN];

void dfs3(int u, int d)
{
    vis3[u] = 1;
    dist[u] = d;

    for (int v : adj[u])
        if (!vis3[v])
            dfs3(v, d + 1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    for (int i = 0; i < m; i++)
    {
        int u;
        scanf("%d", &u);
        is_target[u] = 1;
    }

    auto res = get_target();

    if (res.fi == -1)
        return !printf("NO\n");
    
    dfs3(res.fi, 0);

    for (int i = 1; i <= n; i++)
    {
        if (is_target[i] && dist[i] != res.se)
            return !printf("NO\n");
    }
    

    printf("YES\n");
    printf("%d\n", res.fi);

}