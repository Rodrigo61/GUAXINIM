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
	vi vals(4);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			int val = 0;
			for (int k = 0; k < 4; k++)
			{
				if (k != i && k != j)
					val += vals[k];
			}
			
			if (i != j && val == vals[i] + vals[j])
			{
				return !printf("YES\n");
			}
			
			if (i == j && val == vals[i])
			{
				return !printf("YES\n");
			}
		}
	}
	
	printf("NO\n");
}
