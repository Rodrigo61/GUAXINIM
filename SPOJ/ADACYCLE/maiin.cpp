#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

#define MAXN 2000
#define INF 1000000

vi adj[MAXN];
int mat[MAXN][MAXN];
int N;

int dist[MAXN];

int bfs(int s)
{
	fill(dist, dist + N, INF);
	dist[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		
		if (mat[u][s])
		{
			return dist[u] + 1;
		}
		
		for (int v : adj[u])
		{
			if (dist[v] == INF)
			{
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		
	}
	
	return 0;
}

int main() 
{
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &mat[i][j]);
			
			if (mat[i][j])
			{
				adj[i].pb(j);
			}
		}
	}
	
	
	for (int i = 0; i < N; i++)
	{
		int aux = bfs(i);
		
		if (aux)
		{
			printf("%d\n", aux);
		}
		else
		{
			printf("NO WAY\n");
		}
		
		
	}
	
	
	return 0;
}
