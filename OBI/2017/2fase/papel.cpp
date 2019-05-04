#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define db(x) cerr << #x <<  " = " << x << endl;
#define MAXN 112345
#define fi first
#define se second

int N;
set<pii> heights;
int intervals[MAXN];

int l(int i)
{
	return i == 0 ? i:i-1;
}

int r(int i)
{
	return i == N - 1 ? i:i+1;
}

int main()
{
	scanf("%d", &N);
	int h;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &h);
		heights.insert({-h, i});
	}
	
	int total = 0;
	int maxi = 0;
	for (pii p : heights)
	{
		h = -p.fi;
		int i = p.se;
		
		if (intervals[l(i)] && intervals[r(i)])
		{
			total--;
		}
		else if (!intervals[l(i)] && !intervals[r(i)])
		{
			total++;
		}
		intervals[i] = 1;
		maxi = max(maxi, total);
	}
	
	printf("%d\n", maxi + 1);
	return 0;
}
