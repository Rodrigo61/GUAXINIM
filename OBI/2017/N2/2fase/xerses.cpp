#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x <<  " = " << x << endl;

vector<vector<int>> lose2 = {{3, 4}, {4, 0}, {0, 1}, {1, 2}, {3, 2}};

int main()
{
	int N;
	scanf("%d", &N);
	
	int u, v;
	int xerxes = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &u, &v);
		if (find(lose2[v].begin(), lose2[v].end(), u) == lose2[v].end())
		{
			++xerxes;
		}
	}
	
	if (xerxes > N/2)
	{
		printf("xerxes\n");
	}
	else
	{
		printf("dario\n");
	}
	
	return 0;
}
