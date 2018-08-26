#include<bits/stdc++.h>

using namespace std;

struct Edge
{
	int u, v, w;
};

int N, M, total;
int p[100], l[100];
Edge e[100000];

bool cmp(Edge a, Edge b)
{
	return a.w > b.w;
}

int id(int x)
{
	return (x != p[x] ? p[x] = id(p[x]) : p[x]);
}

void kruskal()
{
	int i, j, u, v, w;
	for(int i = 0; i < N; i++)
	{
		p[i] = i;
		l[i] = 1;
	}
	total = 0;
	sort(e, e+M, cmp);
	for(i = 0, j = 1; i < M && j < N; i++)
	{
		u = id(e[i].u);
		v = id(e[i].v);
		if(l[u] < l[v])
			swap(u, v);
		w = e[i].w;
		if(u != v)
		{
			total += w;
			p[v] = u;
			l[u] += l[v];
			j++;
		}
	}
}

main()
{
	int K;
	for(N = 1; N <= 20; N++)
	{
		for(K = 0; K < N; K++)
		{
			M = 0;
			for(int i = 0; i < N; i++)
			{
				for(int j = 1; j <= K; j++)
				{
					e[M].u = i;
					e[M].v = (i+j)%N;
					e[M++].w = j;
				}
			}
			kruskal();
			printf("%4d ", total);
		}
		printf("\n");
	}
	return 0;
}
