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

int main() 
{

	vi squares;
	squares.reserve(22361);
	
	int l = 1;
	while (l * l <= 2000000000)
	{
		squares.pb(l * l);
		l += 2;
	}
	squares.pb(l * l);
	

	ll N;
	while (scanf("%lld", &N), N)
	{

		db(N);

		ll time = *lower_bound(all(squares), N);
		ll i = sqrt(time);
		
		db(time);
		db(i);
		
		ll r1 = time - (i - 1);
		ll r2 = time - 2 * (i - 1);
		ll r3 = time - 3 * (i - 1);
		ll r4 = time - 4 * (i - 1) + 1;
		
		db(r1);
		db(r2);
		db(r3);
		db(r4);
		
		
		if (N >= r1)
		{
			printf("%lld %lld\n", time - N + 1, i);
		}
		else if (N >= r2)
		{
			printf("%lld %lld\n", i, N - r2 + 1); 
		}
		else if (N >= r3)
		{
			printf("%lld %lld\n", i - 1, (i - 1) - (N - r3)); 
		}
		else
		{
			printf("%lld %lld\n", N - r4 + 1, i - 1); 
		}
	}

	return 0;
}
