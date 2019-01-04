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

ll N;
vector<ll> divi;

void divisores()
{
	ll sqr = sqrt(N);
	for (ll i = 1; i <= sqr; i++)
	{
		if (N % i == 0)
		{
			divi.push_back(i);
			
			if (N/i != i)
			{
				divi.pb(N/i);
			}
		}
	}
	
}

ll An(ll r, ll n)
{
	return 1 + (n-1)*r;
}

ll PA(ll r, ll n)
{
	return ((1 + An(r, n))*n)/2;
}

int main() 
{
	scanf("%d", &N);
	vector<ll> fun;
	divisores();
	for(ll i : divi)
	{
		fun.pb(PA(i, N/i));
	}

	sort(all(fun));
	for (auto i : fun)
		printf("%lld ", i);
	printf("\n");
	
	return 0;
}
