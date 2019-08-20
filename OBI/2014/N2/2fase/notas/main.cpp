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
 
int freq[200];
 
int main()
{
	int N;
	int max_nota = 0;
	int max_freq = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int v;
		scanf("%d", &v);
		freq[v]++;
		if (freq[v] > max_freq)
		{
			max_freq = freq[v];
			max_nota = v;
		}
		else if (freq[v] == max_freq && v > max_nota)
		{
			max_freq = freq[v];
			max_nota = v;
		}
	}
	
	printf("%d\n", max_nota);
	
}
