#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) cerr << #x << " = " << x << endl
#define ll long long

int main()
{
	int N;
	
	while (scanf("%d", &N), N)
	{
		int c = 0;
		for (int s = 1; s <= N; s++)
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					if (i + s - 1 <= N && j + s - 1 <= N)
					{

						c++;
					}
				}
			}
		}
		
		printf("%d\n", c);
	}
}
