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


ll N, M, F, S, T;
#define INF 1000000000000000
#define MAXN 50001

vector<ll> G[MAXN], W[MAXN];
ll dist[MAXN];
vector<pair<ll, ll>> voos;

void dijkstra(int s)
{
	ll  u, v, w;
	priority_queue<pair<ll, ll> > fila;
	for(int i = 0; i < N; i++)
			dist[i] = INF;
			
	dist[s] = 0;
	fila.push(make_pair(0, s));
	
	while(!fila.empty())
	{
		w = -fila.top().first;
		u = fila.top().second;
		fila.pop();
		if(w > dist[u])
			continue;
		for(int i = 0; i < (int)G[u].size(); i++)
		{
			v = G[u][i];
			w = W[u][i];
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				fila.push(make_pair(-dist[v], v));
			}
		}
	}
}

int main() 
{
	
	scanf("%lld%lld%lld%lld%lld", &N, &M, &F, &S, &T);
	
	ll u, v, u2v;
	for (int i = 0; i < M; i++)
	{
		scanf("%lld%lld%lld", &u, &v, &u2v);
		
		G[u].pb(v);
		W[u].pb(u2v);
		G[v].pb(u);
		W[v].pb(u2v);
	}
	
	voos.resize(F);
	for (int i = 0; i < F; i++)
	{
		scanf("%lld%lld", &voos[i].first, &voos[i].second);
		
		if (voos[i].first == S && voos[i].second == T)
		{
			return !printf("0\n");
		}
	}
	
	
	ll dist_from_source[N];
	ll dist_from_target[N];
	
	dijkstra(S);
	for (int i = 0; i < N; i++)
	{
		dist_from_source[i] = dist[i];
	}
	
	dijkstra(T);
	for (int i = 0; i < N; i++)
	{
		dist_from_target[i] = dist[i];
	}
	
	
	ll min_dist = dist_from_source[T];
	for (auto &p : voos)
	{
		min_dist = min(min_dist, dist_from_source[p.first] + dist_from_target[p.second]);
	}
	
	
	printf("%lld\n", min_dist);
	
	
	

	return 0;
}
