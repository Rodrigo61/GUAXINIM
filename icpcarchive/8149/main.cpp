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

#define MAXN 10001
#define MAXB 10001
#define INF 1e18

int B;
int E, V;
vector< pair<ll, pll > > vet_adj[MAXN];
int in_count[MAXN];
map<string, ll> name2id;
pll best_values[MAXN];

pll dp[MAXN][MAXB];
int vis[MAXN][MAXB];
int vis2[MAXN];
int t;

pll solve(ll idx, ll W)
{
	
	if (W < 0)
	{
		return {-INF, 0};
	}
	
	if (idx == V)
	{
		return {0, 0};
	}	
	
	if (vis[idx][W] == t)
	{
		return dp[idx][W];
	}
	vis[idx][W] = t;
	
	pll res;
	pll not_take = solve(idx + 1, W);
	pll take = solve(idx + 1, W - best_values[idx].first);
	
	if (take.first + best_values[idx].second > not_take.first)
	{
		res = {take.first + best_values[idx].second, take.second + best_values[idx].first};
	}
	else if (take.first + best_values[idx].second == not_take.first && take.second + best_values[idx].first < not_take.second)
	{
		res = {take.first + best_values[idx].second, take.second + best_values[idx].first};
	}
	else
	{
		res = {not_take.first,not_take.second};
	}
	
	dp[idx][W] = res;
	return res;
}

void calc_best_values(int u)
{
	if (vis2[u] == t)
	{
		return;
	}
	vis2[u] = t;
	
	
	if (vet_adj[u].empty())
	{
		best_values[u] = {0, 0};
		return;
	}
	
	for (auto e : vet_adj[u])
	{
		ll v = e.first;
		ll cost = e.second.first;
		ll prestige = e.second.second;
		
		calc_best_values(v);
		
		if (best_values[u].first > best_values[v].first + cost)
		{
			best_values[u].first = cost + best_values[v].first;
			best_values[u].second = prestige + best_values[v].second;
		}
		else if (best_values[u].first == best_values[v].first + cost && best_values[u].second < best_values[v].second + prestige)
		{
			best_values[u].first = cost + best_values[v].first;
			best_values[u].second = prestige + best_values[v].second;
		}
	}
}


char aux[30];

int main() 
{
	while (scanf("%d\n", &B) != EOF)
	{
		t++;
		scanf("%d\n", &E);
		V = 0;
		
		string u, v;
		
		for (int i = 0; i < E; i++)
		{
			scanf("%s ", aux);
			u = aux;
			if (name2id.find(u) == name2id.end())
			{
				name2id[u] = V;
				++V;
			}
			
			scanf("%s", aux);
			v = aux;
			if (name2id.find(v) == name2id.end())
			{
				name2id[v] = V;
				++V;
			}
			
			ll cost, repu;
			scanf("%s %lld %lld\n", aux, &cost, &repu);
			
			vet_adj[name2id[u]].pb({name2id[v], {cost, repu}});
			in_count[name2id[v]]++;
		}
		
		for (int i = 0; i < V; i++)
		{
			best_values[i] = {999999, 0};
		}
		
		for (int i = 0; i < V; i++)
		{
			if (in_count[i] == 0)
			{
				calc_best_values(i);
			}
		}

		auto ans = solve(0, B);

		printf("%lld\n", ans.first);
		printf("%lld\n", ans.second);
		
		name2id.clear();
		memset(in_count, 0, sizeof(in_count));
		for (int i = 0; i < V; i++)
		{
			vet_adj[i].clear();
		}
		
		
	}

	return 0;
}
