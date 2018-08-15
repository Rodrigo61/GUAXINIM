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


int H, L;

bool valid(int i, int j)
{
	
	return i >= 0 && i < H && j >= 0 && j < L;
}

vii get_neigh(pii u)
{
	
	vii res;
	
	if (valid(u.first - 1, u.second))
	{
		res.pb({u.first - 1, u.second});
	}
	if (valid(u.first + 1, u.second))
	{
		res.pb({u.first + 1, u.second});
	}
	if (valid(u.first, u.second - 1))
	{
		res.pb({u.first, u.second - 1});
	}
	if (valid(u.first, u.second + 1))
	{
		res.pb({u.first, u.second + 1});
	}
	
	return res;
}

int main() 
{

	scanf("%d%d", &H, &L);
	
	vector<vi> grid(H, vi(L));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}
	
	int mini_color = 9999999;
	int mini_white = 9999999;
	vector<vi> visited(H, vi(L, 0));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (!visited[i][j])
			{
				
				db(i);
				db(j);
				
				int size = 1;
				int color = grid[i][j];
				queue<pii> q;
				
				q.push({i, j});
				visited[i][j] = 1;
				
				while (!q.empty())
				{
					pii u = q.front();
					q.pop();
					
					for (auto &v : get_neigh(u))
					{
						if (!visited[v.first][v.second] && grid[v.first][v.second] == color)
						{
							visited[v.first][v.second] = 1;
							q.push(v);
							++size;
						}
					}
				}
				
				db(size);
				if (color == 0)
				{
					mini_white = min(mini_white, size);
				}
				else
				{
					mini_color = min(mini_color, size);
				}
				
			}
		}
	}
	
	
	if (mini_white == 0)
	{
		printf("%d\n", mini_color);
	}
	else if (mini_color == 0)
	{
		printf("%d\n", mini_white);
	}
	else
	{
		printf("%d\n", min(mini_white, mini_color));
	}
	
	
	

	return 0;
}
