#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

int freq[255];

int main()
{
	int n;
	string str;
	cin >> n >> str;
	for (char c : str)
	{
		freq[c]++;
	}
	
	int used = 0;
	while (used < n)
	{
		if (freq['o'] && freq['n'] && freq['e'])
		{
			printf("1 ");
			freq['o']--;
			freq['n']--;
			freq['e']--;
			used += 3;
		}
		else
		{
			printf("0 ");
			freq['z']--;
			freq['e']--;
			freq['r']--;
			freq['o']--;
			used += 4;
		}
	}
}
