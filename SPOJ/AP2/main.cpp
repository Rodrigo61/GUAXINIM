#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef long long ll;


int main() 
{

	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		
		bool rev = false;
		
		if (a > b)
		{
			swap(a, b);
			rev = true;
		}
		
		ll ab = a + b;
		
		if ((c-3*ab) % ab == 0)
		{
			ll sz = (c / ab) * 2;
			db(sz);
			
			ll in_middle = sz - 6;
			db(in_middle);
			ll step = (b - a)/(in_middle + 1);
			db(step);
			
			ll start = a - 2 * step;
			
			if (rev)
			{
				start = b + 2 * step;
				step = -step;
			}
			
			printf("%d\n", sz);
			for (ll i = 0; i < sz; i++)
			{
				printf("%lld ", start);
				start += step;
			}
			printf("\n");
			
		}
		else
		{
			ll sz = 1 + ((c - ab/2) / ab) * 2;
			
			ll in_middle = sz - 6;
			ll step = (b - a)/(in_middle + 1);
			
			ll start = a - 2 * step;
			if (rev)
			{
				start = b + 2 * step;
				step = -step;
			}
			
			printf("%d\n", sz);
			for (ll i = 0; i < sz; i++)
			{
				printf("%lld ", start);
				start += step;
			}
			printf("\n");
		}
	}
	return 0;
}	
