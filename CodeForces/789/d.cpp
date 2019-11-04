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

#define MAXN 1123456

vi adj[MAXN];
int degree[MAXN];
int cnt = 0;
int vis[MAXN];

void dfs(int u)
{
    vis[u] = 1;
    cnt++;

    for (auto v : adj[u])
        if (!vis[v])
            dfs(v);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
        degree[u]++;
        degree[v]++;
    }

    dfs(1);

    if (cnt != n)
    {
        printf("0\n");
    }
    else
    {
        ll even_cnt = 0;
        ll odd_cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (degree[i] & 1)
                odd_cnt++;
            else
                even_cnt++;
        }

        for (int i = 0; i <= n; i++)
        {
            /* code */
        }
        

        if (even_cnt < 2)
            printf("0\n");
        else
            printf("%lld\n", (even_cnt*(even_cnt - 1))/2);
    }
    
}