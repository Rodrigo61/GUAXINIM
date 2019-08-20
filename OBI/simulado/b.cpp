#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 1123

ll mat[MAXN][MAXN];
ll acu[MAXN][MAXN];
int N, M;

void calc()
{
	ll a = 0;
	for (int i = 0; i < N; i++)
	{
		a += mat[i][0];
		acu[i][0] = a;
	}
	a = 0;
	for (int i = 0; i < M; i++)
	{
		a += mat[0][i];
		acu[0][i] = a;
	}
	
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			acu[i][j] = mat[i][j] + acu[i - 1][j] + acu[i][j - 1] - acu[i - 1][j - 1];
		}
	}
	
}

ll query(int i1, int j1, int i2, int j2)
{
	ll res = acu[i2][j2];
	if (i1 - 1 >= 0)
		res -= acu[i1 - 1][j2];
	if (j1 - 1 >= 0)
		res -= acu[i2][j1 - 1];
	if (i1 - 1 >= 0 && j1 - 1 >= 0)
		res += acu[i1 - 1][j1 - 1];
		
	return res;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%lld", &mat[i][j]);
		}
	}
	
	calc();
	
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		int i1, j1, i2, j2;
		scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
		--i1;
		--i2;
		--j1;
		--j2;
		
		printf("%lld\n", query(i1, j1, i2, j2));
	}
	
	
}

