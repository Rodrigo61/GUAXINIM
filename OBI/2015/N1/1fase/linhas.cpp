#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
#define MAXN 61234

int BIT[MAXN];

void update(int pos, int val)
{
	while (pos < MAXN)
	{
		BIT[pos] += val;
		pos += pos&(-pos);
	}
}

int sum(int pos)
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
	int N;
	scanf("%d", &N);
	vector<int> vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	int total = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		total += sum(vals[i]);
		update(vals[i], 1);
	}
	
	printf("%d\n", total);
}
