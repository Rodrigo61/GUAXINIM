#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c, d, e;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		
		if (d > e)
		{
			int c_b = min(a/2, b); 
			int r_a = a - 2*c_b;
			int c_c = min(r_a/2, c);
			
			printf("%d\n", c_b * d + c_c * e);
		}
		else
		{
			int c_c = min(a/2, c); 
			int r_a = a - 2*c_c;
			int c_b = min(r_a/2, b);
			
			printf("%d\n", c_b * d + c_c * e);
		
		}
		
		
		
	}
	
}
