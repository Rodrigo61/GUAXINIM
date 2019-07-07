#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 2123

int hp, wp, hm, wm;

int main()
{
	
	scanf("%d%d%d%d\n", &hp, &wp, &hm, &wm);
	char c;
	
	vector<bitset<2005>> target(hp);
	for (int i = 0; i < hp; i++)
	{
		for (int j = 0; j < wp; j++)
		{
			scanf("%c", &c);
			
			target[i][j] = c == 'x';
		}
		scanf("\n");
	}
	
	int i = 0, j = -1;
	int m = hp;
	vector<int> lps(m + 1);
	lps[0] = -1;
	while(i < m)
	{
		while(j >= 0 && (target[i] != target[j])) 
			j = lps[j];
		i++, j++;
		lps[i] = j;
	}
	
	vector<vector<int>> grid(hm);
	for (int i = 0; i < hm; i++)
	{
		grid[i].resize(wm);
		for (int j = 0; j < wm; j++)
		{
			scanf("%c", &c);
			
			grid[i][j] = c == 'x';
		}
		scanf("\n");
	}
	
	vector<vector<bitset<2005>>> grid_bit(hm);
	for (int i = 0; i < hm; i++)
	{
		grid_bit[i].resize(wm);
		bitset<2005> bs;
		for (int j = 0; j < wp; j++)
		{
			bs[j] = grid[i][j];
		}
		grid_bit[i][0] = bs;
		
		for (int j = wp; j < wm; j++)
		{
			bs = bs >> 1;
			bs[wp-1] = grid[i][j];
			grid_bit[i][j - wp + 1] = bs;
		}
	}
	
	int total = 0;
	for (int j = 0; j + wp <= wm; j++)
	{
		int t = 0;
		for (int i = 0; i < hm; i++)
		{
			
			while (t == hp || (t >=0 && grid_bit[i][j] != target[t]))
			{
				t = lps[t];
			}
			
			if (t == hp - 1)
			{
				++total;
			}
			
			++t;
		}
	}
	
	printf("%d\n", total);
	
	return 0;
}
