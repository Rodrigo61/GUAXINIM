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

#define MAXN 1123456 

int hole[MAXN];
 
int main()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++)
	{
		int v;
		scanf("%d", &v);
		hole[v] = 1;
	}
	
	int bone = 1;
	for (int i = 0; i < K; i++)
	{
		if (hole[bone])
		{
			return !printf("%d\n", bone);
		}
		
		int a, b;
		scanf("%d%d", &a, &b);
	
		if (bone == a)
		{
			bone = b;
		}
		else if (bone == b)
		{
			bone = a;
		}
	}
	
	printf("%d\n", bone);
	
	
}
