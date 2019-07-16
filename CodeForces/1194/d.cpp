#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, K;
		scanf("%d%d", &N, &K);
		
		if (N == 0)
		{
			printf("Bob\n");
			continue;
		}
		
		if (K % 3 == 0)
		{
			int res = N % (K + 1);
			if (res % 3 == 0 && res != K)
			{
				printf("Bob\n");
			}
			else
			{
				printf("Alice\n");
			}
		}
		else
		{
			if (N % 3 != 0)
			{
				printf("Alice\n");
			}
			else
			{
				printf("Bob\n");
			}
		}
		
		
	}
	
}
