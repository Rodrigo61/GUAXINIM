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

#define INF 1000000000000000
int N;
ll vals[101];
vector<vector<pair<ll, int>>> dp;

pair<ll, int> solve(int beg, int end)
{
	db(beg);
	db(end);
	
	if (beg == end)
	{
		return {0, vals[beg]};
	}
	
	pair<ll, int> &res = dp[beg][end];
	
	if (res.first != -1)
	{
		return res;
	}
	
	res = {INF, 0};
	for (int i = beg; i < end; i++)
	{
		auto left = solve(beg, i);
		auto right = solve(i + 1, end);
		
		if (left.first + right.first + left.second * right.second < res.first)
		{
			res.first = left.first + right.first + left.second * right.second;
			res.second = (left.second + right.second) % 100;
		}
	}
	
	return res;
	
}


int main() 
{

	while (scanf("%d", &N) != EOF)
	{
		for (int i = 0; i < N; i++)
		{
			scanf("%lld", &vals[i]);
		}
		
		dp.clear();
		dp.resize(N, vector<pair<ll, int>>(N, {-1, -1}));
		printf("%lld\n", solve(0, N - 1).first);
		
	}

	return 0;
}
