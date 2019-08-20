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
 
int main()
{
	ll N, K;
	scanf("%lld%lld", &N, &K);
	
	ll up = N;
	ll lo = 0;
	ll best = 0;
	while (lo <= up)
	{
		ll mid  = lo + (up - lo)/2;
		ll rest = N - mid;
		ll sum = (rest*(rest+1))/2;
		
		if (sum - mid <= K)
		{
			best = mid;
			up = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	
	printf("%lld\n", best);
}
