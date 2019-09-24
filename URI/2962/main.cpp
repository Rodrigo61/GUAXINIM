#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long

#define MAXK 1123

int vis[MAXK];
vi adj[MAXK];
int n, m, k;
struct circle { ll x, y, s; };
circle circles[MAXK];

bool dfs(int u)
{
	vis[u] = 1;
	
	if (circles[u].x + circles[u].s >= m)
		return true;
	if (circles[u].y - circles[u].s <= 0)
		return true;
	
	bool res = false;
	for (int v : adj[u])
		if (!vis[v])
			res |= dfs(v);
	
	return res;
}

ll dist(circle a, circle b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
	scanf("%d%d%d", &m, &n, &k);
	
	for (int i = 0; i < k; i++)
	{
		scanf("%lld%lld%lld", &circles[i].x, &circles[i].y, &circles[i].s);
	}
	
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (dist(circles[i], circles[j]) <= (circles[i].s + circles[j].s) * (circles[i].s + circles[j].s))
			{
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		if (vis[i]) continue;
		if (circles[i].x - circles[i].s <= 0)
		{
			// B
			if (dfs(i))
				return !printf("N\n");
		}
		if (circles[i].y + circles[i].s >= n)
		{
			// C
			if (dfs(i))
				return !printf("N\n");
		}
	}
	
	return !printf("S\n");
	
}
