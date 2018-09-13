#include<bits/stdc++.h>

using namespace std;

main()
{
	int N, x, y;
	char op[5];
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d %s %d", &x, op, &y);
		if(op[0] == 'o')
		{
			printf("%d\n", y*2);
		}
		else
		{
			printf("%d\n", y*2-1);
		}
	}
	return 0;
}
