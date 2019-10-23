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

#define MAXN 5123

vi adj[MAXN];
vi adj_i[MAXN];
int pred[MAXN];
int suc[MAXN];

int vis[MAXN];

void dfs_pred(int u)
{
    vis[u] = 1;
    for (int v : adj_i[u])
        if(!vis[v])
            dfs_pred(v);
}

void dfs_suc(int u)
{
    vis[u] = 1;
    for (int v : adj[u])
        if(!vis[v])
            dfs_suc(v);
}


int main()
{
    int a, b, n, m;
    scanf("%d%d%d%d", &a, &b, &n, &m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj_i[v].pb(u);
    }

    for (int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs_pred(i);
        pred[i] = count(vis, vis + n, 1) -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs_suc(i);
        suc[i] = count(vis, vis + n, 1) -1;
    }

    vi ans(3);
    for (int i = 0; i < n; i++)
    {
        if (suc[i] >= n - a)
            ans[0]++;
        if (suc[i] >= n - b)
            ans[1]++;
        if (pred[i] >= b)
            ans[2]++;
    }

    for (int i : ans)
        printf("%d\n", i);
    

    
}