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
	
	int N, A, B;
	
	scanf("%d%d%d", &N, &A, &B);
	
	multiset<ll, greater<ll>> holes;
	
	ll first_hole;
	ll S = 0;
	
	scanf("%lld", &first_hole);
	
	S += first_hole;
	
	ll v;
	for (int i = 1; i < N; i++)
	{
		scanf("%lld", &v);
		S += v;
		holes.insert(v);
	}
	
	int ans = 0;
	for (ll i : holes)
	{
		if (first_hole*A/S >= B)
		{
			break;
		}
		
		S -= i;
		ans++;
	}
	
	
	printf("%d\n", ans);
	
	
	

	return 0;
}
