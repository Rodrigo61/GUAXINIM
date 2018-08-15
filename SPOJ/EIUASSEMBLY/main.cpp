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

int N, BUD;
vi P, M;

bool possible(int T)
{
	
	ll curr_BUD = BUD;
	
	for (int i = 0; i < N; i++)
	{
		if (P[i] < T)
		{
			ll aux = curr_BUD;
			curr_BUD -= (T - P[i]) * M[i];
		}
		
		if (curr_BUD < 0)
		{
			return false;
		}
	}
	
	return true;
	
}

ll solve()
{
	ll upper = 1000000000000000;
	ll lower = 0;
	ll mid;
	
	while (lower < upper)
	{
		
		mid = lower + (upper - lower + 1) / 2;
		db(upper);
		db(lower);
		db(mid);
		
		if (possible(mid)) 
		{
			lower = mid;
		}
		else
		{
			upper = mid - 1;
		}
	}
	
	return lower;
}

int main() 
{

	int T;
	scanf("%d", &T);
	
	for (int q = 0; q < T; q++)
	{
		scanf("%d%d", &N, &BUD);
		
		P.resize(N);
		M.resize(N);
		
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d", &P[i], &M[i]);
		}
		
		//~ print_vector_debug(P);
		//~ return 0;
		
		
		printf("%lld\n", solve());
	}
	
	return 0;
}
