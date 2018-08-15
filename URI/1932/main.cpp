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

int main() 
{

	int N, C;
	scanf("%d%d", &N, &C);
	
	int vals[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	int dp[N + 1][2];
	dp[N][0] = 0;
	dp[N][1] = 0;
	
	for (int i = N - 1; i >= 0; i--)
	{
		dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] - vals[i] - C);
		dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] + vals[i]);
	}
	
	printf("%d\n", dp[0][0]);
	
	return 0;
}
