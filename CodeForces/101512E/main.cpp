#include <bits/stdc++.h>

using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN (int)1e6 + 1
#define r1 first
#define r2 second.first
#define r3 second.second
#define INF 10000000

int N;

pair<int, pair<int, int>> in[MAXN];

int tree[MAXN];

void update(int i, int val)
{
	while (i <= N)
	{
		tree[i] = min(tree[i], val);
		i += (i&-i);
	}
}

int query(int i)
{
	int s = INF;
	while (i > 0)
	{
		s = min(s, tree[i]);
		i -= (i & -i);
	}
	return s;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		for (int i = 0; i < MAXN; i++)
		{
			tree[i] = INF;
		}
		
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d%d", &in[i].r1, &in[i].r2, &in[i].r3);
		}
		
		sort(in, in + N);
		
		int ans = 0;
		for (int i = 0; i < N; i++)
		{		
			if (query(in[i].r2) > in[i].r3)
			{
				++ans;
				update(in[i].r2, in[i].r3);
			}
		}
		
		printf("%d\n", ans);
	}
	
	
}
