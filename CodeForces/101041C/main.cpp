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

ll modInverse(ll a, ll b) 
{
	return a > 1LL ? b - ((modInverse(b % a, a) * b)/a) : 1LL;
}

ll inv(ll a, ll b)
{
	ll z = modInverse(a, b);
	if(z < 0)
		return z + b;
	return z;
}

ll fat(ll i)
{
	if (i == 0)
		return 1;
		
	return (i * fat(i - 1)) % MOD;
}

ll modDivision(ll i, ll j) {
	return ((i % MOD) * inv(j, MOD)) % MOD;
}

int main() 
{

	ll N, M;
	scanf("%lld%lld", &N, &M);
	
	ll T = N + M;
	
	printf("%lld\n", modDivision(fat(T), (fat(N) * fat(M)) % MOD));
	return 0;
}
