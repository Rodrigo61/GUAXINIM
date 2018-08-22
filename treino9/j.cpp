#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

#define MAXN 101

typedef pair<int, int> pii;
int N;
vector<int> adj[MAXN];
vector<pii> stu, tut;
vector<bool> used(MAXN), visit(MAXN);

int match[MAXN], dist[MAXN];

void bfs(int n1, int n2)
{
	fill(dist, dist + n1, -1);
	queue<int> q;
	for(int u = 0; u < n1; u++)
	{
		if(!used[u])
		{
			q.push(u);
			dist[u] = 0;
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int j = 0; j < (int)adj[u].size(); j++)
		{
			int v = match[adj[u][j]];
			if(v >= 0 && dist[v] < 0)
			{
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}

bool dfs(int u)
{
	visit[u] = true;
	for(int j = 0; j < (int)adj[u].size(); j++)
	{
		int v = match[adj[u][j]];
		if(v < 0 || (!visit[v] && dist[v] == dist[u]+1 && dfs(v)))
		{
			match[adj[u][j]] = u;
			used[u] = true;
			return true;
		}
	}
	return false;
}

int hopcroft_karp(int n1, int n2)
{
	fill(match, match+n2, -1);
	fill(used.begin(), used.end(), false);
	int res = 0;
	for(;;)
	{
		bfs(n1, n2);
		fill(visit.begin(), visit.end(), false);
		int f = 0;
		for(int u = 0; u < n1; u++)
		{
			if(!used[u] && dfs(u))
			{
				f++;
			}
		}
		if(f == 0)
		{
			return res;
		}
		res += f;
	}
	return res;
}

int dist2(pii a, pii b){
	return abs(a.F - b.F) + abs(a.S - b.S);
}

int test(int cut){
	for(int i = 0; i < N; i++)
		adj[i].clear();
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
		{
			if(dist2(stu[i], tut[j]) <= cut)
				adj[i].pb(j);
		}
		
	return hopcroft_karp(N, N);
}

main()
{
	
	cin >> N;
	stu.resize(N);
	tut.resize(N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &stu[i].F, &stu[i].S);
	}
	
	for(int i = 0; i < N; i++){
		scanf("%d %d", &tut[i].F, &tut[i].S);
	}
	
	int mn = 0, mx = 1000000000;
	while(mx > mn){
		//printf("%d %d\n", mn, mx);
		int md = (mn + mx)/2;
		if(test(md) == N){
			mx = md;
		}
		
		else{
			mn = md + 1;
		}
	}
	
	cout << mn << endl;
	
	return 0;
}
