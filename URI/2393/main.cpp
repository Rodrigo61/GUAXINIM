#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define MAXN 112

int grid[MAXN][MAXN];

int main()
{
	int N;
	scanf("%d", &N);
	for (int w = 0; w < N; w++)
	{
		int xi, xf, yi, yf;
		scanf("%d%d%d%d", &xi, &xf, &yi, &yf);
		
		for (int i = xi; i < xf; i++)
		{
			for (int j = yi; j < yf; j++)
			{
				grid[i][j] |= 1;
			}
		}
	}
	
	int total = 0;
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			total += grid[i][j];
		}
	}
	printf("%d\n", total);
	
}
