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
	ll N, S;
	scanf("%lld%lld", &N, &S);

	vll vals(N);
	ll total = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
		total += vals[i];
	}
	
	if (total < S)
	{
		return !printf("-1\n");
	}
	
	ll extra = 0;
	ll mini = *min_element(all(vals));
	for (int i = 0; i < N; i++)
	{
		extra += vals[i] - mini;
	}
	db(mini);
	if (extra >= S)
	{
		return !printf("%lld\n", mini);
	}
	
	ll res = S - extra;
	ll q = res / N;
	
	if (res % N == 0)
	{
		printf("%lld\n", mini - q);
	}
	else
	{
		printf("%lld\n", mini - q - 1);
	}
	
	return 0;
}
