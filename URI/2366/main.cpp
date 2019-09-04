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
	int N, M;
	scanf("%d%d", &N, &M);
	int last;
	scanf("%d", &last);
	for (int i = 0; i < N - 1; i++)
	{
		int v;
		scanf("%d", &v);
		if (v - last > M)
		{
			return !printf("N\n");
		}
		last = v;
	}
	
	if (42195 - last > M)
	{
		printf("N\n");
	}
	else
	{
		printf("S\n");
	}
	
	
	
}
