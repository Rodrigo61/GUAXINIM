#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
int main()
{
	int N, C;
	scanf("%d%d", &N, &C);
	vi freq(1000);
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int v;
		scanf("%d", &v);
		if (!freq[v]) ++cnt;
		freq[v]++;
	}
	
	int dishes = ceil((double)(*max_element(all(freq)))/C);
	
	printf("%d\n", cnt*dishes*C - N);
	
}
