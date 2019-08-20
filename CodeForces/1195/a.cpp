#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	vi vet(K + 1);
	int res = 0;
	int use = (N+1)/2;
	for (int i = 0; i < N; i++)
	{
		int v;
		scanf("%d", &v);
		vet[v]++;
		if (use && vet[v] == 2)
		{
			res += 2;
			use--;
			vet[v] = 0;
		}
	}
	
	printf("%d\n", res + use);
	
}
