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

#define MAXM (int)1e8 + 5
#define INF 1e9
#define ELEVATOR 0
#define LADDER 1

ll N, M, Cl, Ce, V;

set<ll> elevator, ladder;

ll i1, j_1, i2, j2;

ll go(set<ll>::iterator it, int type)
{
	ll x = *it;
	ll ans = 0;
	
	ans += abs(x - j_1);
	
	if (type == LADDER)
	{
		ans += abs(i1 - i2);
	}
	else
	{
		ans += ceil((double)abs(i1 - i2)/V);
		db(ans);
	}
	
	ans += abs(x - j2);
	return ans;
}

ll go_left()
{	
	ll ans = INF;

	auto it = elevator.lower_bound(j_1);
	if (it != elevator.begin())
	{
		it--;
		ans = min(ans, go(it, ELEVATOR));
	}
	
	it = ladder.lower_bound(j_1);
	if (it != ladder.begin())
	{
		it--;
		ans = min(ans, go(it, LADDER));
	}
	
	return ans;
}

ll go_right()
{	
	ll ans = INF;

	auto it = elevator.lower_bound(j_1);
	if (it != elevator.end())
	{
		ans = min(ans, go(it, ELEVATOR));
	}
	
	it = ladder.lower_bound(j_1);
	if (it != ladder.end())
	{
		ans = min(ans, go(it, LADDER));
	}
	
	return ans;
}


int main() 
{

	scanf("%lld%lld%lld%lld%lld", &N, &M, &Cl, &Ce, &V);
	
	ll p;
	for (int i = 0; i < Cl; i++)
	{
		scanf("%lld", &p);
		db(p);
		ladder.insert(p);
	}
	
	for (int i = 0; i < Ce; i++)
	{
		scanf("%lld", &p);
		db(p);
		elevator.insert(p);
	}
	
	int Q;
	scanf("%d", &Q);
	db(Q);
	
	for (int i = 0; i < Q; i++)
	{
		scanf("%lld%lld%lld%lld", &i1, &j_1, &i2, &j2);
		
		db(i1);
		db(j_1);
		db(i2);
		db(j2);
		
		if (i1 == i2)
		{
			printf("%lld\n", abs(j_1 - j2));
		}
		else
		{
			printf("%lld\n", min(go_left(), go_right()));
		}
		
	}
	
	
	
	
	return 0;
}
