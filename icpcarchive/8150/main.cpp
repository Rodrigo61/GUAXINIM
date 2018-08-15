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
	ll W, N;
	
	while(scanf("%lld%lld", &W, &N) != EOF)
	{
		
		ll area = 0;
		
		ll l, w;
		for (int i = 0; i < N; i++)
		{
			scanf("%lld%lld", &l, &w);
			
			area += l * w;
		}
		
		printf("%lld\n", area/W);
	}
	
	

	return 0;
}
