#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define vll vector<ll>

int N;

int main()
{
	scanf("%d", &N);
	vi degree(N);
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		degree[u]++;
		degree[v]++;
	}
	
	if (find(all(degree), 2) != degree.end())
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	
	
	
}
