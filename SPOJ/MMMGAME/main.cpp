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
		int N;
		scanf("%d", &N);
		int xr = 0;
		int diff_one = false;
		for (int i = 0; i < N; i++)
		{
			int v;
			scanf("%d", &v);
			xr ^= v;
			if (v != 1) diff_one = true;
		}
		
		if (diff_one)
		{
			if (xr != 0)
			{
				printf("John\n");
			}
			else
			{
				printf("Brother\n");
			}
		}
		else
		{
			if (xr != 0)
			{
				printf("Brother\n");
			}
			else
			{
				printf("John\n");
			}
		}
	}
	
}
