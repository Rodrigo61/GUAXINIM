#include<bits/stdc++.h>
#define MAXN 500001
using namespace std;

string V;

int SA[MAXN], LCP[MAXN], pos[MAXN], tmp[MAXN], val[MAXN];

int gap, N;

bool cmp(int i, int j)
{
	if (pos[i] != pos[j])
	{
		return pos[i] < pos[j];
	}
	
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
	
}

void buildSA()
{
	N = V.size();
	tmp[0] = 0;
	for (int i = 0; i < N; i++)
	{
		SA[i] = i, pos[i] = V[i];
	}
	
	for (gap = 1;; gap *= 2)
	{
		sort(SA, SA + N, cmp);
		
		for (int i = 0; i < N - 1; i++)
		{
			tmp[i + 1] = tmp[i] + cmp(SA[i], SA[i + 1]);
		}
		for (int i = 0; i < N; i++)
		{
			pos[SA[i]] = tmp[i];
		}
		
		if (tmp[N - 1] == N - 1)
		{
			break;
		}
	}
}

void buildLCP()
{
	for (int i = 0, k = 0; i < N; i++)
	{
		if (pos[i] != N - 1)
		{
			int j = SA[pos[i] + 1];
			
			while (V[i + k] == V[j + k])
			{
				k++;
			}
			
			LCP[pos[i]] = k;
			if (k) k--;
		}
		
	}
	
	LCP[N-1] = 0;
}

int comp(int x, int y)
{
	for(int i = 0; i < N; i++)
	{
		if(V[x] != V[y])
			return 0;
		x++, y++;
		if(x >= N)
			x -= N;
		if(y >= N)
			y -= N;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N;
	cin >> V;
	if(N == 1)
		return !printf("Yes\n");
	buildSA();
	buildLCP();
	for(int i = 0; i < N; i++)
		val[SA[i]] = i;
	//for(int i = 0; i < N; i++)
		//printf("%d\n", SA[i]);
	printf("%s\n", (val[0] == 0) || comp(SA[0], 0) ? "Yes" : "No");
	return 0;
}

