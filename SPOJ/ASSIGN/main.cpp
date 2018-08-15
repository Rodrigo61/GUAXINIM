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

int N;
int fullmask;
vector<vi> grid;
vector<vll> dp;

ll solve(int c, int bitmask)
{
	if (c == N)
	{
		return 1;
	}
	
	ll &res = dp[c][bitmask];
	
	if (res != -1)
	{
		return res;
	}
	
	res = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (!(bitmask & (1 << i)) && grid[c][i])
		{
			res += solve(c + 1, bitmask | (1 << i));
		}
	}
	
	return res;
	
}

int main() 
{

	int T;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		cin >> N;
		
		grid.clear();
		grid.resize(N, vi(N));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> grid[i][j];
			}
		}
		
		fullmask = (1 << N) - 1;
		dp.clear();
		dp.resize(N, vll(fullmask, -1));
		printf("%lld\n", solve(0, 0));
		
	}
	
	return 0;
}
