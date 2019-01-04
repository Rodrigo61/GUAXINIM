#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 10005

int N, R;
int heaters[MAXN];

int get_next(int it)
{
	int ma = -1;
	for (int i = 0; i < R; i++)
	{
		if (it - i >= 0 && heaters[it - i])
		{
			ma = it - i;
			break;
		}
	}
	for (int i = 0; i < R; i++)
	{
		if (it + 1 < N && heaters[it + i])
		{
			ma = it + i;
		}
	}
	
	if (ma == -1)
	{
		return -2;
	}
	
	if (ma + R >= N)
	{
		return -1;
	}
	
	return ma + R;
	
}

int main()
{

	scanf("%d%d", &N, &R);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &heaters[i]);
	}
	
	int it = 0;
	int total = 0;
	while (it != -1 && it != -2)
	{
		db(it);
		it = get_next(it);
		db(it);
		++total;
		db(total);
	}
	
	if (it == -1)
	{
		printf("%d\n", total);
	}
	else
	{
		printf("%d\n", -1);
	}
	
	
	
	
}
