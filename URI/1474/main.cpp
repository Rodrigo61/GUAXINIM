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

#define MOD (int)1000000
#define multMod(a, b) ((a % MOD) * (b % MOD)) % MOD
#define sumMod(a, b) ((a % MOD) + (b % MOD)) % MOD

#define MAXN 1
#define N 2
ll C[MAXN+1][MAXN+1];


void multiply(ll A[MAXN+1][MAXN+1], ll B[MAXN+1][MAXN+1])
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			C[i][j] = 0;
			
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
			{
				C[i][j] = (C[i][j] + multMod((ll)A[i][k], B[k][j])) % MOD;
			}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			A[i][j] = C[i][j] % MOD;
}

int main() 
{
	
	ll I, K, L;
	
	while (scanf("%lld%lld%lld", &I, &K, &L) != EOF)
	{
		ll transf[2][2] = {{K, L}, {1, 0}};
		ll ans[2][2] = {{1, 0}, {0, 1}};
		
		if (I == 10)
		{
			printf("%06lld\n", sumMod(L, multMod(K,K)));
			continue;
		}
		if (I == 5)
		{
			printf("%06lld\n", (K % MOD));
			continue;
		}
		
		I /= 5;
		I -= 2;
		
		while (I)
		{
			if (I & 1)
			{
				multiply(ans, transf);
			}
			multiply(transf, transf);
			I >>= 1;
		}
		
		printf("%06lld\n", sumMod(multMod(ans[0][0], sumMod(L, multMod(K, K))), multMod(ans[0][1], K)));
	}
	
	return 0;
}
