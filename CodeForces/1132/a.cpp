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
	vi v(4);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &v[i]);
	}
	
	if (v[0] == v[3] && v[0] != 0)
	{
		printf("1\n");
	}
	else if (v[0] == v[3] && v[2] == 0)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
	
}
