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

#define MAXN 5005
int N;
pair<int, int> vals[MAXN];
int in[MAXN];

int t;
int dp[MAXN][MAXN];
int vis[MAXN][MAXN];

int solve(int i, int j)
{
	if (i >= j)
	{
		return 0;
	}
	
	if (vis[i][j] == t)
	{
		return dp[i][j];
	}
	vis[i][j] = t;
	
	int pos = (upper_bound(vals, vals + N, make_pair(in[i], j))) - vals - 1;
	auto match = vals[pos];

	int res = solve(i + 1, j);
	
	if (match.second <= j && match.second > i && match.first == in[i])
	{
		res = max(res, solve(i + 1, match.second - 1) + 1);
	}
	a
	dp[i][j] = res;
	return res;
}


int main() 
{
	while (scanf("%d", &N) != EOF)
	{
		int val;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &val);
			in[i] = val;
			vals[i] = {val, i};
		}
		sort(vals, vals + N);

		t++;
		printf("%d\n", solve(0, N - 1));
	}
	
	return 0;
}
