#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
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
	cout << "?";
	for (int i = 127; i > 27 ; i--)
	{
		cout << " " << i;
	}
	cout << endl;
	int res;
	cin >> res;
	res &= 16256;
	cout << "?";
	for (int i = 127; i > 27 ; i--)
	{
		cout << " " << (i << 7);
	}
	cout << endl;
	int res2;
	cin >> res2;
	res2 &= 127;
	cout << "! " << (res | res2) << endl;
}
