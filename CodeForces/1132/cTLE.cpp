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
#define LEFT(x) x+x+1
#define RIGHT(x) x+x+2

#define MAXN 5123

int N, Q; 
int BIT[MAXN];
int vals[MAXN];
pii painters[MAXN];

void update(int pos, int offset)
{
	int change = 0;
	if (vals[pos] == 0)
		change = 1;
	else if (vals[pos] + offset == 0)
		change = -1;
	vals[pos] += offset;
	
	while (pos < MAXN)
	{
		BIT[pos] += change;
		pos += pos & (-pos);
	}
}

void range_update(int L, int R, int offset)
{
	for (int i = L; i <= R; i++)
	{
		update(i, offset);
	}
}

int query(int pos)
{
	int res = 0;
	while (pos > 0)
	{
		res += BIT[pos];
		pos -= pos & (-pos);
	}
	return res;
}

int range_query(int L, int R)
{
	int range = query(R) - query(L - 1);
	return range;
}

int main()
{
	scanf("%d%d", &N, &Q);
	
	for (int i = 0; i < Q; i++)
	{
		scanf("%d%d", &painters[i].fi, &painters[i].se);
		range_update(painters[i].fi, painters[i].se, 1);
	}
	int res = 0;
	for (int i = 0; i < Q; i++)
	{
		for (int j = i + 1; j < Q; j++)
		{
			range_update(painters[i].fi, painters[i].se, -1);
			range_update(painters[j].fi, painters[j].se, -1);
			res = max(res, range_query(1, N));
			range_update(painters[i].fi, painters[i].se, 1);
			range_update(painters[j].fi, painters[j].se, 1);
		}
	}
	
	printf("%d\n", res);
	
}
