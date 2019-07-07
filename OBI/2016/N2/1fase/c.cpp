#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345

int main()
{
	int Ia, Ib, Fa, Fb;
	scanf("%d%d%d%d", &Ia, &Ib, &Fa, &Fb);
	
	int total = 0;
	
	if (Ib != Fb)
	{
		total++;
		Ia = !Ia;
	}
	
	if (Ia != Fa)
	{
		total++;
	}
	
	printf("%d\n", total);
}
