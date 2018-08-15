#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
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

int N, M, K;
vector<vector<char>> grid;
vii peoes;
int full_bitmask;

bool valid(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < M && grid[i][j] != '#';
}

vii get_neigh(int i, int j)
{
	vii res;

	if (valid(i - 2, j - 1))
	{
		res.pb({i - 2, j - 1});
	}
	if (valid(i - 2, j + 1))
	{
		res.pb({i - 2, j + 1});
	}
	if (valid(i + 2, j - 1))
	{
		res.pb({i + 2, j - 1});
	}
	if (valid(i + 2, j + 1))
	{
		res.pb({i + 2, j + 1});
	}
	
	
	if (valid(i - 1, j - 2))
	{
		res.pb({i - 1, j - 2});
	}
	if (valid(i - 1, j + 2))
	{
		res.pb({i - 1, j + 2});
	}
	if (valid(i + 1, j - 2))
	{
		res.pb({i + 1, j - 2});
	}
	if (valid(i + 1, j + 2))
	{
		res.pb({i + 1, j + 2});
	}
	
	return res;
}

vector<vi> vis;
vector<vi> d;
vector<vi> dist;

void dist_from(int i, int j, int id) {
	
	vis.clear();
	vis.resize(N, vi(M));
	d.clear();
	d.resize(N, vi(M));
	
	d[i][j] = 0;
	vis[i][j] = 1;
	
	queue<pii> q;
	q.push({i, j});
	
	while (!q.empty())
	{
		pii u = q.front();
		q.pop();
		
		for (int k = 0; k < K; k++)
		{
			if (u.first == peoes[k].first && u.second == peoes[k].second)
			{
				dist[id][k] = d[u.first][u.second];
			}
		}
		
		for (auto &v : get_neigh(u.first, u.second))
		{
			if (!vis[v.first][v.second])
			{
				d[v.first][v.second] = d[u.first][u.second] + 1;
				vis[v.first][v.second] = 1;
				q.push({v.first, v.second});
			}
		}
	}
	
}


void calc_dists(int init_i, int init_j)
{
	
	dist.clear();
	dist.resize(K + 1, vi(K + 1));
		
	dist_from(init_i, init_j, K);
	
	for (int i = 0; i < K; i++)
	{
		dist_from(peoes[i].first, peoes[i].second, i);
	}
}

vector<vi> dp;

int solve(int idx, int bitmask)
{
	if (bitmask == full_bitmask)
	{
		return dist[K][idx];
	}
	
	
	int &res = dp[idx][bitmask];
	
	if (res != -1)
	{
		return res;
	}
	
	res = 999999;
	for (int k = 0; k < K; k++)
	{
		if (!(bitmask & (1 << k)))
		{
			res = min(res, solve(k, bitmask | (1 << k)) + dist[idx][k]);
		}
	}
	
	return res;
}


int main() 
{

	while (scanf("%d %d %d\n", &N, &M, &K), N + M + K)
	{
	
		grid.clear();
		grid.resize(N, vector<char>(M));
		peoes.clear();
		
		int init_i, init_j;
				
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%c", &grid[i][j]);
				
				if (grid[i][j] == 'P')
				{
					peoes.pb({i, j});
				}
				
				if (grid[i][j] == 'C')
				{
					init_i = i;
					init_j = j;
				}
			}
			scanf("\n");
		}
		
		calc_dists(init_i, init_j); // [0..K - 1] sao os peoes, K é o cavalo.
		
		full_bitmask = (1 << K) - 1;
		db(full_bitmask);
		
		dp.clear();
		dp.resize(K + 1, vi(full_bitmask, -1));
		printf("%d\n", solve(K, 0));
	
	}
	return 0;
}
