#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 112345

int N, M;
int vals[MAXN];
int p[MAXN];
int m[MAXN];

int update_p(int u, int v)
{
	if (p[u] == 0)
	{
		m[u] = vals[u];
		m[v] = min(m[v], m[u]);
		return u;
	}
		
	m[u] = min(m[u], vals[u]);
	p[u] = update_p(p[u], u);
	m[v] = min(m[v], m[u]);
	
	return p[u];
}

void join(int u, int v)
{
	p[v] = u;
}

int main()
{
	scanf("%d%d\n", &N, &M);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	memset(m, INF, sizeof(m));
	
	for (int i = 0; i < M; i++)
	{
		char c;
		scanf(" %c", &c);
		if (c == '?')
		{
			int u;
			scanf("%d", &u);
			update_p(u, u);
			printf("%d\n", m[u]);
		}
		else
		{
			int u, v;
			scanf("%d%d", &u, &v);
			join(u, v);
		}
	}
}
