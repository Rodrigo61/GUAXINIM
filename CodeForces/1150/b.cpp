#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 55
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back

int N;
char grid[MAXN][MAXN];
int missing = 0;
const pii NULL_PAIR = {-1, -1};

bool valid(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < N && grid[i][j] == '.';
}

vector<pii> get_neighs(int i, int j)
{
	vector<pii> result;
	
	if (valid(i - 1, j))
	{
		result.pb({i - 1, j});
	}
	if (valid(i + 1, j))
	{
		result.pb({i + 1, j});
	}
	if (valid(i, j - 1))
	{
		result.pb({i, j - 1});
	}
	if (valid(i, j + 1))
	{
		result.pb({i, j + 1});
	}
	
	return result;
	
}

pii find_cand()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			if (!valid(i, j))
			{
				continue;
			}
			
			auto neighs = get_neighs(i, j);
			
			if (neighs.size() == 4)
			{
				return {i, j};
			}
		}
	}
	
	return NULL_PAIR;
}

void fill_cand(pii cand)
{
	auto neighs = get_neighs(cand.fi, cand.se);
	missing -= neighs.size() + 1;
	grid[cand.fi][cand.se] = '#';
	for (auto p : neighs)
		grid[p.fi][p.se] = '#';
}

int main()
{
	scanf("%d\n", &N);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &grid[i][j]);
			if (grid[i][j] == '.')
			{
				++missing;
			}
		}
		scanf("\n");
	}
	
	
	while (true)
	{
		pii cand = find_cand();
		
		db(cand.fi);
		db(cand.se);
		
		if (cand == NULL_PAIR)
		{
			break;
		}
		
		fill_cand(cand);
	}
	
	
	if (missing)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	
	
}
