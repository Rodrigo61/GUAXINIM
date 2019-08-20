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
#define all(x) x.begin(), x.end()
 
vi adj[300];
int trans[300][300];

void dfs(int rep, int u)
{
	trans[rep][u] = 1;
	for (auto v : adj[u])
		if (!trans[rep][v])
			dfs(rep, v);
}
 
int main()
{
	int M, Q;
	cin >> M >> Q;
	for (int i = 0; i < M; i++)
	{
		char a, b;
		cin >> a >> b;
		adj[(int)a].pb(b);
	}
	
	for (int i = 0; i < 300; i++)
	{
		dfs(i, i);
	}
	
	
	for (int i = 0; i < Q; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		
		if ((int)s1.size() != (int)s2.size())
		{
			printf("no\n");
			continue;
		}
		
		bool poss = true;
		for (int i = 0; i < (int)s1.size(); i++)
		{
			if (s1[i] != s2[i] && !trans[(int)s1[i]][(int)s2[i]])
			{
				printf("no\n");
				poss = false;
				break;
			}
		}
		
		if (poss)
			printf("yes\n");
	}
	
	
}
