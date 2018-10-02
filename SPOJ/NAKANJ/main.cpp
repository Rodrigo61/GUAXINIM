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

#define INF 10000000

int x1, x2, y_1, y_2;
int dist[8][8];

bool valid(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8 && dist[x][y] == INF;
}

vector<pii> get_adj(int x, int j)
{
	return vector<pii> {{x - 2, j - 1},
						{x + 2, j - 1},
						{x - 2, j + 1},
						{x + 2, j + 1},
						{x - 1, j - 2},
						{x - 1, j + 2},
						{x + 1, j - 2},
						{x + 1, j + 2}};
}
void bfs()
{
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			dist[i][j] = INF;
		}
	}
	

	queue<pii> q;
	q.push({x1, y_1});
	dist[x1][y_1] = 0;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (x == x2 && y == y_2)
		{
			break;
		}
		
		for (pii v : get_adj(x, y))
		{
			if (valid(v.first, v.second))
			{
				dist[v.first][v.second] = dist[x][y] + 1;
				q.push(v);
			}
		}
	}
	
}

int main() 
{
	int T;
	scanf("%d\n", &T);
	
	while (T--)
	{
		char c1, c2;
		
		scanf("%c%d %c%d\n", &c1, &y_1, &c2, &y_2);
		
		y_1--;
		y_2--;
		x1 = c1 - 'a';
		x2 = c2 - 'a';
		
		bfs();
		printf("%d\n", dist[x2][y_2]);
		
	}
	
	return 0;
}
