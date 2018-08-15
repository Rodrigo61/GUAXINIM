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

	ll N, K, S;
	scanf("%lld%lld%lld", &N, &K, &S);
	
	ll X = S / K;
	ll R = S % K;
	
	db(N);
	db(K);
	db(S);
	db(X);
	db(R);

	
	if (X >= N || K > S)
	{
		return !printf("NO\n");
	}
	
	
	ll dist = 0;
	ll curr_dist = 0;
	ll it = 1;
	
	vi ans;
	
	int turn = 0;
	while (K)
	{
		
		if (turn == 0)
		{
			it += X;
			curr_dist = X;
			
			int extra = min(R, N - it);
			it += extra;
			curr_dist += extra;
			R -= extra;
			--K;
			
			turn = 1;
		}
		else
		{
			it -= X;
			curr_dist = X;
			
			int extra = min(R, it - 1);
			it -= extra;
			curr_dist += extra;
			R -= extra;
			--K;
			
			turn = 0;
		}
		
		ans.pb(it);
		dist += curr_dist;
		
	}
	
	if (dist == S)
	{
		printf("YES\n");
		for (auto &e : ans)
			printf("%d ", e);
	}
	else
	{
		printf("NO\n");
	}
	
	
	return 0;
}
