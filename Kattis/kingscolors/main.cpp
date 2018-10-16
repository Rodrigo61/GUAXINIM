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


#define MAXN 2505
#define MOD 1000000007

int N, K;

int vis2[MAXN][MAXN];
ll dp[MAXN][MAXN];


ll mult_mod(int a, int b)
{
	ll _a = a;
	ll _b = b;
	ll _c = ((_a % MOD) * (_b % MOD)) % MOD;
	
	return _c;
	
}

int solve(int i, int c)
{
	db(i);
	//~ int u = order2id[i];
	//~ db(u);
	db(c);
	if (c < 0)
	{
		return 0;
	}
	
	if (i == 1)
	{
		if (c == 0)
		{
			return K - 1;
		}
		else if (c == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	if (vis2[i][c])
	{
		return dp[i][c];
	}
	vis2[i][c] = 1;
	
	//~ ll res = 0;

	//~ res = (mult_mod(solve(i - 1, c - 1), c) + mult_mod(solve(i - 1, c), (K - c - 1))) % MOD;
	
	ll res = mult_mod(solve(i - 1, c - 1), c);

	if (K - c - 1 > 0)
	{
		res = (res + mult_mod(solve(i - 1, c), (K - c - 1))) % MOD;
	}
	

	dp[i][c] = res;
	return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	scanf("%d%d", &N, &K);
	
	printf("%d\n", solve(N, K));
	
    return 0;
}
