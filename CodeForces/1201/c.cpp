#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

#define MAXN 112345

int main()
{
	ll N, K;
	scanf("%lld%lld", &N, &K);
	vll vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	sort(all(vals));
	
	ll mid = (N - 1) / 2;
	ll it = mid + 1;
	ll cost = 1;
	
	while (K)
	{
		if (it == N)
		{
			vals[mid] += K / cost;
			break;
		}

		ll diff = vals[it] - vals[mid];
		ll cost_diff = diff * cost;
		
		if (K < cost_diff)
		{
			vals[mid] += K / cost;
			break;
		}
		
		vals[mid] += diff;
		K -= cost_diff;
		++it;
		++cost;
	}
	
	printf("%lld\n", vals[mid]);
		
}
