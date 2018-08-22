#include<bits/stdc++.h>

using namespace std;
#define db(x) //cerr << #x << " == " << x << endl;	

typedef vector<int> vi;
int C, P, X, L;

int main()
{
	
	scanf("%d%d%d%d", &C, &P, &X, &L);
	
	vi init_degree(C + 1, 0);
	vector<set<int>> vet_adj(C + 1);
	
	
	for (int i = 0; i < P; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		
		vet_adj[u].insert(v);
		vet_adj[v].insert(u);
		
		init_degree[u]++;
		init_degree[v]++;
	}
	
	
	queue<int> q;
	q.push(L);
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		
		if (u == X)
		{
			return !printf("leave\n");
		}
		
		for (auto &v : vet_adj[u])
		{
			vet_adj[v].erase(u);
			
			if ((int)vet_adj[v].size() <= init_degree[v]/2)
			{
				q.push(v);
			}
		}
		vet_adj[u].clear();
	}
	
	printf("stay\n");
	
	
	return 0;
}
