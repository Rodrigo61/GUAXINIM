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

#define MAXN 312345

ll vals[MAXN];
 
int main()
{
	int N;
	scanf("%d", &N);
	ll total = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
		total += vals[i];
	}
	sort(vals, vals + N);
	
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		int v;
		scanf("%d", &v);
		printf("%lld\n", total - vals[N - v]);
	}
	
}
