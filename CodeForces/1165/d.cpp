#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " 1<< x << endl;
#define all(x) x.begin(), x.end()

set<ll> divisors;

int main()
{
	
	int Q;
	scanf("%d", &Q);
	
	while (Q--)
	{
		int N;
		scanf("%d", &N);
		vector<ll> vals(N);
		divisors.clear();
		for (int i = 0; i < N; i++)
		{
			scanf("%lld", &vals[i]);
			divisors.insert(vals[i]);
		}
		
		bool possible = true;

		
		for (ll d : divisors)
		{
			for (int i = 2; i*i <= d; i++)
			{
				if (d % i == 0)
				{
					if (divisors.find(i) == divisors.end())
					{
						possible = false;
						break;
					}
					if (divisors.find(d/i) == divisors.end())
					{
						possible = false;
						break;
					}
				}
			}
			if (!possible)
			{
				break;
			}
			
		}
		
		sort(all(vals));
		
		int l = 1, r = N - 2;
		ll target = vals[0] * vals[N - 1];
	
		for (int i = 0; i < ((N+1)/2) - 1 && possible; i++)
		{
			if (vals[l] * vals[r] != target)
			{
				possible = false;
				break;
			}
			++l;
			--r;
		}
		
		if (possible)
		{
			printf("%lld\n", target);
		}
		else
		{
			printf("-1\n");
		}
		
		
	}
	
}
