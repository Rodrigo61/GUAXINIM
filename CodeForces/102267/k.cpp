#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#define MAXN 2123456

int vals[MAXN];
int N;
ll res;

void solve(int idx, ll total)
{
	if (idx == N)
	{
		res += total;
		return;
	}

	solve(idx + 1, total);
	solve(idx + 1, total | vals[idx]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	solve(0, 0);
	printf("%lld\n", res);
	
}
