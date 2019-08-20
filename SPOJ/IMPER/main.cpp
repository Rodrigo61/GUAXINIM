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
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

#define MAXN 11234 

vi adj[MAXN];
int N;

void dfs(int u, int pu, int curr_deep, int &most_deep, int &target)
{
	if (curr_deep > most_deep)
	{
		target = u;
		most_deep = curr_deep;
	}
	
	for (int v : adj[u])
	{
		if (v != pu)
			dfs(v, u, curr_deep + 1, most_deep, target);
	}
}

int main()
{
	while (scanf("%d", &N), N != -1)
	{
		for (int i = 0; i <= N; i++)
			adj[i].clear();
			
		for (int i = 2; i <= N; i++)
		{
			int v;
			scanf("%d", &v);
			adj[i].pb(v);
			adj[v].pb(i);
		}
		
		int most_deep = 0;
		int target = 1;
		dfs(1, 0, 0, most_deep, target);
		most_deep = 0;
		dfs(target, 0, 0, most_deep, target);

		printf("%d\n", (most_deep + 1) / 2);
	}
}
