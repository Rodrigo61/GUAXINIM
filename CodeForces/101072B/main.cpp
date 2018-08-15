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

int main() 
{
	
	ll N;
	ll X;
	
	scanf("%lld%lld", &N, &X);
	

	ll final_gcd = 0;
	for (int i = 0; i < X; i++)
	{
		ll val;
		scanf("%lld", &val);
		
		final_gcd = __gcd(final_gcd, val);
	}

	printf("%lld\n", N - N/__gcd(N, final_gcd));
	return 0;
}
