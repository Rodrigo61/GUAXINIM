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

vii white_edges;
vi adj[MAXN];
int color[MAXN];
int curr_color = 1;
bool bip = true;
int n, m;

struct TwoSat {
vi val, comp, z; int time = 0;
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

    void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}

    void set_value(int x) { either(x, x); }

    int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(auto &e: gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		for (int i = 0; i < 2 * N; ++i) if (!comp[i]) dfs(i);
		for (int i = 0; i < N; ++i) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (color[v] == 0)
        {
            color[v] = color[u] == curr_color ? curr_color + 1: curr_color;
            dfs(v);
        }
        else if (color[v] == color[u])
        {
            bip = false;
            return;
        }
    }
}

void restart()
{
    white_edges.clear();
    bip = true;
    curr_color = 1;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        color[i] = 0;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);

            if (w)
                adj[u].pb(v), adj[v].pb(u);
            else
                white_edges.pb({u, v});
        }

        for (int i = 1; i <= n; i++)
        {
            if (!color[i])
            {
                color[i] = curr_color;
                dfs(i);
                curr_color += 2;             

                if (!bip)
                    break;
            }
        }

        if (!bip)
            printf("NO\n");
        else
        {
            TwoSat tsat(curr_color - 1);
            for (pii edge : white_edges)
            {
                int u = edge.fi;
                int v = edge.se;
                if (color[u] != 0 && color[v] != 0)
                {
                    if (color[u] == color[v])
                    {
                        tsat.set_value(color[u] - 1);
                    }
                    else
                    {
                        tsat.either(color[u] - 1, color[v] - 1);
                    }
                }
            }

            for (int i = 1; i < curr_color; i += 2)
            {
                tsat.either(i - 1, i);
                tsat.either(~(i - 1), ~i);
            }

            if (!bip || !tsat.solve())
                printf("NO\n");
            else
                printf("YES\n");
        }

        restart();
    }
    
}