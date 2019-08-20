#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

pii NULL_PAIR = {-1, -1};

int main()
{
	int N;
	scanf("%d", &N);
	vi vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	int Q;
	scanf("%d", &Q);
	vii type2;
	vii type1(N, NULL_PAIR);
	
	for (int i = 0; i < Q; i++)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			int p, x;
			scanf("%d%d", &p, &x);
			--p;
			type1[p] = {i, x};
		}
		else
		{
			int x;
			scanf("%d", &x);
			type2.pb({i, x});
		}
	}
	
	int best = 0;
	int it2 = type2.size() - 1;
	vi best_vet(Q);
	for (int i = Q - 1; i >= 0; i--)
	{
		if (it2 >= 0 && i == type2[it2].fi)
		{
			best = max(best, type2[it2].se);
			--it2;
		}
		best_vet[i] = best;
	}
	
	for (int i = 0; i < N; i++)
	{
		pii u = type1[i];
		if (u == NULL_PAIR)
		{
			printf("%d ", max(vals[i], best_vet[0]));
		}
		else
		{
			printf("%d ", max(u.se, best_vet[u.fi]));
		}
	}
	
}
