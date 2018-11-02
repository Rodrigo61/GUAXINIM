#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;

int N, Q;
int A[MAXN];
int tree[4*MAXN];
int tree2[4*MAXN];

void build(int node, int start, int end)
{
	if(start == end)
		tree[node] = abs(A[start]-A[start+1]);
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}

void build2(int node, int start, int end)
{
	if(start == end)
		tree2[node] = abs(A[start]-A[start-1]);
	else
	{
		int mid = (start+end)/2;
		build2(2*node, start, mid);
		build2(2*node+1, mid+1, end);
		tree2[node] = max(tree2[2*node], tree2[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, int val)
{
	if(start == end)
		tree[node] = val;
	else
	{
		int mid = (start+end)/2;
		if(start <= idx && idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}

void update2(int node, int start, int end, int idx, int val)
{
	if(start == end)
		tree2[node] = val;
	else
	{
		int mid = (start+end)/2;
		if(start <= idx && idx <= mid)
			update2(2*node, start, mid, idx, val);
		else
			update2(2*node+1, mid+1, end, idx, val);
		tree2[node] = max(tree2[2*node], tree2[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r)
{
	if(r < start || end < l)
		return 0;
	if(l <= start && end <= r)
		return tree[node];
	int mid = (start+end)/2;
	return max(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
}

int query2(int node, int start, int end, int l, int r)
{
	if(r < start || end < l)
		return 0;
	if(l <= start && end <= r)
		return tree2[node];
	int mid = (start+end)/2;
	return max(query2(2*node, start, mid, l, r), query2(2*node+1, mid+1, end, l, r));
}

int bbl(int pos, int H)
{
	int lo = 1, hi = pos, mid, best = 0, x;
	while(lo <= hi)
	{
		mid = (lo+hi)/2;
		x = query(1, 1, N-1, mid, pos);
		if(x <= H)
		{
			best = pos-mid+1;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	return best;
}

int bbr(int pos, int H)
{
	int lo = pos, hi = N, mid, best = 0, x;
	while(lo <= hi)
	{
		mid = (lo+hi)/2;
		x = query2(1, 2, N, pos, mid);
		if(x <= H)
		{
			best = mid-pos+1;
			lo = mid+1;
		}
		else
			hi = mid-1;
	}
	return best;
}

int main()
{
	int x, h, op;
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	build(1, 1, N-1);
	build2(1, 2, N);
	/*for(int i = 1; i < N; i++)
		printf("%d ", query(1, 1, N-1, i, i));
	printf("\n");
	for(int i = 2; i <= N; i++)
		printf("%d ", query2(1, 2, N, i, i));
	printf("\n\n");*/
	while(Q--)
	{
		scanf("%d %d %d", &op, &x, &h);
		if(op == 1)
		{
			A[x] = h;
			if(x != 1)
			{
				//printf("A: %d %d\n", x-1, abs(A[x]-A[x-1]));
				update(1, 1, N-1, x-1, abs(A[x-1]-A[x]));
			}
			if(x != N)
			{	
				//printf("B: %d %d\n", x, abs(A[x+1]-A[x]));
				update(1, 1, N-1, x, abs(A[x]-A[x+1]));
			}
			if(x != 1)
			{
				//printf("C: %d %d\n", x, abs(A[x]-A[x-1]));
				update2(1, 2, N, x, abs(A[x]-A[x-1]));
			}
			if(x != N)
			{
				//printf("D: %d %d\n", x+1, abs(A[x+1]-A[x]));
				update2(1, 2, N, x+1, abs(A[x+1]-A[x]));
			}
			/*for(int i = 1; i < N; i++)
				printf("%d ", query(1, 1, N-1, i, i));
			printf("\n");
			for(int i = 2; i <= N; i++)
				printf("%d ", query2(1, 2, N, i, i));
			printf("\n\n");*/
		}
		else
		{
			//printf("%d %d\n", bbl(x-1, h), bbr(x+1, h));
			printf("%d\n", bbl(x-1, h)+bbr(x+1, h)+1);
		}
	}
	return 0;
}
