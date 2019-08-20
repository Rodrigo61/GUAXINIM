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
	ll H, L;
	scanf("%lld%lld", &H, &L);
	printf("%.20lf\n", ((double)(L*L - H*H))/(2*H));
}
