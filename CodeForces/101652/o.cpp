#include "bits/stdc++.h"

using namespace std;

#define MAXN 100
#define db(x) //cerr << #x << " = " << x << endl;

char grid[MAXN][MAXN];
int vis[MAXN];
int N;

int val(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	
	return c - 'A' + 10;	
}

bool row(int r)
{
	memset(vis, 0, sizeof(vis));
	
	for (int i = 0; i < N; i++)
	{
		if (vis[val(grid[r][i])])
		{
			return false;
		}
		vis[val(grid[r][i])] = 1;
	}
	
	return true;
}

bool col(int c)
{
	memset(vis, 0, sizeof(vis));
	
	for (int i = 0; i < N; i++)
	{
		if (vis[val(grid[i][c])])
		{
			return false;
		}
		vis[val(grid[i][c])] = 1;
	}
	
	return true;
}



int main()
{
	while (scanf("%d\n", &N) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		int diff = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%c", &grid[i][j]);
				
				if (vis[val(grid[i][j])] == 0)
				{
					++diff;
				}
				vis[val(grid[i][j])] = 1;
			}
			scanf("\n");
		}
		
		if (diff != N)
		{
			printf("No\n");
			continue;
		}
		
		
		bool no = false;
		for (int i = 0; i < N; i++)
		{
			if (!row(i))
			{
				printf("No\n");
				no = true;
				break;
			}
			if (!col(i))
			{
				no = true;
				printf("No\n");
				break;
			}
		}
		
		if (no)
		{
			continue;
		}
		
		
		int last_r = val(grid[0][0]);
		int last_c = last_r;
		bool notreduced = false;
		for (int i = 1; i < N; i++)
		{
			if (val(grid[0][i]) <= last_r)
			{
				notreduced = true;
				printf("Not Reduced\n");
				break;
			}
			
			if (val(grid[i][0]) <= last_c)
			{
				notreduced = true;
				printf("Not Reduced\n");
				break;
			}
			
			last_r = val(grid[0][i]);
			last_c = val(grid[i][0]);
		}
		
		if (notreduced)
		{
			continue;
		}
		
		printf("Reduced\n");
	}
	
	return 0;
}
