#include<bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;
int N, Q;

map<string, int> name2id;
int reachable[200][200];
vector<vector<int>> vet_adj;
int max_id;

int vis[200];

void dfs(int u, int rep)
{
	reachable[rep][u] = 1;
	vis[u] =  1;
	
	for (int v : vet_adj[u])
	{
		if (!vis[v])
		{
			dfs(v, rep);
		}
	}
	
}

void calc_reachable()
{
	
	for (int i = 0; i < max_id; i++)
	{
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
	}
	
}

int main(){

	scanf("%d%d", &N, &Q);
	
	char a1[40], a2[40];
	string s1, s2;
	max_id = 0;
	
	vet_adj.clear();
	vet_adj.resize(200);
	for (int i = 0; i < N; i++)
	{
		scanf("%s  are worse than %s\n", a1, a2);
		s1 = a1;
		s2 = a2;
		
		db(s1);
		db(s2);
		
		if (name2id.find(s1) == name2id.end())
		{
			name2id[s1] = max_id++;
		}
		
		if (name2id.find(s2) == name2id.end())
		{
			name2id[s2] = max_id++;
		}
		
		int u = name2id[s1];
		int v = name2id[s2];
		db(u);
		db(v);
		
		vet_adj[u].push_back(v);
	}
	
	calc_reachable();
	
	for (int i = 0; i < Q; i++)
	{
		scanf("%s  are worse than %s\n", a1, a2);
		s1 = a1;
		s2 = a2;
		
		if (name2id.find(s1) == name2id.end() || name2id.find(s2) == name2id.end())
		{
			printf("Pants on Fire\n");
			continue;
		}
		
		int u = name2id[s1];
		int v = name2id[s2];
		
		if (reachable[u][v])
		{
			printf("Fact\n");
		}
		else if (reachable[v][u])
		{
			printf("Alternative Fact\n");
		}
		else
		{
			printf("Pants on Fire\n");
		}
		
		
	}
	
	
	return 0;
}
