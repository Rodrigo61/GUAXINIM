#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define mp make_pair

int main()
{
	int N;
	int i1, j1, i2, j2;
	scanf("%d%d%d%d%d", &N, &i1, &j1, &i2, &j2);
	
	//linha
	pii cima = min(mp(i1, j1), mp(i2, j2));
	pii baixo = max(mp(i1, j1), mp(i2, j2));
	if (cima.fi <= N / 2 && baixo.fi > N / 2)
	{
		return !printf("S\n");
	}
	
	//coluna
	pii esq = min(mp(j1, i1), mp(j2, i2));
	pii dir = max(mp(j1, i1), mp(j2, i2));
	if (esq.fi <= N / 2 && dir.fi > N / 2)
	{
		return !printf("S\n");
	}
	
	printf("N\n");
}
