#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	vll vals(N);
	vll prefix(N);
	ll acu = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
		acu += vals[i];
		prefix[i] = acu;
	}
	
	ll res = 0;
	for (int i = 0; i < N; i++)
	{
		ll target = K + prefix[i] - vals[i];
		auto lo = lower_bound(prefix.begin() + i, prefix.end(), target);
		if (lo != prefix.end() && *lo == target)
		{
			auto up = upper_bound(prefix.begin() + i, prefix.end(), target);
			res += distance(lo, up);
		}
	}
	
	printf("%lld\n", res);
}
