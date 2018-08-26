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


#define MOD 1000000007

void matrix_mult(ll A[3][3], ll B[3][3])
{
	ll C[3][3];
	memset(C, 0, sizeof(C));
	for (int i = 0; i < 3; i++)
	{
		for (int b_j = 0; b_j < 3; b_j++)
		{
			for (int j = 0; j < 3; j++)
			{
				C[i][b_j] = (C[i][b_j] + (A[i][j] % MOD * B[j][b_j] % MOD) % MOD) % MOD;
			}
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			A[i][j] = C[i][j];
		}
	}
	
}

void matrix_pow(ll A[3][3], int e)
{
	
	ll ans[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	
	while (e)
	{
		if (e & 1)
		{
			matrix_mult(ans, A);
		}
		
		matrix_mult(A, A);
		e >>= 1;
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			A[i][j] = ans[i][j];
		}
		
	}
	
}

int fib(int L)
{
	if (L < 0)
	{
		return 0;
	}
	
	ll transf[3][3] = {{1, 1, 0}, {0, 1, 1}, {0, 1, 0}};
	matrix_pow(transf, L);
	
	return transf[0][1];
}

int main() 
{
	
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		int M, N;
		scanf("%d%d", &N, &M);
		
		db(fib(N - 1));
		db(fib(M));
		printf("%d\n", (fib(M) - fib(N - 1) + MOD) % MOD);
	}

	return 0;
}
