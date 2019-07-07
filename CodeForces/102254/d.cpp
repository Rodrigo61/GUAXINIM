#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl
#define vi vector<int>
#define pb push_back
#define INF 0x3f3f3f3f
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()

int main ()
{
	int N;
	scanf("%d", &N);
	vll vals(2*N);
	for (int i = 0; i < 2 * N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	sort(all(vals));
	
	vll sums;
	
	for (int i = 0; i < N; i++)
	{
		sums.pb(vals[i] + vals[2*N - i - 1]);
	}
	sort(all(sums));
	
	printf("%lld\n", sums.back() - sums[0]);
	
}
