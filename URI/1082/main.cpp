#include <bits/stdc++.h>

using namespace std;
#define db(x) cerr << #x << " = " << x << endl;

int main()
{
	int T;
	scanf("%d", &T);
	int nc = 0;
	
	while (T--)
	{
		int N, M;
		scanf("%d%d\n", &N, &M);
		vector<vector<int>> adj(N);
		
		for (int i = 0; i < M; i++)
		{
			char a, b;
			scanf("%c %c\n", &a, &b);
			adj[a - 'a'].push_back(b - 'a');
			adj[b - 'a'].push_back(a - 'a');
		}
		
		printf("Case #%d:\n", ++nc);
		
		vector<int> vis(N);
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			if (!vis[i])
			{
				++total;
				vector<int> res;
				queue<int> q;
				q.push(i);
				vis[i] = 1;
				
				while (!q.empty())
				{
					int u = q.front();
					q.pop();
					
					res.push_back(u);	
					
					for (auto v: adj[u])
					{
						if (!vis[v])
						{
							vis[v] = 1;
							q.push(v);
						}
					}
				}
				
				sort(res.begin(), res.end());
				for (auto c: res)
					printf("%c,", c + 'a');
				printf("\n");
			}
			
		}
		
		printf("%d connected components\n\n", total);
	}
	
}
