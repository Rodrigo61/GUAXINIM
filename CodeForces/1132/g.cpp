#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define LEFT(x) x+x+1
#define RIGHT(x) x+x+2
#define pii pair<int, int>

#define MAXN 1123456

int N, K;
int vals[MAXN];
vi adj[MAXN];
int timestamp;
int Tin[MAXN], Tout[MAXN];
int stree[4*MAXN];
int lazy_tree[4*MAXN];

void ETT(int u)
{
	Tin[u] = timestamp;
	for (int v : adj[u])
		ETT(v);
	Tout[u] = timestamp++;
}

void generate_tree()
{
	stack<pii> gt_stack;
	for (int i = N; i >= 1; i--)
	{
		while (!gt_stack.empty() && gt_stack.top().fi <= vals[i])
		{
			gt_stack.pop();
		}
		
		if(gt_stack.empty())
		{
			adj[0].pb(i);
		}
		else
		{
			adj[gt_stack.top().se].pb(i);
		}
		
		gt_stack.push({vals[i], i});
	}
	
	ETT(0);
}

void lazy_update(int node, int l, int r){

	stree[node] += lazy_tree[node];
	if(l != r){
		/* Propagate, not a leaf */
		lazy_tree[LEFT(node)] += lazy_tree[node];
		lazy_tree[RIGHT(node)] += lazy_tree[node];
	}
	lazy_tree[node] = 0;
}

void update(int node, int l, int r, int tl, int tr, int offset)
{
	lazy_update(node, l, r);

	if (l > tr || r < tl)
	{
		return;
	}
	
	if (l >= tl && r <= tr)
	{
		lazy_tree[node] += offset;
		lazy_update(node, l, r);
		return;
	}
	
	int mid = (l + r) / 2;
	update(LEFT(node), l, mid, tl, tr, offset);
	update(RIGHT(node), mid + 1, r, tl, tr, offset);
	stree[node] = max(stree[LEFT(node)], stree[RIGHT(node)]);
}

int query(int node, int l, int r, int tl, int tr)
{
	lazy_update(node, l, r);
	
	if (l > tr || r < tl)
	{
		return 0;
	}
	
	if (l >= tl && r <= tr)
	{
		return stree[node];
	}
	
	int mid = (l + r) / 2;
	return query(LEFT(node), l, mid, tl, tr) + 
	       query(RIGHT(node), mid + 1, r, tl, tr);
	
}

void enable(int u)
{
	update(0, 0, N, Tin[u], Tout[u], 1);
}

void disable(int u)
{
	update(0, 0, N, Tin[u], Tout[u], -1);
}

void print_seg()
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", query(0, 0, N, i, i));
	}
	printf("\n");
	
}
 
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	generate_tree();
	
	for (int i = 1; i <= N; i++)
	{
		enable(i);
		//~ print_seg();
		if (i >= K)
		{
			printf("%d\n", query(0, 0, N - 1, 0, N - 1));
			disable(i - K + 1);
		}
	}
	
}
