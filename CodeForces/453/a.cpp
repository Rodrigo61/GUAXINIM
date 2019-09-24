#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define pll pair<ll, ll>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	double res = 0;
	for (int i = 1; i <= N; i++)
	{
		res += i * (pow(i/(double)N, M) - pow((i - 1)/(double)N, M));
	}
	printf("%lf", res);
}
