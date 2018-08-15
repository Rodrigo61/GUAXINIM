#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef unsigned long long ll;
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

ll N, B;



ll solve()
{
	ll upper = (N + 1)/2;
	ll lower = 1;
	ll a1 = (N - 1) * 4;
	ll best;
	
	while (lower <= upper)
	{
		ll mid = lower + (upper - lower) / 2;
		
		ll n = mid - 1;
		ll pivo = 1 + (n * (2 * a1 + (n - 1) * (-8)))/2;
		
		if (pivo <= B)
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

ll get_delta(ll beg, ll end)
{
	if (beg > end)
	{
		swap(beg, end);
	}
	
	ll upper = end - beg;
	ll lower = 0;
	ll best;
	
	while (lower <= upper)
	{
		ll mid = lower + (upper - lower)/2;
		
		if (beg + mid <= B)
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
	
	
	scanf("%llu%llu", &N, &B);
	
	//~ ll n_voltas = (N + 1) / 2;
	
	//~ for (int i = 1; i <= n_voltas; i++)
	//~ {
		//~ int n = i - 1;
		//~ int pivo = 1 + (n * (2 * a1 + (n - 1) * (-8)))/2;
		
		//~ printf("pivo %d = %d\n", i, pivo);
	//~ }
	
	ll lower_pivo_frame = solve();
	db(lower_pivo_frame);
	ll n = lower_pivo_frame - 1;
	ll a1 = (N - 1) * 4;
	ll pivo = 1 + (n * (2 * a1 + (n - 1) * (-8)))/2;
	ll seq_sz = N - 2 * (n);
	
	db(seq_sz);

	ll lower, upper;
	
	db(pivo + 1 * (seq_sz - 1));
	db(pivo + 2 * (seq_sz - 1));
	db(pivo + 3 * (seq_sz - 1));
	
	if (B <= pivo + seq_sz - 1)
	{
		lower = pivo;
		upper = pivo + seq_sz - 1;
		
		ll delta = get_delta(lower, upper);
		ll i = lower_pivo_frame;
		ll j = lower_pivo_frame + delta;
		
		printf("%lld %lld\n", i, j);
	}
	else if (B <= pivo + 2 * (seq_sz - 1))
	{
		lower = pivo + seq_sz - 1;
		upper = pivo + 2 * (seq_sz - 1);
		
		ll delta = get_delta(lower, upper);
		ll i = lower_pivo_frame + delta;
		ll j = lower_pivo_frame + seq_sz - 1;
		
		printf("%lld %lld\n", i, j);
	}
	else if (B <= pivo + 3 * (seq_sz - 1))
	{
		lower = pivo + 2 * (seq_sz - 1);
		upper = pivo + 3 * (seq_sz - 1);
		
		ll delta = get_delta(lower, upper);
		db(delta);
		db(seq_sz - delta);
		ll i = lower_pivo_frame + seq_sz - 1;
		ll j = lower_pivo_frame + (seq_sz - delta) - 1;
		
		printf("%lld %lld\n", i, j);
	}
	else
	{
		lower = pivo + 3 * (seq_sz - 1);
		upper = pivo + 4 * (seq_sz - 1);
		
		ll delta = get_delta(lower, upper);
		ll i = lower_pivo_frame + (seq_sz - delta) - 1;
		ll j = lower_pivo_frame;
		
		printf("%lld %lld\n", i, j);
	}
	
	
	return 0;
}
