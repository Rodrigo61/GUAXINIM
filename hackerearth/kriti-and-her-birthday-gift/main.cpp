#include "bits/stdc++.h"

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

#define MAXN 100001
#define sz(x) x.size()

struct query {
	int l, r, id, v;
};

int vals[MAXN];
int n;
int freq[MAXN];
vector<query> vet_q;
int ans[MAXN];

void add(int p)
{
    ll v = vals[p];
    freq[v]++;
}

void remove(int p)
{
    ll v = vals[p];
    freq[v]--;
}

void output(int id)
{
    if (vet_q[id].v != -1)
        ans[id] = freq[vet_q[id].v];
    else
        ans[id] = 0;
}

template<class F>
void mos(int n, vector<query> q, const F &add, const F &remove, const F &output)
{
	int bsize = 1 + n / sqrt(sz(q));
	sort(q.begin(), q.end(), [&](const query &lhs, const query &rhs) {
		if (lhs.l / bsize != rhs.l / bsize)
			return  (lhs.l / bsize < rhs.l / bsize);
		return lhs.r < rhs.r;
	});

	int l = 1, r = 0; // int l = 0, r = -1; (if indices starts at 0)
	for (int i = 0; i < sz(q); i++)
	{
		while (l > q[i].l)
			add(--l);
		while (r < q[i].r)
			add(++r);
		while (l < q[i].l)
			remove(l++);
		while (r > q[i].r)
			remove(r--);

		output(q[i].id);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int id = 0;
    map<string, int> s2i;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s2i.find(s) == s2i.end())
            s2i[s] = id++;
        vals[i] = s2i[s];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int l, r;
        string s;
        cin >> l >> r >> s;
        --l, --r;
        if (s2i.find(s) == s2i.end())
            vet_q.pb({l, r, i, -1});
        else
            vet_q.pb({l, r, i, s2i[s]});
    }

    mos(n, vet_q, add, remove, output);

    for (int i = 0; i < q; i++)
    {
        printf("%d\n", ans[i]);
    }
    
}