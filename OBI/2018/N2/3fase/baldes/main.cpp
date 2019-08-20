#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

#define LEFT(x) x+x+1
#define RIGHT(x) x+x+2
#define MAXN 112345
 
int N, Q;
pii min_tree[4*MAXN], max_tree[4*MAXN];
int start[MAXN];

void build(int node, int l, int r)
{
	if (l == r)
	{
		max_tree[node] = {start[l], l};
		min_tree[node] = {start[l], l};
		return;
	}
	
	int mid = (l + r) / 2;
	build(LEFT(node), l, mid);
	build(RIGHT(node), mid + 1, r);
	max_tree[node] = max(max_tree[LEFT(node)], max_tree[RIGHT(node)]);
	min_tree[node] = min(min_tree[LEFT(node)], min_tree[RIGHT(node)]);
}

void update_max(int node, int l, int r, int pos, int val)
{
	if (l == r)
	{
		max_tree[node] = max(max_tree[node], {val, pos});
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid)
	{
		update_max(LEFT(node), l, mid, pos, val);
	}
	else
	{
		update_max(RIGHT(node), mid + 1, r, pos, val);
	}
	max_tree[node] = max(max_tree[LEFT(node)], max_tree[RIGHT(node)]);
}

void update_min(int node, int l, int r, int pos, int val)
{
	if (l == r)
	{
		min_tree[node] = min(min_tree[node], {val, pos});
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid)
	{
		update_min(LEFT(node), l, mid, pos, val);
	}
	else
	{
		update_min(RIGHT(node), mid + 1, r, pos, val);
	}
	min_tree[node] = min(min_tree[LEFT(node)], min_tree[RIGHT(node)]);
}

pii query_max(int node, int l, int r, int tl, int tr)
{
	if (r < tl || l > tr)
	{
		return {-1, -1};
	}
	
	if (l >= tl && r <= tr)
	{
		return max_tree[node];
	}
	
	int mid = (l + r ) / 2;
	
	return max(query_max(LEFT(node), l, mid, tl, tr),
			   query_max(RIGHT(node), mid + 1, r, tl, tr));
}

pii query_min(int node, int l, int r, int tl, int tr)
{
	if (r < tl || l > tr)
	{
		return {INF, INF};
	}
	
	if (l >= tl && r <= tr)
	{
		return min_tree[node];
	}
	
	int mid = (l + r ) / 2;
	
	return min(query_min(LEFT(node), l, mid, tl, tr),
			   query_min(RIGHT(node), mid + 1, r, tl, tr));
}
 
int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &start[i]);
	}
	build(0, 0, N - 1);
	
	for (int i = 0; i < Q; i++)
	{
		int cmd, a, b;
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == 1)
		{
			--b;
			update_max(0, 0, N - 1, b, a);
			update_min(0, 0, N - 1, b, a);
		}
		else
		{
			--a, --b;
			//min
			pii mini = query_min(0, 0, N - 1, a, b);
			pii maxi = max(query_max(0, 0, N - 1, a, mini.se - 1), query_max(0, 0, N - 1, mini.se + 1, b));
			int res = maxi.fi - mini.fi;
			//max
			maxi = query_max(0, 0, N - 1, a, b);
			mini = min(query_min(0, 0, N - 1, a, maxi.se - 1), query_min(0, 0, N - 1, maxi.se + 1, b));
			res = max(res, maxi.fi - mini.fi);
			
			printf("%d\n", res);
		}
	}
	
	
}
