#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long

typedef vector<int> vi;

int N, M;
vi photos;
vector<set<int>> in_adj;
vector<set<int>> out_adj;
vi memo;
int full_bitmask;

vi visited;
vi in_stack;

bool dfs(int u)
{
    if(!visited[u])
	{
        visited[u] = true;
        in_stack[u] = true;
 
		for (auto &v : out_adj[u]) 
		{	
			if (in_stack[v])
				return true;
				
			if (dfs(v))
				return true;
		}
    }
    in_stack[u] = false;  
    return false;
}
 
bool has_cycle()
{
	visited.assign(N, 0);
	in_stack.assign(N, 0);

    for(int i = 0; i < N; i++)
        if (dfs(i))
            return true;
 
    return false;
}

bool unlocked(int bitmask, int i) {
	
	for (auto v : in_adj[i]) {
		if (!(bitmask & (1 << v))) {
			return false;
		}
	}
	
	return true;
}

int multmod(int i, int j) {
	
	return (i * j) % MOD ;
}

int solve(int bitmask) {
	
	if (bitmask == full_bitmask) {
		return 1;
	}
	
	//~ printf("%d\n", bitmask);
	int &res = memo[bitmask];
	//~ printf("res = %d\n", res);
	if (res != -1) {
		return res;
	}
	
	//~ printf("not memo\n");
	
	res = 0;
	for (int i = 0; i < N; i++)
	{
		//~ printf("i = %d\n", i);
		if (!(bitmask & (1 << i)) && unlocked(bitmask, i)) {	
			res = (res + multmod(photos[i], solve(bitmask | (1 << i)))) % MOD;
			//~ printf("res = %d\n", res);
		}
	}
	
	return res;
	
}

signed main() {
	
	scanf("%I64d %I64d", &N, &M);
	
	photos.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%I64d", &photos[i]);
	}
	
	//~ printf("d1\n");
	in_adj.resize(N);
	out_adj.resize(N);
	
	int u, v;
	for (int i = 0; i < M; i++)
	{
		scanf("%I64d %I64d", &u, &v);
	
		--u, --v;
		in_adj[u].insert(v);
		out_adj[v].insert(u);	
		//~ out[v] |= 1 << u;
		//~ in[u] |= 1 << v;
	}
	
	//~ printf("aqui\n");
	
	if (has_cycle()) {
		
		//~ printf("has cycle\n");
		
		return !printf("0\n");
	} else {
		
		full_bitmask = (1 << N) - 1;
		memo.resize(full_bitmask, -1);
		printf("%I64d\n", solve(0));
		
	}
	
	
	return 0;
}
