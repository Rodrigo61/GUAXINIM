#include<bits/stdc++.h>

using namespace std;

int mem[3605];
int n, t;
int com[20];

pair<int, int> bfs(){
	queue<int> fila;
	fila.push(0);
	mem[0] = 0;
	while(!fila.empty()){
		int at = fila.front();
		fila.pop();
		
		for(int i = 0; i < n; i++){
			int nx = min(max(at + com[i], 0), 3600);
			if(mem[nx] == -1){
				mem[nx] = mem[at] + 1;
				fila.push(nx);
			}
		}
	}
	
	if(mem[t] != -1)
		return {mem[t], 0};
	
	int i = t;
	while(mem[i] == -1)
		i++;
	
	return {mem[i], i - t};
}

int main(){
	int T;
	cin >> T;
	while(T--){
		
		cin >> n >> t;
		memset(mem, -1, sizeof(mem));
		
		for(int i  = 0; i < n; i++)
			scanf("%d", &com[i]);
		
		pair<int, int> p = bfs();
		
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}
