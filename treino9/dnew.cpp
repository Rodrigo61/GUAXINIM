#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for(int i = (s); i < (e); i++)
#define FOE(i,s,e) for(int i = (s); i <= (e); i++)
#define FOD(i,s,e) for(int i = (s); i >= (e); i--)
#define ll long long
#define pb push_back
#define mp make_pair

int n, m, x, y, z, k, w;
int dp[4005], A[4005];

int main ()
{
	scanf("%d", &n);
	FOE(i, 1, n) scanf("%d", &A[i]);
	
	FOE(i, 1, n)
	{
		FOE(j, 0, i - 1)
		{
			x = A[j + 1] + 1740;
			y = max(A[i] + 80, A[j + 1] + 1800 + 20 * (i - j) + 60); 
			if (j == 0) dp[i] = y - x;
			dp[i] = min(dp[i], dp[j] + (y - x));
		}
	}
	
	printf("%d\n", dp[n]);
	return 0;
}
