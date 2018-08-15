#include "bits/stdc++.h"
using namespace std;

#define db(x) //cout << #x << " == " << x << endl
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

int N, M;
vector<vector<char>> grid;
vector<vector<int>> grid_id;
vector<vi> dist;
vector<vi> visited;
int id;
int full_bitmask;


bool valid(int i, int j)
{
	
	return i >= 0 && i < N && j >= 0 && j < M && !visited[i][j] && grid[i][j] != 'x';
}


vii get_neigh(pii u)
{

	vii res;
	
	if (valid(u.first - 1, u.second))
	{
		res.pb({u.first - 1, u.second});
	}
	
	if (valid(u.first, u.second - 1))
	{
		res.pb({u.first, u.second - 1});
	}
	
	if (valid(u.first + 1, u.second))
	{
		res.pb({u.first + 1, u.second});
	}
	
	if (valid(u.first, u.second + 1))
	{
		res.pb({u.first, u.second + 1});
	}
	
	return res;
	
}

void dist_from(int i, int j)
{
	
	vector<vi> d(N, vi(M, 0));
	visited.clear();
	visited.resize(N, vi(M, 0));
	
	visited[i][j] = 1;
	int curr_id = grid_id[i][j];
	
	queue<pii> q;
	q.push({i, j});
	
	db(i);
	db(j);
	while (!q.empty())
	{
		pii u = q.front();
		q.pop();
		
		if (grid_id[u.first][u.second] != -1)
		{
			db(u.first);
			db(u.second);
			db(grid_id[u.first][u.second]);
			dist[curr_id][grid_id[u.first][u.second]] = d[u.first][u.second];
		}
		
		for (auto &p : get_neigh(u))
		{
			visited[p.first][p.second] = 1;
			d[p.first][p.second] = d[u.first][u.second] + 1;
			q.push(p);
		}
	}
	
}

void calc_dists()
{
	
	id = 1;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == '*')
			{
				grid_id[i][j] = id;
				++id;
			}
			
			if (grid[i][j] =='o')
			{
				grid_id[i][j] = 0;
			}
			
		}	
	}

	db(id);
	dist.clear();
	dist.resize(id, vi(id, 99999));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid_id[i][j] != -1)
			{
				dist_from(i, j);
			}
		}	
	}
	
	//~ for (int i = 0; i < id; i++)
	//~ {
		//~ for (int j = 0; j < id; j++)
		//~ {
			//~ printf("%d ", dist[i][j]);
		//~ }
		//~ printf("\n");
		
	//~ }
	//~ printf("\n");
	
	
}

vector<vi> dp;

int solve(int c, int bitmask)
{

	if (bitmask == full_bitmask)
	{
		return 0;
	}
	
	
	int &res = dp[c][bitmask];
	
	if (res != -1)
	{
		return res;
	}
	
	res = 999999;
	
	for (int i = 1; i < id; i++)
	{
		if (!(bitmask & (1 << i)))
		{
			res = min(res, solve(i, bitmask | (1 << i)) + dist[c][i]);
		}
	}
	
	return res;
	
}

int main() 
{
	
	while (scanf("%d %d\n", &M, &N), N+M)
	{
		grid.clear();
		grid.resize(N, vector<char>(M));
		grid_id.clear();
		grid_id.resize(N, vector<int>(M, -1));
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%c", &grid[i][j]);
			}
			scanf("\n");
		}
		
		calc_dists();
		full_bitmask = (1 << id) - 1;
		
		dp.clear();
		dp.resize(id, vi(full_bitmask, -1));
		int res = solve(0, 1);
		
		
		if (res < 9999)
		{
			printf("%d\n", res);
		}
		else
		{
			printf("-1\n");
		}
		
		
	}

	return 0;
}
