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
	
	ll total = 0;
	int N, M;
	scanf("%d%d", &N, &M);
	vi C;
	
	for (int i = 0; i < N; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		
		total += a;
		C.pb(b - a);
	}
	db(total);
	
	sort(all(C));
	int it = 0;
	
	while (it < N && total > M)
	{
		db(it);
		db(total);
		total += C[it];
		++it;
	}
	
	
	if (total <= M)
	{
		printf("%d\n", it);
	}
	else
	{
		printf("-1\n");
	}
	

	return 0;
}
