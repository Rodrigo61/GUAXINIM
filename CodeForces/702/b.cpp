#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define ll long long

int N;
int vals[MAXN];
vector<int> pot;

void calc()
{
	ll i = 1;
	while (i <= 2000000000)
	{
		pot.pb(i);
		i *= 2;
	}
}

int main()
{
	calc();
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	sort(vals, vals+N);
	
	ll total = 0;
	for (int i = 0; i < N; i++)
	{
		int a = vals[i];
		
		for (int p : pot)
		{
			int b = p - a;
			total += upper_bound(vals + i + 1, vals+N, b) - lower_bound(vals + i + 1, vals+N, b);
		}
	}
	
	printf("%lld\n", total);
	return 0;
}
