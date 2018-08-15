#include "bits/stdc++.h"
using namespace std;

#define db(x) cout << #x << " == " << x << endl
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
int qtos_div[10000001];

int mod_pow(ll base, ll exp)
{
	ll ans = 1;
	while (exp)
	{
		if (exp & 1)
		{
			ans = (ans * base) % MOD;
		}
		
		base = (base * base) % MOD;
		exp >>= 1;
	}
	
	return ans;
}

int main() 
{

	int A, B, N;
	scanf("%d%d%d", &A, &B, &N);
	
	memset(qtos_div, 0, sizeof(qtos_div));
	for (int i = 1; i < B + 1; i++)
	{
		for (int j = i; j < B + 1; j += i)
		{
			qtos_div[j]++;
		}
	}
	
	int n_grupos = 0;
	for (int i = A; i <= B; i++)
	{
		if (qtos_div[i] == N)
		{
			++n_grupos;
		}
	}
	
	printf("%d\n", mod_pow(n_grupos, B - A + 1 - n_grupos));
	

	return 0;
}
