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
 
#define MAXA 1123456
#define MAXN 212345
#define sz(x) x.size()
 
constexpr int logn = 20;
constexpr int maxn = 1 << logn;
ll hilbertorder(int x, int y)
{
	ll d = 0;
	for (int s = 1 << (logn - 1); s; s >>= 1)
	{
		bool rx = x & s, ry = y & s;
		d = d << 2 | rx * 3 ^ static_cast<int>(ry);
		if (!ry)
		{
			if (rx)
			{
				x = maxn - x;
				y = maxn - y;
			}
			swap(x, y);
		}
	}
	return d;
}
 
struct query {
	int l, r, id;
    ll ord() const
    {
        return hilbertorder(l, r);
    }
};
 
ll freq[MAXA];
ll curr_sum = 0;
ll vals[MAXN];
ll ans[MAXN];
 
ll add(int p)
{
    ll v = vals[p];
    curr_sum -= v * freq[v] * freq[v];
    freq[v]++;
    curr_sum += v * freq[v] * freq[v];
    return 0;
}
 
ll rem(int p)
{
    ll v = vals[p];
    curr_sum -= v * freq[v] * freq[v];
    freq[v]--;
    curr_sum += v * freq[v] * freq[v];
    return 0;
}
 
ll output(int id)
{
    return ans[id] = curr_sum;
}
 
template<class F>
void mos(int n, vector<query> q, const F &add, const F &remove, const F &output)
{
	int bsize = 1 + n / sqrt(sz(q));
	sort(q.begin(), q.end(), [&](const query &lhs, const query &rhs) {
        return lhs.ord() < rhs.ord();
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
    int n, q;
    scanf("%d%d", &n, &q);
 
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &vals[i]);
    }
 
    vector<query> vet_q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        vet_q.pb({l, r, i});
    }
    
    mos(n, vet_q, add, rem, output);
 
    for (int i = 0; i < q; i++)
    {
        printf("%lld\n", ans[i]);
    }
}