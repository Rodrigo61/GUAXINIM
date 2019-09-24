#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define pll pair<ll, ll>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
int main()
{
	int n;
	scanf("%d", &n);
	vll vals(n + 2);
	vals[0] = vals[n + 1] = INF;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	vll max_l(n + 1), max_r(n + 1), min_l(n + 1), min_r(n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		int j = i - 1;
		while (vals[j] != INF && vals[j] < vals[i])
			j = max_l[j];		
		max_l[i] = j;
	}
 
	for (int i = n; i > 0; i--)
	{
		int j = i + 1;
		while (vals[j] != INF && vals[j] <= vals[i])
			j = max_r[j];		
		max_r[i] = j;
	}
 
	for (int i = 1; i <= n; i++)
	{
		int j = i - 1;
		while (vals[j] != INF && vals[j] >= vals[i])
			j = min_l[j];		
		min_l[i] = j;
	}
 
	for (int i = n; i > 0; i--)
	{
		int j = i + 1;
		while (vals[j] != INF && vals[j] > vals[i])
			j = min_r[j];		
		min_r[i] = j;
	}
 
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += (i - max_l[i]) * (max_r[i] - i) * vals[i];
		res -= (i - min_l[i]) * (min_r[i] - i) * vals[i];
	}
	
	printf("%lld\n", res);
}
