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

int N, L;

ll __lcm(ll a, ll b)
{

	return a * (b/__gcd(a, b));
}

int main() 
{

	scanf("%d%d", &N, &L);
	
	ll fixed_lcm;
	scanf("%lld", &fixed_lcm);
	for (int i = 1; i < N; i++)
	{
		ll val;
		scanf("%lld", &val);

		fixed_lcm = __lcm(fixed_lcm, val);
	}
	
	//~ db(fixed_lcm);
	
	ll max_lcm = 0;
	int max_num = 0;
	
	for (int i = 1; i <= L; i++)
	{
		ll lcm = __lcm(fixed_lcm, i);
	
		if (lcm > max_lcm && lcm <= L)
		{
			max_lcm = lcm;
			max_num = i;
		}
		
	}
	
	
	printf("%d\n", max_num);
	
	
	

	return 0;
}
