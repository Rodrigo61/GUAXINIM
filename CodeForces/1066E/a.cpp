#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		int L, v, l, r;
		scanf("%d%d%d%d", &L, &v, &l, &r);
		int total = L / v - (r / v - (l - 1) / v);
		printf("%d\n", total);
	}
	
	return 0;
}
