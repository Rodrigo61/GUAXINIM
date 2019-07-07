#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl
#define vi vector<int>
#define pb push_back
#define INF 0x3f3f3f3f
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()

#define MAXN 112345
#define RIGHT(X) X+X+1
#define LEFT(X) X+X+2

int N, Q;
ll sum_tree[4*MAXN], min_tree[4*MAXN], max_tree[4*MAXN];

void update(int pos, ll val, int l, int r, int node)
{
	if (l == r)
	{
		sum_tree[node] = min_tree[node] = max_tree[node] = val;
		return;
	}
	
	int mid = (l + r) / 2;
	
	if (pos <= mid)
	{
		update(pos, val, l, mid, LEFT(node));
	}
	else
	{
		update(pos, val, mid + 1, r, RIGHT(node));
	}
	
	sum_tree[node] = sum_tree[LEFT(node)] + sum_tree[RIGHT(node)];
	max_tree[node] = max(max_tree[LEFT(node)], max_tree[RIGHT(node)]);
	min_tree[node] = min(min_tree[LEFT(node)], min_tree[RIGHT(node)]);
}

ll sum(int tl, int tr, int l, int r, int node)
{
	if (r < tl || l > tr)
	{
		return 0;
	}
	
	if (l >= tl && r <= tr)
	{
		return sum_tree[node];
	}
	
	int mid = (l + r) / 2;
	return sum(tl, tr, l, mid, LEFT(node)) +
		   sum(tl, tr, mid + 1, r, RIGHT(node));
}

ll maxi(int tl, int tr, int l, int r, int node)
{
	if (r < tl || l > tr)
	{
		return 0;
	}
	
	if (l >= tl && r <= tr)
	{
		return max_tree[node];
	}
	
	int mid = (l + r) / 2;
	return max(maxi(tl, tr, l, mid, LEFT(node)),
		       maxi(tl, tr, mid + 1, r, RIGHT(node)));
}

ll mini(int tl, int tr, int l, int r, int node)
{
	if (r < tl || l > tr)
	{
		return 11;
	}
	
	if (l >= tl && r <= tr)
	{
		return min_tree[node];
	}
	
	int mid = (l + r) / 2;
	return min(mini(tl, tr, l, mid, LEFT(node)),
		       mini(tl, tr, mid + 1, r, RIGHT(node)));
}

int main ()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; i++)
	{
		ll v;
		scanf("%lld", &v);
		update(i, v, 0, N - 1, 0);
	}
	
	for (int i = 0; i < Q; i++)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			--l, --r;
			printf("%lld\n", sum(l, r, 0, N - 1, 0) - maxi(l, r, 0, N - 1, 0) - mini(l, r, 0, N - 1, 0));
		}
		else
		{
			ll p, v;
			scanf("%lld%lld", &p, &v);
			--p;
			update(p, v, 0, N - 1, 0);
		}
	}
	
	
}
