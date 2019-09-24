#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
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

struct block
{
	ll hL, hR;
	ll cost;
};
list<block> lst;


void merge(list<block>::iterator it)
{
	if (it == lst.begin()) return;
	
	auto it2 = it;
	--it2;
	while (it2->hR - 1 == it->hR)
	{
		it->hL = it2->hL;
		it->cost += it2->cost;
		if (it2 == lst.begin())
		{
			lst.erase(it2);
			break;
		}
		else
		{
			auto aux = it2;
			aux--;
			lst.erase(it2);
			it2 = aux;
		}
		
	}
}


void print_it(list<block>::iterator it)
{
	//~ printf("hL = %lld  hR = %lld  cost = %lld\n", it->hL, it->hR, it->cost);
}


int main()
{
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n;
		scanf("%d", &n);
		lst.clear();
	
		ll cost = 0;
		vll as, bs;
		for (int i = 0; i < n; i++)
		{
			ll a, b;
			scanf("%lld%lld", &a, &b);
			as.pb(a);
			bs.pb(b);
			
			//todo empty
			if (lst.empty())
			{
				lst.push_back({a, a, b});
				continue;
			}
			
			auto it = lst.end();
			--it;
			
			print_it(it);
			
			if (it->hR == a)
			{
				db("d1");
				if (it->cost < b)
				{
					db("d1.1");
					cost += it->cost;
					it->cost += b;
					it->hR = a;
					it->hL++;
					
					merge(it);
				}
				else
				{
					db("d1.2");
					lst.clear();
					lst.push_back({a + 1, a + 1, b});
					cost += b;
				}
			}
			else
			{
				db("d2");
				lst.push_back({a, a, b});
				it = lst.end();
				--it;
				merge(it);
			}
		}
		
		ll res = cost;
		
		db("-------");
		cost = 0;
		lst.clear();
		for (int i = n - 1; i >= 0; i--)
		{
			ll a = as[i];
			ll b = bs[i];
			db(a);
			db(b);
			
			//todo empty
			if (lst.empty())
			{
				lst.push_back({a, a, b});
				continue;
			}
			
			auto it = lst.end();
			--it;
			
			print_it(it);
			
			if (it->hR == a)
			{
				db("d1");
				if (it->cost < b)
				{
					db("d1.1");
					cost += it->cost;
					it->cost += b;
					it->hR = a;
					it->hL++;
					
					merge(it);
				}
				else
				{
					db("d1.2");
					lst.clear();
					lst.push_back({a + 1, a + 1, b});
					cost += b;
					
				}
			}
			else
			{
				db("d2");
				lst.push_back({a, a, b});
				it = lst.end();
				--it;
				merge(it);
			}
		}
		
		printf("%lld\n", min(cost, res));
		
	}
	
}
