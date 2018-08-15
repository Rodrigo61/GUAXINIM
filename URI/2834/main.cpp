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

#define valid(i, j) (i >= 0 && i < N && j >= 0 && j < M && ((i+1) % 2 == 1 || (j + 1) % 2 == 1)) && !vis[i][j]

int N, M;
int is, js, it, jt;
int max_dist;
int vis[11][11];

void dfs(int i, int j, int dist)
{
	
	if (i == it && j == jt)
	{
		max_dist = max(max_dist, dist);
		return;
	}

	vis[i][j] = 1;
	
	if (valid(i - 1, j))
	{
		dfs(i - 1, j, dist + 1);
	}
	if (valid(i + 1, j))
	{
		dfs(i + 1, j, dist + 1);
	}
	if (valid(i, j - 1))
	{
		dfs(i, j - 1, dist + 1);
	}
	if (valid(i, j + 1))
	{
		dfs(i, j + 1, dist + 1);
	}
	
	vis[i][j] = 0;
}

int main() 
{
	
	scanf("%d%d", &N, &M);
	scanf("%d%d%d%d", &is, &js, &it, &jt);
	--is, --js, --it, --jt;
	
	dfs(is, js, 0);
	
	printf("%d\n", max_dist + 1);
	return 0;
}
