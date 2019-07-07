#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

int main()
{
	int N, M;
	scanf("%d%d", &M, &N);
	vector<int> degree(N);
	
	int total = 0;
	for (int i = 0; i < M; i++)
	{
		int u, v, u2v;
		scanf("%d%d%d", &u,  &u2v, &v);
		
		degree[u] -= u2v;
		degree[v] += u2v;
		
		total += u2v;
	}
	
	int best = 0;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] > 0)
		{
			best += degree[i];
			db(degree[i]);
		}
	}
	
	if (total == best)
	{
		printf("N\n");
	}
	else
	{
		printf("S\n");
	}
	
	printf("%d\n", best);
}
