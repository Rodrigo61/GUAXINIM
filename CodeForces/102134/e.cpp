#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345
#define INF 1123456789
#define db(x) //cout << #x << " = " << x << endl;
#define pii pair<int, int>

#define LEFT_NODE(i) i+i+1
#define RIGHT_NODE(i) i+i+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) {seg.first, MID(seg)}
#define RIGHT_SEG(seg) {MID(seg) + 1, seg.second}

vector<int> adj[MAXN];
int N, Q;
vector<int> queries[MAXN];
int node_value[MAXN];
int freq[MAXN];
int vis[MAXN];
map<pii, int> queries_ans;
vector<pii> output_order;

int segtree[MAXN*4];

void build(pii curr_seg, int node){

	if(curr_seg.first == curr_seg.second){
		segtree[node] = freq[curr_seg.first];
		return;
	}

	build(LEFT_SEG(curr_seg), LEFT_NODE(node));
	build(RIGHT_SEG(curr_seg), RIGHT_NODE(node));

	segtree[node] = segtree[LEFT_NODE(node)] + segtree[RIGHT_NODE(node)];
}

void update_aux(pii curr_seg, int index, int value, int node){

	if (curr_seg.first == curr_seg.second) {
		segtree[node] = value;
		return;
	}

	if (index <= MID(curr_seg)) {
		update_aux(LEFT_SEG(curr_seg), index, value, LEFT_NODE(node));
	} else {
		update_aux(RIGHT_SEG(curr_seg), index, value, RIGHT_NODE(node));
	}

	segtree[node] = segtree[LEFT_NODE(node)] + segtree[RIGHT_NODE(node)];
}

int query_aux(pii curr_seg, int node, int k)
{
	if (curr_seg.first == curr_seg.second)
	{
		return curr_seg.first;
	}
	
	if (segtree[LEFT_NODE(node)] >= k)
	{
		return query_aux(LEFT_SEG(curr_seg), LEFT_NODE(node), k);
	}
	
	return query_aux(RIGHT_SEG(curr_seg), RIGHT_NODE(node), k - segtree[LEFT_NODE(node)]);
}

int k_smallest(int k){
	return query_aux({1, N}, 0, k);
}

void init_seg()
{
	build({1, N}, 0);
}

void update(int index, int value) {
	update_aux({1, N}, index, value, 0);
}


int dfs(int u)
{
	node_value[u] = 1;
	for (auto v : adj[u])
	{
		if (node_value[v] == 0)
		{
			node_value[u] += dfs(v);
		}
	}

	freq[node_value[u]]++;
	return node_value[u];
}

void change(int p, int u)
{
	freq[node_value[p]]--;
	freq[node_value[u]]--;
	update(node_value[p], freq[node_value[p]]);
	update(node_value[u], freq[node_value[u]]);
	
	node_value[p] -= node_value[u];
	node_value[u] += node_value[p];
	
	freq[node_value[p]]++;
	freq[node_value[u]]++;
	update(node_value[p], freq[node_value[p]]);
	update(node_value[u], freq[node_value[u]]);
	
}

void dfs2(int u)
{
	vis[u] = 1;
	
	for (int k : queries[u])
		queries_ans[{u, k}] = k_smallest(k);
		
	for (int v : adj[u])
	{
		if (!vis[v])
		{
			change(u, v);
			dfs2(v);
			change(v, u);
		}
	}
}

int main()
{
	scanf("%d%d", &N, &Q);
	
	int u,v;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int k;
	for (int i = 0; i < Q; i++)
	{
		scanf("%d%d", &u, &k);
		queries[u].push_back(k);
		output_order.push_back({u, k});
	}
	dfs(1);
	init_seg();
	dfs2(1);
	
	for (auto p : output_order)
	{
		printf("%d\n", queries_ans[p]);
	}
	
	return 0;
}
