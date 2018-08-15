#include<bits/stdc++.h>
#define MAXN 1000000

#define db(x) //cerr << #x << " == " << x << endl;

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;

int N, M;
vii edges;
vi order;
vi ans;

struct Node{
	int pai;
	int rank;
};

class UnionFind{
	
	vector<Node> vet_node;
	int total;
	
public:

	UnionFind()
	{
		total = N;
		vet_node.resize(N);
		for (int i = 0; i < N; i++)
		{
			vet_node[i].pai = i;
			vet_node[i].rank = 1;
		}
		
	}

	int find(int i)
	{
		if (vet_node[i].pai == i)
		{
			return i;
		}
		
		
		vet_node[i].pai = find(vet_node[i].pai);
		return vet_node[i].pai;
	}
	
	bool unionByRank(int i, int j)
	{
		int paii = find(i);
		int paij = find(j);
		
		db(i);
		db(j);
		db(paii);
		db(paij);
		
		
		if (paii == paij)
		{
			return false;
		}
		
		total--;
		if (vet_node[paii].rank > vet_node[paij].rank)
		{
			vet_node[paij].pai = paii;
		}
		else if (vet_node[paii].rank > vet_node[paij].rank)
		{
			vet_node[paii].pai = paij;
		}
		else
		{
			vet_node[paii].pai = paij;
			vet_node[paij].rank++;
		}
		
		return true;
	}
		
};

void solve()
{
	UnionFind UF;
	
	int total = N;
	ans.clear();
	for (int i = M - 1; i >= 0; i--)
	{
		int u = edges[order[i]].first;
		int v = edges[order[i]].second;
		
		ans.push_back(N);
		if (UF.unionByRank(u, v))
		{
			N--;
		}
		
	}
	
}

int main()
{
	scanf("%d%d", &N, &M);
	
	edges.resize(M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &edges[i].first, &edges[i].second);
		--edges[i].first, --edges[i].second;
	}
	
	order.resize(M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &order[i]);
		--order[i];
	}
	
	solve();
	
	reverse(ans.begin(), ans.end());
	for(int i : ans)
	{
		printf("%d\n", i);
	}
	

	return 0;
}
