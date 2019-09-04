#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

int main()
{
	int N;
	scanf("%d", &N);
	vector<pair<pii, int>> vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &vals[i].fi.fi, &vals[i].fi.se);
		vals[i].se = i;
	}
	int res = max_element(all(vals), [](pair<pii, int> &a, pair<pii, int> &b)
	{
		return (double)log(a.fi.fi) * a.fi.se < log(b.fi.fi) * b.fi.se;
	})->se;
	printf("%d\n", res);
}
