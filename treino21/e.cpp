#include<bits/stdc++.h>

using namespace std;

main()
{
	int N, a, b;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b-1);
	}
	return 0;
}
