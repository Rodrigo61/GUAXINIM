#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

int rep[MAXN];

int get_rep(int u)
{
    if (rep[u] == 0) return u;
    return rep[u] = get_rep(rep[u]);
}

bool connect(int u, int v)
{
    int repu = get_rep(u);
    int repv = get_rep(v);

    if (repu == repv) return false;
    
    rep[repu] = repv;
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vi> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (connect(u, v))
            {
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }

        vi color_cnt(2);
        vi color(n + 1);
        vi vis(n + 1);
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    color[v] = !color[u];
                    color_cnt[color[v]]++;
                    q.push(v);
                }
            }
        }
        
        int target;
        if (color_cnt[0] <= color_cnt[1])
        {
            printf("%d\n", color_cnt[0]);
            target = 0;
        }
        else
        {
            printf("%d\n", color_cnt[1]);
            target = 1;
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == target)
                printf("%d ", i);
        }
        printf("\n");

        for (int i = 1; i <= n; i++)
        {
            rep[i] = 0;
        }
    }
    
}