#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) cerr << #x << " = " << x << endl
#define ll long long
 
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		printf("Case %d: ", i + 1);
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (c % __gcd(a,b) == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	
}
