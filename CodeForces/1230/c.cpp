#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cout << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MAXN 10

vector<pii> edges;
vector<vi> possib;
int n, m;



void calc(vi curr, int idx)
{
	if (idx == n)
	{
		possib.pb(curr);
		return;
	}
	
	for (int i = 1; i <= 6; i++)
	{
		curr.pb(i);
		calc(curr, idx + 1);
		curr.pop_back();
	}
}

void print_vet(vi &v)
{
	for (int a : v)
		printf("%d ", a);
	printf("\n");
}

int main()
{
	scanf("%d%d", &n, &m);
	db(n);
	db(m);
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edges.pb({u, v});
	}
	
	vi aux;
	calc(aux, 0);
	
	int maxi = 0;
	for (auto &v : possib)
	{
		int count[7][7];
		memset(count, 0, sizeof(count));
		
		print_vet(v);
		
		for (auto e : edges)
		{
			count[max(v[e.fi], v[e.se])][min(v[e.fi], v[e.se])]++;
		}
		
		int local = 0;
		for (int i = 1; i <= 6; i++)
		{
			for (int j = i; j <= 6; j++)
			{
				if (count[j][i])
				{
					local++;
				}
			}
		}
		
		maxi = max(maxi, local);
	}
	
	printf("%d\n", maxi);
}
