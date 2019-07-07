#include <bits/stdc++.h>

using namespace std;

int freq[1123456];
int C;

int main()
{
	scanf("%d", &C);
	int total = 0;
	for (int i = 0; i < C; i++)
	{
		int val;
		scanf("%d", &val);
		if (freq[val])
		{
			--freq[val];
		}
		else
		{
			total += 2;
			freq[val] = 1;
		}
	}
	
	printf("%d\n", total);
	
}
