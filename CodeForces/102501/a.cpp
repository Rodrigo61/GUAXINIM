#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
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
#define pb push_back
typedef long double ld;

#define MAXT 112
#define MAXN 1123
#define MAXB 112


pii S, T;
int B;
int C0;
int N;
ll vet_T[MAXT];
pii raw_V[MAXN];
vector<pii> raw_adj[MAXN];
int vis[MAXN][MAXB];
ll dp[MAXN][MAXB];
map<pii, int> map_id;


struct Edge{
    ll v, c, d;
};

vector<Edge> adj[MAXN];

ll dist(pii a, pii b)
{
    return (ll)ceil(sqrt((double)((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se)  * (a.se - b.se))));
}

void create_graph()
{
    int id = 0;

    for (int i = 0; i < N; i++)
    {
        if (map_id.find(raw_V[i]) == map_id.end())
        {
            map_id[raw_V[i]] = id++;
        }

        int u = map_id[raw_V[i]];

        for (auto pv : raw_adj[i])
        {
            int j = pv.fi;

            if (map_id.find(raw_V[j]) == map_id.end())
            {
                map_id[raw_V[j]] = id++;
            }

            int v = map_id[raw_V[j]];

            if (u == v) continue;

            ll t = pv.se;
            ll d = dist(raw_V[i], raw_V[j]);
            
            adj[u].pb({v, t * d, d});
            adj[v].pb({u, t * d, d});
        }
    }
}

ll solve(int u, int b)
{
    if (b < 0)
        return INF; 

    if (u == map_id[T])
        return 0;

    if (vis[u][b])
        return dp[u][b];
    vis[u][b] = 1;

    ll res = INF;
    for (auto pv : adj[u])
    {
        ll rec = solve(pv.v, b - pv.d);
        res = min(res, rec + pv.c);
    }

    return dp[u][b] = res;
}

int main()
{
    scanf("%d%d", &S.fi, &S.se);
    scanf("%d%d", &T.fi, &T.se);

    if (S == T)
        return !printf("0\n");

    scanf("%d", &B);
    scanf("%d", &C0);

    int qtdT;
    scanf("%d", &qtdT);

    for (int i = 0; i < qtdT; i++)
    {
        scanf("%d", &vet_T[i]);
    }
    
    scanf("%d", &N);
    N += 2;

    raw_V[N - 2] = S;
    raw_V[N - 1] = T;
    for (int i = 0; i < N - 2 ; i++)
    {
        scanf("%d%d", &raw_V[i].fi, &raw_V[i].se);
        int sz;
        scanf("%d", &sz);
        for (int j = 0; j < sz; j++)
        {
            int v, t;
            scanf("%d%d", &v, &t);
            --t;
            raw_adj[i].pb({v, vet_T[t]});
        }
        raw_adj[i].pb({N - 2, C0});
        raw_adj[i].pb({N - 1, C0});
    }

    raw_adj[N - 2].pb({N - 1, C0});

    create_graph();


    ll res = solve(map_id[S], B);
    if (res == INF)
        printf("-1\n");
    else
        printf("%d\n", res);
    

}