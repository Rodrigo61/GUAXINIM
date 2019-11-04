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

#define sz(x) (int)x.size()

char aux[1123];


namespace euler
{

#define MAXN 30
#define MAXM 112345

struct edge
{
    int u, v, id;
};

struct vertice
{
    vi outs;           // edges indexes
    int in_degree = 0; // not used with undirected graphs
};

int n, m;
edge edges[MAXM];
vertice vertices[MAXN];
vi::iterator its[MAXN];
bool used_edge[MAXM];

void init()
{
    for (int i = 0; i < n; i++)
    {
        its[i] = vertices[i].outs.begin();
    }
}

vi euler_tour(int n_edges, int src)
{
    vi ret_vertices;
    vector<pii> s = {{src, -1}};
    while (!s.empty())
    {
        int x = s.back().first;
        auto &it = its[x], end = vertices[x].outs.end();

        while (it != end && used_edge[*it])
            ++it;

        if (it == end)
        {
            ret_vertices.push_back(x);
            s.pop_back();
        }
        else
        {
            auto edge = edges[*it];
            int v = edge.u == x ? edge.v : edge.u;
            s.push_back({v, *it});
            used_edge[*it] = true;
        }
    }
    if (sz(ret_vertices) != n_edges + 1)
        ret_vertices.clear(); // No Eulerian cycles/paths.

    reverse(all(ret_vertices));
    return ret_vertices;
}

} // namespace euler


void reset()
{
    for (int i = 0; i < euler::n; i++)
    {
        euler::vertices[i].outs.clear();
        euler::vertices[i].in_degree = 0;
    }
    for (int i = 0; i < euler::m; i++)
    {
        euler::used_edge[i] = false;
    }
    
}

int find_src()
{
	int src = 0;
	for (int i = 0; i < euler::n; i++)
	{
		if ((int)sz(euler::vertices[i].outs) > euler::vertices[i].in_degree)
		{
			src = i;
			break;
		}
		if (euler::vertices[i].in_degree)
			src = i;
	}
 
	return src;
}

bool check_condition()
{
	int c = 0;
	for (int i = 0; i < euler::n; ++i)
	    c += abs(euler::vertices[i].in_degree - sz(euler::vertices[i].outs));
	return c <= 2;
}

int main()
{
    int t;
    scanf("%d", &t);
    euler::n = 26;
    while (t--)
    {
        scanf("%d", &euler::m);
        for (int i = 0; i < euler::m; i++)
        {
            scanf("%s", aux);
            string str = aux;
            int u = str[0] - 'a';
            int v = str.back() - 'a';
            euler::edges[i] = {u, v, i};
            euler::vertices[u].outs.pb(i);
            euler::vertices[v].in_degree++;
        }

        euler::init();

        if (!check_condition() || euler::euler_tour(euler::m, find_src()).empty())
        {
            printf("The door cannot be opened.\n");
        }
        else
        {
            printf("Ordering is possible.\n");
        }
        
        reset();
    }
    
}