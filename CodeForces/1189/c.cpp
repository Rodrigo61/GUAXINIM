#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define LEFT(x) x+x+1
#define RIGHT(x) x+x+2
#define MAXN 112345

int N;
vi vals;
int tree_val[MAXN * 4], tree_cand[MAXN * 4];
int ans;

void build(int l, int r, int node)
{
	if (l == r)
	{
		tree_val[node] = vals[l];
		return;
	}
	
	int mid = (l + r) / 2;
	build(l, mid, LEFT(node));
	build(mid + 1, r, RIGHT(node));
	tree_val[node] = (tree_val[LEFT(node)] + tree_val[RIGHT(node)]);
	int aux = int(tree_val[node] >= 10);
	tree_cand[node] = tree_cand[LEFT(node)] + tree_cand[RIGHT(node)] + aux;
	tree_val[node] = (tree_val[LEFT(node)] + tree_val[RIGHT(node)]) % 10;
}

int query(int tl, int tr, int l, int r, int node)
{
	db(l);
	db(r);
	if (r < tl || l > tr)
	{
		return 0;
	}
	
	if (l >= tl && r <= tr)
	{
		ans += tree_cand[node];
		return tree_val[node];
	}
	
	int mid = (l + r) / 2;
	int res = (query(tl, tr, l, mid, LEFT(node)) + query(tl, tr, mid + 1, r, RIGHT(node)));
	
	if (res >= 10)
	{
		++ans;
	}
	
	return res % 10;
		
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int v;
		scanf("%d", &v);
		vals.pb(v);
	}
	
	build(0, N - 1, 0);
		
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		db(i);
		int l, r;
		ans = 0;
		scanf("%d%d", &l, &r);
		--l, --r;
		query(l, r, 0, N - 1, 0);
		printf("%d\n", ans);
	}
	
}
