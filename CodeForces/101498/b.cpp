#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		string a, b;
		cin >> a >> b;
		
		int freq[255];
		memset(freq, 0, sizeof(freq));
		for (char c : b)
		{
			freq[c]++;
			db(freq[c]);
		}
		
		int total = 0;
		for (char c : a)
		{
			if (freq[c] == 0)
			{
				break;
			}
			freq[c]--;
			++total;
		}
		
		printf("%d\n", total);
	}
	
}
