#include<bits/stdc++.h>
#define MAXN 200001
#define INF 1001001001
using namespace std;

pair<int, int> tree[4*MAXN];
pair<int, int> A[MAXN];

pair<int, int> op(pair<int, int> a, pair<int, int> b)
{
	return {max(a.first, b.first), min(a.second, b.second)};
}

void build(int node, int start, int end)
{
	if(start == end)
		tree[node] = A[start];
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = op(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, pair<int, int> p)
{
	if(start == end)
		tree[node] = p;
	else
	{
		int mid = (start+end)/2;
		if(start <= idx && idx <= mid)
			update(2*node, start, mid, idx, p);
		else
			update(2*node+1, mid+1, end, idx, p);
		tree[node] = op(tree[2*node], tree[2*node+1]);
	}
}

pair<int, int> query(int node, int start, int end, int l, int r)
{
	if(r < start || end < l)
		return {-INF, INF};
	if(l <= start && end <= r)
		return tree[node];
	int mid = (start+end)/2;
	return op(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
}

int main()
{
	int N, Q, x, y, z;
	pair<int, int> p;
	char sel;
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; i++)
		scanf("%d %d%*c", &A[i].first, &A[i].second);
	build(1, 1, N);
	while(Q--)
	{
		scanf("%c", &sel);
		if(sel == '?')
		{
			scanf("%d %d%*c", &x, &y);
			p = query(1, 1, N, x, y);
			//printf("%d %d\n", p.first, p.second);
			if(p.second >= p.first)
				printf("%d\n", p.second-p.first+1);
			else
				printf("0\n");
		}
		else
		{
			scanf("%d %d %d%*c", &x, &y, &z);
			update(1, 1, N, x, {y, z});
		}
	}
	return 0;
}
