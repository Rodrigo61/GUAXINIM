#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
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
	
	if (n == 3)
	{
		printf("WBW\nBBB\nWBW\n");
	}
	else
	{
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((i + j) % 2)
					printf("B");
				else
					printf("W");
			}
			printf("\n");
		}
		
	}
}
