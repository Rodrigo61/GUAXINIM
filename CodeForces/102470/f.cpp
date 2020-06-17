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
#define pii pair<int, ll>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;
#define sz(x) int(x.size())

#define MAXN 35
#define MAX2N MAXN*MAXN

int W, H;

struct hole
{
    int x, y;
    int t;
};

int grid[MAXN][MAXN];
hole grid_hole[MAXN][MAXN];
int vis[MAXN][MAXN];
int grid_id[MAXN][MAXN];
int id;
vector<pii> adj[MAX2N];
vector<pair<int, int>> neighs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void create_graph(int y, int x)
{
    if (x == W - 1 && y == H - 1) return;

    if (grid[y][x] == 2)
    {
        auto hole = grid_hole[y][x];
        if (!vis[hole.y][hole.x])
        {
            grid_id[hole.y][hole.x] = id++;
            vis[hole.y][hole.x] = 1;
            create_graph(hole.y, hole.x);
        }
        adj[grid_id[y][x]].push_back({grid_id[hole.y][hole.x], hole.t});
    } 
    else
    {
        for (auto n : neighs)
        {
            int xt = x + n.fi;
            int yt = y + n.se;

            if (x == 0 && y == 0)
            {
                db(xt);
                db(yt);
            }

            if (xt < 0 || xt >= W || yt < 0 || yt >= H || grid[yt][xt] == 1)
                continue;

            if (!vis[yt][xt])
            {
                grid_id[yt][xt] = id++;
                vis[yt][xt] = 1;
                create_graph(yt, xt);
            }
            adj[grid_id[y][x]].push_back({grid_id[yt][xt], 1});
        }
    }
}



ll dist[MAX2N];

ll bellmanford(int s, int t)
{
    for (int i = 0; i < id; ++i)
        dist[i] = INF;
    dist[s] = 0;
    bool negative = false;
    for (int i = 0; i < id; i++)
    {
        for (int u = 0; u < id; u++)
        {
            for (int j = 0; j < sz(adj[u]); ++j)
            {
                int v = adj[u][j].fi;
                ll w = adj[u][j].se;

                if (i == id - 1 && dist[v] > dist[u] + w)
                    negative = true;
                else
                {
                    dist[v] = min(dist[v], dist[u] + w);
                }
                    
            }
        }
    }

    if (negative)
        return -INF;
    return dist[t];
}

void restart()
{
    memset(grid, 0, sizeof(grid));
    memset(grid_id, 0, sizeof(grid_id));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < MAX2N; i++)
    {
        adj[i].clear();
    }
    id = 0;
}

int main()
{
    while(scanf("%d%d", &W, &H), W != 0) 
    {
        restart();
        int G;
        scanf("%d", &G);
        for (int i = 0; i < G; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            grid[y][x] = 1;
        }

        int E;
        scanf("%d", &E);
        for (int i = 0; i < E; i++)
        {
            int x, y, xt, yt, t;
            scanf("%d%d%d%d%d", &x, &y, &xt, &yt, &t);
            grid[y][x] = 2;
            grid_hole[y][x] = {xt, yt, t};
        }

        grid_id[0][0] = id++;
        vis[0][0] = 1;
        create_graph(0, 0);
        
 

        db(grid_id[H - 1][W - 1]);
        ll res = bellmanford(0, grid_id[H - 1][W - 1]);

        if (res == -INF)
            printf("Never\n");
        else
        {
            if (grid_id[H - 1][W - 1] == 0 && H*W > 1)
            {
                printf("Impossible\n");
                continue;
            }
            printf("%lld\n", res);
        }
        
        
    }

}