#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
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
	vi vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	sort(all(vals));
	
	int res = 2;
	int acu = vals[0] + vals[1];
	for (int i = 2; i < N; i++)
	{
		if (vals[i] < acu)
		{
			res = i + 1;
		}
		acu += vals[i];
	}
	
	printf("%d\n", res >= 3 ? res:0);
}
