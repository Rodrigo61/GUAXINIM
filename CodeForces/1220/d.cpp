#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define fi first
#define se second
#define vi vector<int>

#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define vll vector<ll>
#define ull unsigned long long
typedef long double ld;

ll extract_factors(ll a)
{
	while (a % 2 == 0) a /= 2;
	return a;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	vll vals;
	map<ll, int> freq;
	for (int i = 0; i < n; i++)
	{
		ll a;
		scanf("%lld", &a);
		vals.pb(a);
		freq[a]++;
	}
	
	sort(all(vals));
	
	set<ll> factors;
	set<ll> used;
	map<ll, ll> f2i;
	multiset<ll> discarded;
	for (int i = 0; i < n; i++)
	{
		db(vals[i]);
		if (used.find(vals[i]) != used.end())
			continue;
			
		ll f = extract_factors(vals[i]);
		db(f);
		
		if (factors.find(f) != factors.end())
		{
			ll j = f2i[f];
			if (freq[vals[i]] > freq[vals[j]])
			{
				used.erase(used.find(vals[j]));
				used.insert(vals[i]);
				f2i[f] = i;
				for (int k = 0; k < freq[vals[j]]; ++k)
					discarded.insert(vals[j]);
			}
			else
				discarded.insert(vals[i]);
		}
		else
		{
			f2i[f] = i;
			factors.insert(f);
			used.insert(vals[i]);
		}
	}
	
	printf("%d\n", (int)discarded.size());
	if (!discarded.empty())
	{
		for (ll i : discarded)
		{
			printf("%lld ", i);
		}
	}
}
