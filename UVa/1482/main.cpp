#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

ll grundy(ll n)
{
	return n & 1 ? grundy(n/2):n/2;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		ll xr = 0;
		for (int i = 0; i < N; i++)
		{
			ll v;
			scanf("%lld", &v);
			xr ^= grundy(v);
		}
		
		if (xr == 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		
	}
	
}
