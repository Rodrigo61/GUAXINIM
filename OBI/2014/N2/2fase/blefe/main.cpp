#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	set<ll> A;
	for (int i = 0; i < N; i++)
	{
		ll v;
		scanf("%lld\n", &v);
		A.insert(v);
	}
	
	set<ll> vals;
	for (int i = 0; i < M; i++)
	{
		ll v;
		scanf("%lld\n", &v);
		
		if (A.find(v) != A.end())
		{
			vals.insert(v);
			continue;
		}
		
		auto l = vals.begin();
		auto r = --vals.end();
		bool poss = false;
		while (true)
		{
			ll sum = *l + *r;
			if (sum == v)
			{
				poss = true;
				break;
			}
			
			if (l == r) break;
			
			if (sum > v)
				--r;
			else
				++l;
		}
		
		if (!poss)
		{
			return !printf("%lld\n", v);
		}
		
		vals.insert(v);
	}	
	
	printf("sim\n");
	
}
