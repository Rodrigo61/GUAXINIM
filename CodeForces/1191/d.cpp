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

const string p1 = "sjfnb";
const string p2 = "cslnb";

int main()
{
	int N;
	scanf("%d", &N);
	map<ll, int> mp;
	set<ll> gte2;
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		ll v;
		scanf("%lld", &v);
		if (mp.find(v) == mp.end()) mp[v] = 0;
		mp[v]++;
		sum += v;
	}
	
	for (auto p : mp)
	{
		int v = p.first;
		if (mp[v] >= 3)
		{
			return !printf("%s\n", p2.c_str());
		}
		if (v == 0 && mp[v] == 2)
		{
			return !printf("%s\n", p2.c_str());
		}
		if (mp[v] == 2)
		{
			gte2.insert(v);
			if ((int)gte2.size() == 2)
				return !printf("%s\n", p2.c_str());
				
			if (mp.find(v - 1) != mp.end())
				return !printf("%s\n", p2.c_str());
		}
	}
	
	ll exp_sum = (N * (N - 1)) / 2;
	ll res = exp_sum - sum;
	
	if (res % 2 == 0)
	{
		printf("%s\n", p2.c_str());
	}
	else
	{
		printf("%s\n", p1.c_str());
	}
	
	
	
}
