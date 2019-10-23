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
#define sz(x) x.size()
typedef long double ld;

#define MAXN 41234
#define MAXQ 112345

int n, q;
ll vals[MAXN];
vi adj[MAXN];
int ans[MAXQ];
int t;
int curr;
int freq[MAXN];

struct query
{
    int l, r, id, lc;
};

void add(int p)
{
    if (freq[vals[p]] == 0)
        ++curr;
    freq[vals[p]]++;
}

void remove(int p)
{
    freq[vals[p]]--;
    if (freq[vals[p]] == 0)
        --curr;
}

void output(int id)
{
    ans[id] = curr;
}

struct lca_preprocess
{
	int lgn;
	vector<int> h;
	vector<vector<int>> p;
	vector<int> *graph;

	void dfs(int a)
	{
		for (int i = 0; i < (int)sz(graph[a]); i++)
			if (graph[a][i] != p[0][a])
			{
				h[graph[a][i]] = h[a] + 1;
				p[0][graph[a][i]] = a;
				dfs(graph[a][i]);
			}
	}

	lca_preprocess(int root, int n, vector<int> graph[]) : h(n + 1), graph(graph)
	{
		lgn = 31 - __builtin_clz(n + 1);
		p.assign(lgn + 1, vector<int>(n + 1, 0));

		p[0][root] = root;
		h[root] = 0;
		dfs(root);

		for (int i = 1; i <= lgn; i++)
			for (int j = 0; j <= n; j++)
				p[i][j] = p[i - 1][p[i - 1][j]];
	}

	int lca(int a, int b)
	{
		if (h[a] < h[b])
			swap(a, b);
		for (int i = lgn; i >= 0; i--)
			if (h[p[i][a]] >= h[b])
				a = p[i][a];

		if (a == b)
			return a;

		for (int i = lgn; i >= 0; i--)
			if (p[i][a] != p[i][b])
			{
				a = p[i][a];
				b = p[i][b];
			}

		return p[0][a];
	}
};

template <class F>
void mos_tree(int root, int n, vector<pii> pq, vector<int> graph[], const F &add, const F &remove, const F &output)
{
	int a, b;
	lca_preprocess lca(root, n, graph);

	vector<int> st(n + 1, 0), en(n + 1, 0), v(2 * n + 3, 0), cnt(n + 1, 0), s;
	int id = 0;
	s.push_back(root);
	while (!s.empty()) // dfs pre-pos ordering.
	{
		a = s.back();
		s.pop_back();

		if (st[a])
			v[en[a] = ++id] = a;
		else
		{
			v[st[a] = ++id] = a;
			s.push_back(a);
			for (int i = 0; i < sz(graph[a]); i++)
				if (graph[a][i] != lca.p[0][a])
					s.push_back(graph[a][i]);
		}
	}

	vector<query> q;

	for (int i = 0; i < sz(pq); i++)
	{
		tie(a, b) = pq[i];

		if (st[a] > st[b])
			swap(a, b);
		int y = lca.lca(a, b);
		if (a == y)
			q.push_back({st[a], st[b], i, -1});
		else
			q.push_back({en[a], st[b], i, st[y]}); 
			// For queries of this type, the lca must be separately added.
	}

	int bsize = 1 + (2 * n) / sqrt(sz(q));
	sort(q.begin(), q.end(), [&](const query &lhs, const query &rhs) {
        if (lhs.l / bsize != rhs.l / bsize) 
            return lhs.l < rhs.l;
        if ((lhs.l / bsize) & 1)
            return (lhs.r > rhs.r);     
        return (lhs.r < rhs.r);    
	});
	// Vertices inserted twice are removed.
	auto consider = [&](int i) {
		cnt[v[i]]++;
		if (cnt[v[i]] % 2 == 1)
			add(v[i]);
		else
			remove(v[i]);
	};

	int l = 0, r = -1;
	for (int i = 0; i < sz(q); i++)
	{
		while (l > q[i].l)
			consider(--l);
		while (r < q[i].r)
			consider(++r);
		while (l < q[i].l)
			consider(l++);
		while (r > q[i].r)
			consider(r--);

		if (q[i].lc != -1)
			consider(q[i].lc);

		output(q[i].id);

		if (q[i].lc != -1)
			consider(q[i].lc);
	}
}

int main()
{
    scanf("%d%d", &n, &q);

    set<ll> used;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &vals[i]);
        used.insert(vals[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    map<ll, int> compressed;
    int id = 0;
    for (ll i : used)
        compressed[i] = id++;

    for (int i = 0; i < n; i++)
    {
        vals[i] = compressed[vals[i]];
    }

    vii vet_q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        vet_q.pb({u, v});
    }

    mos_tree(0, n, vet_q, adj, add, remove, output);
    
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", ans[i]);
    }
}