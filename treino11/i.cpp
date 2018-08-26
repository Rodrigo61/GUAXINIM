#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;

pair<int, int> vis[100006];

int cnt = 1;

void dfs(int pos){
	vis[pos].first = cnt;
	for(int i = 0; i < adj[pos].size(); i++){
		int nx = adj[pos][i];
		if(vis[nx].first == 0){
			cnt++;
			dfs(nx);
		}
	}
	vis[pos].second = cnt;
} 

int main(){
	int n, q;
	cin >> n >> q;
	
	vector<int> v;
	
	adj.resize(n+1);
	
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		if(a != -1)
			adj[a].push_back(i);
		else
			v.push_back(i);
	}
	
	for(int i = 0; i < v.size(); i++){
		dfs(v[i]);
		cnt++;
	}
	
	for(int i = 0; i < q; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == y)
			printf("Yes\n");
		else if(vis[x].first > vis[y].first && vis[x].second <= vis[y].second)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	
	
	return 0;
	
}
