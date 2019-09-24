#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long

#define MAXN 112345
#define LEFT_NODE(x) x+x+1
#define RIGHT_NODE(x) x+x+2

int n;
ll point_val_bit[MAXN];
ll point[MAXN];
ll BIT[MAXN];
int BIT_DEADS[MAXN];
ll seg3[4*MAXN];
ll lazy[4*MAXN];
ll a_vals[MAXN], b_vals[MAXN];
vi died;

void update_dead(int pos, int kill)
{
	++pos;
	int aux = pos;
	if (point[aux] == kill)
	{
		string text = "Kill = " + to_string(kill);
		db(text);
		printf("%s\n", text.c_str());
		assert(text == "");
	}
	assert(point[aux] != kill);
	int val = kill ? 1:-1;
	while (pos <= n)
	{
		BIT_DEADS[pos] += val;
		pos += pos & -pos;
	}
	point[aux] = kill;
}

int deads(int pos)
{
	++pos;
	int res = 0;
	while (pos > 0)
	{
		res += BIT_DEADS[pos];
		pos -= pos & -pos;
	}
	return res;
}


void update_bit(int pos, ll new_val)
{
	int aux = pos;
	++pos;
	while (pos <= n)
	{
		BIT[pos] -= point_val_bit[aux];
		BIT[pos] += new_val;
		pos += pos & -pos;
	}
	point_val_bit[aux] = new_val;
}

ll prefix(int pos)
{
	++pos;
	ll res = 0;
	while (pos > 0)
	{
		res += BIT[pos];
		pos -= pos & -pos;
	}
	
	return res;
}

void lazy_upd(int node, int l, int r)
{
	if(lazy[node] != 0){
		if (seg3[node] != INF)
			seg3[node] += lazy[node];

		if(l != r){
			lazy[LEFT_NODE(node)] += lazy[node];
			lazy[RIGHT_NODE(node)] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void update_seg(int node, int l, int r, int tl, int tr, ll val, int point_updt)
{
	lazy_upd(node, l, r);

	if (l > tr || r < tl)
		return;
	
	if (l >= tl && r <= tr)
	{
		if (point_updt)
		{
			lazy[node] = 0;
			seg3[node] = val;
		}
		else
		{
			lazy[node] += val;
			lazy_upd(node, l, r);
		}
		return;
	}
	
	int mid = (l + r) / 2;
	update_seg(LEFT_NODE(node), l, mid, tl, tr, val, point_updt);
	update_seg(RIGHT_NODE(node), mid + 1, r, tl, tr, val, point_updt);
	
	seg3[node] = min(seg3[LEFT_NODE(node)], seg3[RIGHT_NODE(node)]);
}

int low_b(ll target)
{
	int up = n - 1;
	int lo = 0;
	int best = -1;
	
	while (lo <= up)
	{
		int mid = lo + (up - lo)/2;
		if (prefix(mid) <= target)
		{
			best = mid;
			lo = mid + 1;
		}
		else
		{
			up = mid - 1;
		}
	}
	
	return best;
}

ll query_min(int node, int l, int r, int tl, int tr)
{
	if (l > tr || r < tl)
		return INF;
		
	lazy_upd(node, l, r);
	
	if (l >= tl && r <= tr)
		return seg3[node];
	
	int mid = (l + r) / 2;
	return min(query_min(LEFT_NODE(node), l, mid, tl, tr),
			   query_min(RIGHT_NODE(node), mid + 1, r, tl, tr));
}

void query(int node, int l, int r, int tl, int tr, ll target)
{
	if (l > tr || r < tl)
		return;
		
	if (query_min(0, 0, n - 1, l, r) >= target)
		return;
		
	if (l == r)
	{
		died.pb(l);
		return;
	}
	
	int mid = (l + r) / 2;
	query(LEFT_NODE(node), l, mid, tl, tr, target);
	query(RIGHT_NODE(node), mid + 1, r, tl, tr, target);
}

void print_prefix()
{
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ printf("%d ", prefix(i));
	//~ }
	//~ printf("\n");
}

void print_seg()
{
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ int aux = query_min(0, 0, n-1, i, i);
		//~ if (aux == INF)
			//~ printf("I ");
		//~ else
			//~ printf("%d ", aux);
	//~ }
	//~ printf("\n");
	
}


signed main()
{
	db(INF);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		update_bit(i, a);
		b_vals[i] = b;
		a_vals[i] = a;
	}
	
	for (int i = 0; i < n; ++i)
	{
		update_seg(0, 0, n - 1, i, i, b_vals[i] + prefix(i), 1);
	}
	
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		print_prefix();
		print_seg();
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			ll x;
			scanf("%lld", &x);
			
			int pos = low_b(x);
			int a = n - (pos + 1) - (deads(n - 1) - deads(pos));
			
			died.clear();
			query(0, 0, n-1, 0, pos, x);
			
			for (auto d : died)
			{
				update_dead(d, 1);
				update_seg(0, 0, n - 1, d, d, INF, 1);
				update_seg(0, 0, n - 1, d + 1, n - 1, -a_vals[d], 0);
				update_bit(d, 0);
			}
			
			printf("%d %d\n", (int)died.size(), a);
		}
		else
		{
			ll a, b, c;
			scanf("%lld%lld%lld", &a, &b, &c);
			--c;
			
			update_bit(c, a);

			if (query_min(0, 0, n-1, c, c) != INF)
			{
				update_seg(0, 0, n - 1, c + 1, n - 1, -a_vals[c], 0);
				print_seg();
			}
			else
			{
				update_dead(c, 0);
			}
			
			update_seg(0, 0, n - 1, c, c, b + prefix(c), 1);
			print_seg();
			update_seg(0, 0, n - 1, c + 1, n - 1, a, 0);
			print_seg();
			
			a_vals[c] = a;
			b_vals[c] = b;
		}
	}
	
	
}
