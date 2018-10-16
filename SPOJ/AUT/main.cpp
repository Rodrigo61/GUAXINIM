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

#define MAXN 45

int cost[MAXN], e_count[MAXN];

int dp[MAXN][1605][MAXN];

int solve(int i, int b, int k)
{
	//~ printf("(i = %d, b = %d, k = %d) \n", i, b, k);
	if (i == 0)
	{
		return 0;
	}
	
	int &res = dp[i][b][k];
	
	if (res != -1)
	{
		return res;
	}
	
	res = 0;
	
	for (int q = 0; q <= e_count[i]; q++)
	{
		int c_cost = (q * cost[i]);
		if (k + q > 40 || b < c_cost)
		{
			continue;
		}
		
		int for_free = min(e_count[i] - q, k);
		res = max(res, solve(i - 1, b - c_cost, k + q) + c_cost + for_free * cost[i]); 
	}
	
	return res;
}

int main() 
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		int N, K;
		scanf("%d%d", &N, &K);
		
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &cost[i]);
		}
		int acumulate = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &e_count[i]);
			acumulate += e_count[i] * cost[i];
		}
		
		
		if (K > 1600)
		{
			printf("%d\n", acumulate);
			continue;
		}
		
		
		for (int i = 0; i < MAXN; i++)
		{
			for (int j = 0; j < 1605; j++)
			{
				for (int k = 0; k < MAXN; k++)
				{
					dp[i][j][k] = -1;
				}
			}
		}
		
		printf("%d\n", solve(N, K, 0));
	}
	
	return 0;
}
