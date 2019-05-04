#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 112345
#define ll long long
#define fi first
#define se second
#define pll pair<ll, ll>


int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	
	ll gcd = 0;
	ll v;
	
	ll last;
	scanf("%lld", &last);
	ll first = last;
	
	for (int i = 1; i < N; i++)
	{
		scanf("%lld", &v);
		gcd = __gcd(gcd, v - last);
		last = v;
	}
	
	int pos = -1;
	for (int i = 0; i < M; i++)
	{
		scanf("%lld\n", &v);
		
		if (gcd % v == 0)
		{
			pos = i;
		}
	}
	
	if (pos == -1)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		printf("%lld ", first);
		printf("%d\n", pos + 1);
	}
	
	
	return 0;
}
