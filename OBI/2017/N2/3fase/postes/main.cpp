#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
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
	int a = 0, b = 0;
	for (int i = 0; i < N; i++)
	{
		int v;
		scanf("%d", &v);
		if (v < 50)
		{
			++a;
		}
		else if (v >= 50 && v < 85)
		{
			++b;
		}
	}
	
	printf("%d %d\n", a, b);
	
}
