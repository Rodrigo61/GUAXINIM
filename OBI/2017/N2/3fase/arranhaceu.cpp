#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 112345

int N, Q;
int BIT[MAXN];
int vals[MAXN];

void update(int pos, int val)
{
	while (pos <= N)
	{
		BIT[pos] += val;
		pos += pos&(-pos);
	}
}

int value(int pos)
{
	int res = 0;
	while (pos > 0)
	{
		res += BIT[pos];
		pos -= pos&(-pos);
	}
	return res;
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &vals[i]);
		update(i, vals[i]);
	}
	
	for (int i = 0; i < Q; i++)
	{
		int t;
		scanf("%d", &t);
		
		if (t == 0)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			update(a, -vals[a]);
			update(a, b);
			vals[a] = b;
		}
		else
		{
			int a;
			scanf("%d", &a);
			printf("%d\n", value(a));
		}
	}
	
	
}
