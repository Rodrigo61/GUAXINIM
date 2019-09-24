#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

int main()
{
	int n;
	scanf("%d", &n);
	ll mat[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%lld", &mat[i][j]);
		}
	}
	
	vi common_divs;
	for (int i = 1; i * i <= mat[0][1]; i++)
	{
		if (mat[0][1] % i == 0)
		{
			common_divs.pb(i);
			if (mat[0][1]/i != i)
				common_divs.pb(mat[0][1]/i);
		}
	}
	
	for (int div : common_divs)
	{
		vll vals(n);
		vals[0] = div;
		bool poss = true;
		
		for (int i = 1; i < n; i++)
		{
			if (mat[i][0] % div)
				poss = false;
				
			vals[i] = mat[i][0] / div;
		}
		
		
		for (int i = 1; poss && i < n; i++)
		{
			for (int j = i + 1; poss && j < n; j++)
			{
				if (mat[i][j] != vals[i] * vals[j])
					poss = false;
			}
		}
		
		if (poss)
		{
			for (auto v : vals)
			{
				printf("%lld ", v);
			}
			return 0;
		}
	}
	
	
}
