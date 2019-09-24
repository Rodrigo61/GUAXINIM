#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

int main()
{
	int n, k;
	cin >> n >> k;
	string num;
	cin >> num;
	
	if (n == 1)
	{
		if (k == 1)
			num = "0";
		cout << num << endl;
		return 0;
	}
		
	
	for (int i = 0; k && i < n; i++)
	{
		if (i == 0)
		{
			if (num[0] != '1')
			{
				num[0] = '1';
				k--;
			}
		}
		else
		{
			if (num[i] != '0')
			{
				num[i] = '0';
				k--;
			}
		}
	}
	
	cout << num << endl;
	
}
