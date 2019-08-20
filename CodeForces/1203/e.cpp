#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 151234

int N;
int vals[MAXN];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	sort(vals, vals + N);
	
	set<int> r;
	for (int i = 0; i < N; i++)
	{
		if (r.find(vals[i] - 1) == r.end() && vals[i] > 1)
		{
			r.insert(vals[i] - 1);
		}
		else if (r.find(vals[i]) == r.end())
		{
			r.insert(vals[i]);
		}
		else
		{
			r.insert(vals[i] + 1);
		}
	}
	
	
	printf("%d\n", (int)r.size());
	
}
