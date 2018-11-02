#include <bits/stdc++.h>

using namespace std;

#define MAXN (int)1e5+5
#define db(x) cerr << #x << " = " << x << endl;

int N;
vector<int> tree[MAXN];

int vis[MAXN];

double solve(int u, int dist)
{
	vis[u] = 1;
	
	if (dist != 0 && tree[u].size() == 1)
	{
		return dist;
	}
	
	double ans = 0;
	
	for (auto v : tree[u])
	{
		if (!vis[v])
		{
			if (dist != 0)
			{
				ans += 1.0/(double)(tree[u].size() - 1) * solve(v, dist + 1);
			}
			else
			{
				ans += 1.0/(double)(tree[u].size()) * solve(v, dist + 1);
			}
		}
	}
	
	return ans;
}

int main()
{
	scanf("%d", &N);
	
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	printf("%lf\n", solve(1, 0));
	
}
