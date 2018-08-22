#include "bits/stdc++.h"
using namespace std;

#define db(x) //cout << #x << " == " << x << endl
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
ll coins[1001];

ll dp[2000001];

ll greedy(ll num)
{
	ll acu = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (num >= coins[i])
		{
			acu += num / coins[i];
			num = num % coins[i];
		}
	}
	
	return acu;
	
}

int main() 
{
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &coins[i]);
	}
	
	for (int i = 1; i < 2000000; i++)
	{
		dp[i] = 100000000000000000;
	}
	
	dp[0] = 0;
	for (int i = 0; i < N; ++i)
	{
		ll c = coins[i];
		for (int j = 1; j < 2000000; j++)
		{
			if (j - c >= 0)
			{
				dp[j] = min(dp[j], dp[j - c] + 1);
			}
		}
	}
	
	
	for (int i = 2; i < 2000000; i++)
	{
		if (greedy(i) != dp[i])
		{
			return !printf("non-canonical\n");
		}
	}
	
	printf("canonical\n");

	return 0;
}
