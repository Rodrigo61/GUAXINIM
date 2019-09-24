#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

int main()
{
	string s;
	cin >> s;
	vi first_a(255, INF);
	for (int i = 0; i < (int)s.size(); i++)
	{
		first_a[s[i]] = min(first_a[s[i]], i);
	}
	
	for (int i = 0; i < (int)s.size(); i++)
	{
		bool found = false;
		for (char j = 'a'; j < s[i]; j++)
		{
			if (first_a[j] < i)
			{
				found = true;
				break;
			}
		}
		
		if (found)
		{
			printf("Ann\n");
		}
		else
		{
			printf("Mike\n");
		}
	}
	
}
