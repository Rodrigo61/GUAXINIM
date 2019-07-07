#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;


int main()
{
	int N, y, x;
	scanf("%d%d%d", &N, &y, &x);
	
	string s;
	cin >> s;
	
	reverse(s.begin(), s.end());
	int total = 0;
	if (s[x] == '0')
	{
		++total;
	}
	
	if (s[y] == '0')
	{
		++total;
	}
	
	for (int i = 0; i < y; i++)
	{
		if (i != x && s[i] == '1')
		{
			++total;
		}
	}
	
	printf("%d\n", total);
}
