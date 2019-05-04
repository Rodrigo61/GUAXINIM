#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

#define MAXN 112
#define db(x) cerr << #x <<  " = " << x << endl;
#define pb push_back
#define se second
#define fi first

int N, M;
char mapa[MAXN][MAXN];
pii NULL_PAIR = {-1, -1};

bool valid(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < M && mapa[i][j] == 'H';
}

pii get_neigh(pii pos)
{
	if (valid(pos.fi - 1, pos.se))
	{
		return {pos.fi - 1, pos.se};
	}
	if (valid(pos.fi + 1, pos.se))
	{
		return {pos.fi + 1, pos.se};
	}
	if (valid(pos.fi, pos.se - 1))
	{
		return {pos.fi, pos.se - 1};
	}
	if (valid(pos.fi, pos.se + 1))
	{
		return {pos.fi, pos.se + 1};
	}
	
	return NULL_PAIR;
}

int main()
{
	scanf("%d%d\n", &N, &M);
	
	pii pos;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &mapa[i][j]);
			
			if (mapa[i][j] == 'o')
			{
				pos = {i, j};
			}
		}
		scanf("\n");
	}
	
	while (true)
	{
		auto neigh = get_neigh(pos);
		mapa[pos.fi][pos.se] = 'w';
		
		if (neigh == NULL_PAIR)
		{
			break;
		}
		pos = neigh;
	}
	
	printf("%d %d\n", pos.fi + 1, pos.se + 1);

	return 0;
}
