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
	int N, K;
	scanf("%d%d", &N, &K);
	
	vi buy(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &buy[i]);
	}
	
	vi sell = buy;
	sell[0] = 0;
	for (int i = 1; i < N; i++)
	{
		int val;
		scanf("%d", &val);
		sell[i] += val;
	}
	
	int last_line[K + 1][2];
	int curr_line[K + 1][2];
	//~ int dp[N + 1][K + 1][2];
	memset(last_line, 0, sizeof(last_line));
	for (int k = 0; k < K + 1; k++)
	{
		last_line[k][0] = 0;
		last_line[k][1] = 0;
		curr_line[k][0] = 0;
		curr_line[k][1] = 0;
	}
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int k = 1; k < K + 1; k++)
		{
			
			curr_line[k][1] = max({last_line[k][1], last_line[k - 1][0] + sell[i], last_line[k - 1][1] + sell[i] - buy[i]});
			curr_line[k][0] = max(last_line[k][0], max(last_line[k][1] - buy[i], 0));
			
		}
		memcpy(last_line, curr_line, sizeof(curr_line));
	}
	
	printf("%d\n", last_line[K][0]);
	

	return 0;
}
