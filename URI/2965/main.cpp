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
#define LN(x) x+x+1
#define RN(x) x+x+2

int n, k;
vi adj[MAXN];
int best_child[MAXN];
pii tree[4 * MAXN];

void update(int node, int l, int r, int pos, int val)
{
	if (l == r)
	{
		tree[node] = {val, pos};
		return;
	}
	
	int mid = (l + r) / 2;
	if (pos <= mid) update(LN(node), l, mid, pos, val);
	else update(RN(node), mid + 1, r, pos, val);
	
	tree[node] = max(tree[LN(node)], tree[RN(node)]);
}

int dfs(int u)
{
	if (adj[u].empty())
	{
		update(0, 0, n - 1, u, 1);
		return 1;
	} 
	
	int best = 0;
	
	for (int i = 0; i < (int)adj[u].size(); ++i)
	{
		int rec = dfs(adj[u][i]);
		if (rec > best)
		{
			best = rec;
			best_child[u] = i;
		}
	}
			
	update(0, 0, n - 1, u, best + 1);
	return best + 1;
}

void dfs2(int u)
{
	update(0, 0, n - 1, u, 0);
	if (!adj[u].empty())
		dfs2(adj[u][best_child[u]]);
}

pii query(int node, int l, int r, int pos)
{
	if (l == r)
	{
		return tree[node];
	}
	
	int mid = (l + r) / 2;
	if (pos <= mid) return query(LN(node), l, mid, pos);
	else return query(RN(node), mid + 1, r, pos);
}

void print_seg()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", query(0, 0, n - 1, i).fi);
	}
	printf("\n");
}

void print_best()
{
	for (int i = 0; i < n; i++)
	{
		if (adj[i].empty())
			printf("- ");
		else
			printf("%d ", adj[i][best_child[i]]);
	}
	printf("\n");
	
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - 1; i++)
	{
		int u;
		scanf("%d", &u);
		--u;
		adj[u].pb(i + 1);
	}
	
	dfs(0);
	
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		//~ print_seg();
		//~ print_best();
		pii maxi = tree[0];
		res += maxi.fi;
		dfs2(maxi.se);
	}
	
	printf("%d\n", res);
	
}
