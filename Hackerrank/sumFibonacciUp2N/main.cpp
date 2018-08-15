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

void multiply(ll A[3][3], ll B[3][3])
{
	ll C[3][3];
	int N = 3;
	
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

int main() 
{

	int N;
	scanf("%d", &N);

	ll mat[3][3];
	mat[0][0] = 1;
	mat[0][1] = 1;
	mat[0][2] = 1;
	mat[1][0] = 0;
	mat[1][1] = 1;
	mat[1][2] = 1;
	mat[2][0] = 0;
	mat[2][1] = 1;
	mat[2][2] = 0;
	
	ll ans[3][3];
	ans[0][0] = 1;
	ans[0][1] = 0;
	ans[0][2] = 0;
	ans[1][0] = 0;
	ans[1][1] = 1;
	ans[1][2] = 0;
	ans[2][0] = 0;
	ans[2][1] = 0;
	ans[2][2] = 1;
	
	N--;
	while (N)
	{
		if (N & 1)
		{
			multiply(ans, mat);
		}
		
		multiply(mat, mat);
		N >>= 1;
	}
	printf("%lld\n", ans[0][0] + ans[0][1]);

	
	
	return 0;
}
