#include<bits/stdc++.h>

using namespace std;

int t;
int pd[451][451];
int vis[451][451];

char str[451];

vector<int> values;
int K;

int custo2(int x)
{
	return (x*(x+1))/2;
}

int custo(int x, int y)
{
	//printf("valores: %d %d\n", x, y);
	int z = (x-y)/(y+1), w = (x-y)%(y+1);
	//printf("custos: %d %d -> %d\n", z, w, w*custo2(z+1) + (y+1-w)*custo2(z));
	return w*custo2(z+1) + (y+1-w)*custo2(z);
}

int solve(int x, int y)
{
	if(x == (int)values.size())
		return 0;
	if(vis[x][y] == t)
		return pd[x][y];
	vis[x][y] = t;
	int r = 1001001001LL;
	for(int i = 0; i <= values[x]; i++)
	{
		if(i <= y)
			r = min(r, solve(x+1, y-i)+custo(values[x], i));
	}
	return pd[x][y] = r;
}

int busca(int hi)
{
	int lo = 0, mid, ans;
	while(lo <= hi)
	{
		mid = (lo+hi)/2;
		t++;
		int x = solve(0, mid);
		//printf("%d -> %d\n", mid, x);
		if(x <= K)
		{
			ans = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	return ans;
}

int main()
{

	int N, cnt = 0, acum = 0;
	scanf("%d %d", &N, &K);
	scanf("%s", str);
	for(int i = 0; i < N; i++)
	{
		if(str[i] == '0')
		{
			if(cnt != 0)
			{
				values.push_back(cnt);
				acum += cnt;
			}
			cnt = 0;
		}
		else
			++cnt;
	}
	if(cnt != 0)
	{
		acum += cnt;
		values.push_back(cnt);
	}
	printf("%d\n", busca(acum));
	return 0;
}
