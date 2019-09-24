#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

int main()
{
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		int n, x;
		scanf("%d%d", &n, &x);
		int std_blow = -INF;
		int final_blow = -INF;
		for (int i = 0; i < n; i++)
		{
			int d, h;
			scanf("%d%d", &d, &h);
			std_blow = max(std_blow, d - h);
			final_blow = max(final_blow, d);
		}
		
		if (std_blow <= 0 && final_blow < x)
		{
			printf("-1\n");
		}
		else
		{
			int res = 1;
			x -= final_blow;
			if (x > 0)
			{
				res += x / std_blow;
				if (x % std_blow != 0)
					++res;
			}
			printf("%d\n", res);
		}
		
	}
}
