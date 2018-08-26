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

int vals[1000001];
int N, M;

bool possible(int m)
{
	ll acu = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (vals[i] > m)
		{
			acu += vals[i] - m;
		}
	}
	
	return acu >= (ll)M;
	
}

int solve()
{
	int upper = 1000000000;
	int lower = 0;
	int best;
	
	while (lower <= upper)
	{
		int mid = lower + (upper-lower)/2;
		
		if (possible(mid))
		{
			best = mid;
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
	}
	
	return best;
}


int main() 
{
	
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	printf("%d\n", solve());
	return 0;
}
