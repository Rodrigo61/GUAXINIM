#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;

ll N, T;
vector<ll> vals;
ll curr_t, curr_c;

pair<ll, ll> get_cost()
{
	ll cycle_t = curr_t;
	ll cost = 0;
	ll items = 0;
	
	for (ll v : vals)
	{
		if (v <= cycle_t)
		{
			cycle_t -= v;
			cost += v;
			++items;
		}
	}
	
	return {cost, items};
}

int main()
{

	scanf("%lld%lld", &N, &T);
	
	vals.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	curr_t = T;
	ll total = 0;
	while (true)
	{
		auto c = get_cost();
		curr_c = c.first;
		ll items = c.second;
		
		db(curr_c);
		db(curr_t);
		db(items);
		
		if (items == 0)
		{
			break;
		}
		
		total += items*(curr_t / curr_c);
		curr_t = curr_t % curr_c;
		
		db(total);
	}
	
	//total += get_cost().second;
	
	printf("%lld\n", total);
	
}
