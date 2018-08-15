#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef unsigned long long ll;
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

vector<vector<vll>> dp;

ll solve(int c, int A, int B)
{

	if (c == 0)
	{
		return 1;
	}
	
	
	ll &res = dp[c][A][B];
	if (res != -1)
	{
		return res;
	}
	
	res = 0;
	
	for (int i = 0; A - i >= 0; i++)
	{
		for (int j = 0; B - j >= 0; j++)
		{
			res += solve(c - 1, A - i, B - j);
		}
	}
	
	return res;
}

int main() 
{
	
	int N, A, B;

	scanf("%d%d%d", &N, &A, &B);
	
	dp.resize(N + 1, vector<vll>(A + 1, vll(B + 1, -1)));
	printf("%llu", solve(N, A, B));
	return 0;
}
