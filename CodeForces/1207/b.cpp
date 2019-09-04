#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

int N, M;
int s[55][55];
int t[55][55];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	
	vii res;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (s[i][j] == 1 &&
			   (i + 1 < N && s[i + 1][j] == 1) &&
			   (j + 1 < M && s[i][j + 1] == 1) &&
			   (i + 1 < N && j + 1 < M && s[i + 1][j + 1] == 1))
			   {
				    res.pb({i, j});
					t[i][j] = 1;
					t[i + 1][j] = 1;
					t[i][j + 1] = 1;
					t[i + 1][j + 1] = 1;				   
			   }
		}
	}
	
	bool poss = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (s[i][j] != t[i][j])
			{
				poss = false;
			}
		}
	}
		
	if (poss)
	{
		printf("%d\n", (int)res.size());
		for (auto p : res)
			printf("%d %d\n", p.fi + 1, p.se + 1);
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	
	
}
