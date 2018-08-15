#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
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

ll B;
ll E, V;

struct Node{

	ll id, cost, repu;
	Node(){}
	Node(int i, int j, int k): id(i), cost(j), repu(k){}
	
	bool operator < (Node const& other) const {
        if (this->cost < other.cost)
		{
			return true;
		}
		
		if (this->cost == other.cost)
		{
			return this->repu > other.repu;
		}
		
		return false;
    }
};

vector< pair<ll, pll > > vet_adj[10001];
int in_count[10001];
map<string, ll> name2id;
pll best_values[10001];
pll dijkstra_values[10001];
vector<ll> seted;
vector<vll> dp;

pll solve(ll idx, ll W)
{
	
	if (idx == V)
	{
		return {0, 0};
	}
	
	if (dp[idx][W] != make_pair((ll)-1, (ll)-1))
	{
		return dp[idx][W];
	}
	
	pll not_take = solve(idx + 1, W);
	pll take = {0,0};
	if (W - best_values[idx].first >= 0)
	{
		 take = solve(idx + 1, W - best_values[idx].first);
	}
	else
	{
		dp[idx][W] = {not_take.first, not_take.second};
		return dp[idx][W];
	}
	
	if (take.first + best_values[idx].second > not_take.first)
	{
		dp[idx][W] = {take.first + best_values[idx].second, take.second + best_values[idx].first};
	}
	else if (take.first + best_values[idx].second < not_take.first)
	{
		dp[idx][W] = {not_take.first, not_take.second};
	}
	else
	{
		if (take.second < not_take.second)
		{
			dp[idx][W] = {not_take.first, not_take.second};
		}
		else
		{
			dp[idx][W] = {take.first + best_values[idx].second, take.second + best_values[idx].first};
		}
	}
	
	
	return dp[idx][W];
}

void dijkstra(ll u)
{
	for (int i = 0; i < V; i++)
	{
		dijkstra_values[i] = {999999, 0};
	}
	
    dijkstra_values[u] = {0, 0};

    priority_queue<Node> pq;
    Node ne;
    ne.id = u;
    ne.cost = 0;
    ne.repu = 0;
    pq.push(ne);

    while(!pq.empty()){
        
        Node nu = pq.top() ;
		int u = nu.id;
		int cost = nu.cost;
		int repu = nu.repu;
		pq.pop();

        if(dijkstra_values[u].first < cost) continue;
        if (dijkstra_values[u].first == cost && dijkstra_values[u].second > repu) continue;

		dijkstra_values[u] = {cost, repu};
		if (cost < best_values[u].first)
		{
			best_values[u] = dijkstra_values[u];
		}
		if (cost == best_values[u].first && repu > best_values[u].second)
		{
			best_values[u] = dijkstra_values[u];
		}
		
        for(auto &pv :  vet_adj[u]){
            ll v = pv.first;
            ll vcost = pv.second.first + cost;
            ll vrepu = pv.second.second + repu;
            
            db(v);
            db(vcost);
            db(vrepu);

            if (vcost < best_values[v].first)
			{
				dijkstra_values[v] = {vcost, vrepu};
				Node ne;
				ne.id = v;
				ne.cost = vcost;
				ne.repu = vrepu;
				pq.push(ne);
			}
			if (vcost == best_values[v].first && vrepu > best_values[v].second)
			{
				dijkstra_values[v] = {vcost, vrepu};
				Node ne;
				ne.id = v;
				ne.cost = vcost;
				ne.repu = vrepu;
				pq.push(ne);
			}
        }
    }
}

char aux[30];
int main() 
{
	while (scanf("%lld\n", &B) != EOF)
	{
		name2id.clear();
		scanf("%lld\n", &E);
		V = 0;
		
		string u, v;
		
		for (int i = 0; i < E; i++)
		{
			scanf("%s ", aux);
			u = aux;
			db(u);
			if (name2id.find(u) == name2id.end())
			{
				name2id[u] = V;
				++V;
			}
			
			scanf("%s", aux);
			v = aux;
			db(v);
			if (name2id.find(v) == name2id.end())
			{
				name2id[v] = V;
				++V;
			}
			
			ll cost, repu;
			scanf("%s %lld %lld\n", aux, &cost, &repu);
			
			vet_adj[name2id[v]].pb({name2id[u], {cost, repu}});
			in_count[name2id[u]]++;
		}
		
		for (int i = 0; i < V; i++)
		{
			best_values[i] = {999999, 0};
		}
		
		for (int i = 0; i < V; i++)
		{
			if (in_count[i] == 0)
			{
				dijkstra(i);
			}
		}

		dp.clear();
		dp.resize(V, vll(B + 1, {-1, -1}));		
		auto ans = solve(0, B);

		printf("%lld\n", ans.first);
		printf("%lld\n", ans.second);
		
	}

	return 0;
}
