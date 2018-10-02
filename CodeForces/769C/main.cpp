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

#define MAXN 1001
#define INF 1001001001

int N, M, K;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

int cx, cy;
string res;

bool valid(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < M && grid[i][j] != '*';
}


void calc_dists()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dist[i][j] = INF;
		}
	}
	
	dist[cx][cy] = 0;
	
	queue<pii> q;
	q.push({cx, cy});
	
	while (!q.empty())
	{
		int ux = q.front().first;
		int uy = q.front().second;
		q.pop();
		
		if (valid(ux - 1, uy) && dist[ux - 1][uy] == INF)
		{
			dist[ux - 1][uy] = dist[ux][uy] + 1;
			q.push({ux - 1, uy});
		}
		if (valid(ux + 1, uy) && dist[ux + 1][uy] == INF)
		{
			dist[ux + 1][uy] = dist[ux][uy] + 1;
			q.push({ux + 1, uy});
		}
		if (valid(ux, uy - 1) && dist[ux][uy - 1] == INF)
		{
			dist[ux][uy - 1] = dist[ux][uy] + 1;
			q.push({ux, uy - 1});
		}
		if (valid(ux, uy + 1) && dist[ux][uy + 1] == INF)
		{
			dist[ux][uy + 1] = dist[ux][uy] + 1;
			q.push({ux, uy + 1});
		}
		
	}
	
}


bool solve(int limit)
{
	int remaining = limit;
	
	while (remaining)
	{

		if (valid(cx + 1, cy) && dist[cx + 1][cy] < remaining)
		{
			res += "D";
			cx += 1;
		} 
		else if (valid(cx, cy - 1) && dist[cx][cy - 1] < remaining)
		{
			res += "L";
			cy -= 1;
		} 
		else if (valid(cx, cy + 1) && dist[cx][cy + 1] < remaining)
		{
			res += "R";
			cy += 1;
		} 
		else if (valid(cx - 1, cy) && dist[cx - 1][cy] < remaining)
		{
			res += "U";
			cx -= 1;
		}
		else
		{
			return false;
		}
		
		--remaining;

	}
	
	return true;
	
}


int main() 
{
	scanf("%d%d%d\n", &N, &M, &K);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &grid[i][j]);
			
			if (grid[i][j] == 'X')
			{
				cx = i;
				cy = j;
			}
		}
		scanf("\n");
	}

	if (K & 1)
	{
		return !printf("IMPOSSIBLE\n");
	}
	
	if (!valid(cx - 1, cy) && !valid(cx + 1, cy) && !valid(cx, cy - 1) && !valid(cx, cy + 1))
	{
		return !printf("IMPOSSIBLE\n");
	}
	
	calc_dists();
	
	if (solve(K))
	{
		printf("%s\n", res.c_str());
	}
	else
	{
		printf("IMPOSSIBLE\n");
	}
	
	return 0;
}
