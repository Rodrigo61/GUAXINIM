// piramide
#include <bits/stdc++.h>

using namespace std;

#define MAXN 112
#define INF 0x3f3f3f3f

int N;
int grid[MAXN][MAXN];

int get_col_sum(int i, int j)
{
	int total = 0;
	for (int it = i; it < N; it++)
	{
		total += grid[it][j];
	}
	return total;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}
	
	
	// seleciona a primeira linha
	int mini = INF;
	int left = -1, right = -1;
	for (int j = 0; j < N; j++)
	{
		int col_sum = get_col_sum(0, j);
		if (col_sum < mini)
		{
			mini = col_sum;
			left = right = j;
		}
	}
	
	// Restante das linhas
	int total = mini;
	for (int i = 1; i < N; i++)
	{
		int left_col = left > 0 ? get_col_sum(i, left - 1):INF;
		int right_col = right < N ? get_col_sum(i, right + 1):INF;
		
		if (left_col < right_col)
		{
			--left;
			total += left_col;
		}
		else
		{
			++right;
			total += right_col;
		}
	}
	
	
	printf("%d\n", total);
}
