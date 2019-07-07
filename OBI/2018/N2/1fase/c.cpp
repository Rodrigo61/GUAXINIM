#include <bits/stdc++.h>

using namespace std;


int main()
{
	int L, C;
	scanf("%d%d", &L, &C);
	
	int Lu = 2 * (L - 1);
	int Cu = 2 * (C - 1);
	
	printf("%d\n", L * C + (L-1)*(C-1));
	
	printf("%d\n", Lu + Cu);
	
}
