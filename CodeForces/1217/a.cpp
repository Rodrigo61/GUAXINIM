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

#define MAXN 3123 

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int s, i, e;
		scanf("%d%d%d", &s, &i, &e);
		
		if (i >= s)
		{
			e -= (i - s) + 1;
			s = i + 1;
		}
		
		if (e < 0)
		{
			printf("%d\n", 0);
		}
		else
		{
			int k = min((s + e - i + 1)/2, e + 1);
			printf("%d\n", k);
		}
	}
	
}
