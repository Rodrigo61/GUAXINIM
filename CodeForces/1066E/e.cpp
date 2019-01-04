#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 200005
#define MOD 998244353

int N, M;
int a[MAXN], b[MAXN];

int main()
{
	scanf("%d%d\n", &N, &M);
	
	char c;
	for (int i = 0; i < N; i++)
	{
		scanf("%c", &c);
		a[N - i - 1] = c - '0';
	}
	scanf("\n");
	for (int i = 0; i < M; i++)
	{
		scanf("%c", &c);
		b[M - i - 1] = c - '0';
	}
	
	ll pw = 1;
	ll sum = 0;
	ll total = 0;
	
	for (int i = 0; i < M; i++)
	{
		if (i < N && a[i] == 1)
		{
			sum = (sum + pw) % MOD;
		}
		
		if (b[i] == 1)
		{
			total = (total + sum) % MOD;
		}
		
		pw = (pw + pw) % MOD;
	}
	
	printf("%lld\n", total);
	

	return 0;
}
