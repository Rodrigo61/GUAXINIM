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

#define MOD 1000000007


void multiply(ll A[2][2], ll B[2][2])
{
	ll C[2][2];
	int N = 2;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			C[i][j] = 0;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
			{
				C[i][j] = ((ll)C[i][j] + (((ll)A[i][k])*B[k][j]) % MOD) % MOD;
			}
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			A[i][j] = C[i][j];
}

void pow_mat(ll mat[2][2], ll power)
{
	ll cpy[2][2];
	
	if (power == 1) return;
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cpy[i][j] = mat[i][j];
			mat[i][j] = (i == j);
		}
	}
	
	while (power)
	{
		if (power & 1)
		{
			multiply(mat, cpy);
		}	
		
		multiply(cpy, cpy);
		power >>= 1;
	}
	
	for (int i = 0; i < power - 1; i++)
	{
		multiply(mat, cpy);
	}
	
}

int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	
	ll mat[2][2] = {{1,1}, {1, 0}};
	pow_mat(mat, n - 2);
	
	return (mat[0][0] + mat[0][1]) % MOD;
}


int main() 
{
	
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		
		printf("%d\n", fib(n));
	}
	
	return 0;
}
