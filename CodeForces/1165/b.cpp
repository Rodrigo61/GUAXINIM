#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;

multiset<ll> contest;
int N;

int main()
{
	scanf("%d", &N);
	ll v;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &v);
		contest.insert(v);
	}
	
	ll total = 0;
	while (!contest.empty())
	{
		ll first = *contest.begin();
		contest.erase(contest.begin());
		
		if (first >= total + 1)
		{
			++total;
		}
		
	}
	
	printf("%lld\n", total);
}
