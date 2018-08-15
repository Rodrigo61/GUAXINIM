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

#define MAXN (int)1000001


int main() 
{
	vll factors(MAXN);
	for (int i = 1; i < MAXN; i++)
	{
		for (int j = i; j < MAXN; j += i)
		{
			factors[j] += i;
		}
	}
	
	
	vll ans(MAXN);
	ans[1] = 1;
	for (int i = 2; i < MAXN; i++)
	{
		//~ db(i);
		//~ db(factors[i]);
		
		ans[i] = ans[i - 1] + factors[i];
	}
	
	int N;
	while (scanf("%d", &N), N)
	{
		printf("%lld\n", ans[N]);
	}
	return 0;
}
