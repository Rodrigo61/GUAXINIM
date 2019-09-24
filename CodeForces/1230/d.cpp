#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MAXN 7123

vi in_d[MAXN];
int out_d[MAXN];
int nogo[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	vector<pll> inp(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &inp[i].fi);
		
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &inp[i].se);
	}
	
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i) continue;	
			
			if (((inp[i].fi ^ inp[j].fi) & inp[i].fi) == 0)
			{
				in_d[j].pb(i);
				out_d[i]++;
			}
			
		}
		
		if (out_d[i] == 0)
		{
			q.push(i);
		}
	}
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		nogo[u] = 1;
		
		for (auto v : in_d[u])
		{
			out_d[v]--;
			if (out_d[v] == 0)
			{
				q.push(v);
			}
		}
	}
	
	ll res = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (nogo[i] == 0)
		{
			db(i);
			count++;
			res += inp[i].se;
		}
	}
	
	if (count < 2)
	{
		res = 0;
	}
	
	
	printf("%lld\n", res);	
	
}
