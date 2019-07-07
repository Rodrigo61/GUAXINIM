#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define vll vector<ll>

int N;
deque<ll> d;
vll vals;

int main()
{
	scanf("%d", &N);
	int turn = 0;
	for (int i = 0; i < N; i++)
	{
		ll v;
		scanf("%lld", &v);
		vals.pb(v);
		
	}
	sort(all(vals));
	reverse(all(vals));
	for (ll i : vals)
	{
		if (turn)
		{
			d.push_back(i);
		}
		else
		{
			d.push_front(i);
		}
		turn  = !turn;
	}
	
	bool poss = true;
	for (int i = 1; i < N - 1; i++)
	{
		if (d[i] >= d[i - 1] + d[i + 1])
		{
			poss = false;
		}
	}
	
	if (d[0] >= d[1] + d[N - 1] || d[N - 1] >= d[N - 2] + d[0])
	{
		poss = false;
	}
	
	if (poss)
	{
		printf("YES\n");
		for (ll i : d)
			printf("%lld ", i);
	}
	else
	{
		printf("NO\n");
	}
	
	
	
}
