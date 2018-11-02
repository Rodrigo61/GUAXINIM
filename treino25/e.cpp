#include<bits/stdc++.h>

using namespace std;

#define MAXN (int)1e5+5
#define db(x) cerr << #x << " = " << x << endl;

int main()
{
	string in;
	cin >> in;
	
	int c = 0;
	
	for (int i = 0; i < (int)in.size() - 1; i++)
	{
		c ^= in[i] - '0';
	}
	
	if (c == in.back() - '0')
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	
	
	
	return 0;
}
