#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
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

int N, F;
int t;
vector<pair<int, int>> graph[MAXN];
bool is_target[MAXN];
int vis[MAXN][2];
int dp[MAXN][2];

bool prune(int u)
{
    bool has_target = is_target[u];
    vii new_graph;
    for (auto p : graph[u])
    {
        bool useful_branch = prune(p.fi);
        has_target |= useful_branch;
        if (useful_branch)
            new_graph.pb(p);
    }
        
    graph[u] = new_graph;

    return has_target;
}

int solve(int u, int e)
{
    if (vis[u][e] == t)
        return dp[u][e];
    vis[u][e] = t;

    int tot = 0;
    for (auto p : graph[u])
    {
        int v = p.fi;
        int w = p.se;

        tot += solve(v, 0) + w;
    }   

    int res = tot;
    if (e)
    {
        for (auto p : graph[u])
        {
            int v = p.fi;
            int w = p.se;

            res = min(res, tot - solve(v, 0) - w + solve(v, 1));
        }
    }

    return dp[u][e] = res;
}

void restart()
{
    for (int i = 1; i <= N; i++)
    {
        graph[i].clear();
        is_target[i] = false;
    }   
}

int main()
{
    while (scanf("%d%d", &N, &F) != EOF)
    {
        restart();
        for (int i = 0; i < N - 1; i++)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[a].pb({b, w});
        }

        for (int i = 0; i < F; i++)
        {
            int u;
            scanf("%d", &u);
            is_target[u] = true;
        }
        
        
        prune(1);

        // for (int i = 1; i <= N; i++)
        // {
        //     printf("%d: ", i);
        //     for (auto p : graph[i])
        //         printf("%d ", p.fi);
        //     printf("\n");
        // }
        

        t++;
        printf("%d\n", solve(1, 1));
    }
}