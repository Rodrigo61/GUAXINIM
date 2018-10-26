#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
#define MAXN 400010

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag,  
tree_order_statistics_node_update> OST;

int t, N;
OST bit[MAXN];

void insert(int x, int y)
{
	for(int i = x; i < MAXN; i += i&-i)
		bit[i].insert(ii(y, x));
}

void remove(int x, int y)
{
	for(int i = x; i < MAXN; i += i&-i)
		bit[i].erase(ii(y, x));
}

int query(int x, int y)
{
	int ans = 0;
	for(int i = x; i; i -= i & -i)
		ans += bit[i].order_of_key(ii(y+1, 0));
	return ans;
}

int query(int x, int y, bool b)
{
	return query(x, N) + query(N, y) - query(x, y);
}

pair<int, pair<int, int> > vet[MAXN];

int main()
{
	int T, x, ans;
	//printf("COMECOU\n");
	scanf("%d", &T);
	for(t = 0; t < T; t++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d %d %d", &vet[i].fi, &vet[i].se.fi, &vet[i].se.se);
		sort(vet, vet+N);
		ans = 0;
		//printf("Ok\n");
		for(int i = 0; i < N; i++)
		{
			x = query(vet[i].se.fi, vet[i].se.se);
			//printf("%d!\n", x);
			if(x == 0)
				ans++;
			insert(vet[i].se.fi, vet[i].se.se);
		}
		for(int i = 0; i < N; i++)
		{
			remove(vet[i].se.fi, vet[i].se.se);
		}
		printf("%d\n", ans);
	}
	return 0;
}
