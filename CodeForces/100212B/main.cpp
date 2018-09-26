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

#define INF 1e18
#define MAXN 2001

int N;
ll freq[MAXN];
ll dp[MAXN][MAXN];
int P[MAXN][MAXN];

ll prefix[MAXN];

ll sum(int i, int j)
{
	if (i > j || i == 0) return 0;
	
	return prefix[j] - prefix[i - 1];
}

void pre_calc()
{
	for (int i = 1; i <= N; i++)
	{
		prefix[i] = prefix[i - 1] + freq[i];
	}
}

void print_solutions(int i, int j, string &code)
{
	if (i == j)
	{
		printf("%s\n", code.c_str());
		return;
	}
	
	
	code.pb('0');
	print_solutions(i, P[i][j] - 1, code);
	code.pop_back();
	
	code.pb('1');
	print_solutions(P[i][j], j, code);
	code.pop_back();
}

int main() 
{
	freopen("codes.in", "r", stdin);
	freopen("codes.out", "w", stdout);
	
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &freq[i]);
	}
	
	
	pre_calc();
	
	
	for (int i = 1; i <= N; i++)
	{
		P[i][i] = i;
	}
	
	
	for (int i = N; i >= 1; i--)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			
			int limit = min(j, P[i + 1][j]);
			int min_k = max(i + 1, P[i][j-1]);
			
			ll min_cost = INF;

			for (int k = min_k; k <= limit; ++k)
			{
				ll new_cost = dp[i][k - 1] + dp[k][j];
				
				if (new_cost < min_cost)
				{
					min_cost = new_cost;
					min_k = k;
				}
			}
			
			dp[i][j] = min_cost + sum(i, j);
			P[i][j] = min_k;
		}
	}
	
	//~ printf("%lld\n", dp[1][N]);
	
	string aux;
	print_solutions(1, N, aux);
	
	
	return 0;
}
