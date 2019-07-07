#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
#define piii pair<int, pair<int, int>>
#define fi first
#define se second.first
#define th second.second
#define pb push_back
#define MAXN 112


int N, K;
piii tips[MAXN];

bool check_pos(int x, int y)
{
	for (int i = 0; i < K; i++)
	{
		if (abs(x - tips[i].fi) + abs(y - tips[i].se) != tips[i].th)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		tips[i].fi = x;
		tips[i].se = y;
		tips[i].th = d;
	}
	
	bool found = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check_pos(i, j))
			{
				if (found)
				{
					return !printf("-1 -1\n");
				}
				found = true;
			}
		}
	}
	
	if (!found)
	{
		return !printf("-1 -1\n");
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check_pos(i, j))
			{
				printf("%d %d\n", i, j);
			}
		}
	}
	
}
