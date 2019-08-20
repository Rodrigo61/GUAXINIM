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
	ll L, N;
	scanf("%lld%lld", &L, &N);
	ll res = 0;
	if (N != 1)
	{
		res += N - 1;
		L -= N - 1;
	}
	res += L*L;
	printf("%lld\n", res);
}
