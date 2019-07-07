#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 212345

int N;
ll vals[MAXN];
int H[MAXN];
int nextgt[MAXN];

ll solve(int pos)
{
	ll res = 0;
	
	if (nextgt[pos])
	{
		res = max(res, solve(nextgt[pos]));
		res = max(res, solve(nextgt[pos]) + vals[pos]);
	}
	
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &H[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	for (int i = N - 1; i > 0; i--)
	{
		int j = i + 1;
		while (H[j] <= H[i])
			j = nextgt[j];		
		nextgt[i] = j;
	}
	
	for (int i = 1; i <= N; i++)
	{
		db(nextgt[i]);
	}
	
	
	printf("%lld\n", solve(1));
	
}
