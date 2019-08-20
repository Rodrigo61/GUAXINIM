
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
 
 
int main()
{
	int N;
	scanf("%d", &N);
	ll maxi = 0;
	ll total = 0;
	for (int i = 0; i < N; i++)
	{
		ll v;
		scanf("%lld", &v);
		maxi = max(maxi, v);
		total += v;
	}

	ll half = total / 2;
	if (total & 1 || maxi > half)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
		
}
