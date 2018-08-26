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

#define MOD 1000007

ll mult_mod(ll a, ll b)
{
	return ((a % MOD) * (b % MOD)) % MOD;
}

int main() 
{
	
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		ll n;
		scanf("%lld", &n);
		
		--n;
		
		ll res;
		if (n & 1)
		{
			res = mult_mod(n, (n + 1) / 2);
		}
		else
		{
			res = mult_mod(n / 2, n + 1);
		}
		
		res = (res + mult_mod(n, n + 1)) % MOD;
		res = (res + (mult_mod(2, n) + 2) % MOD) % MOD;
		printf("%lld\n", res);
	}

	return 0;
}
