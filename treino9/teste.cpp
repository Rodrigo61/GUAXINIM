#include<bits/stdc++.h>
#define MOD 123456789

using namespace std;

int pd[2501][2501];

main()
{
	pd[1][1] = 1;
	pd[1][2] = 2;
	pd[2][1] = 1;
	pd[2][2] = 3;
	pd[2][3] = 4;
	for(int i = 3; i <= 2500; i++)
	{
		pd[i][1] = 1;
		pd[i][2] = pd[i-1][3];
		for(int j = 3; j <= i; j++)
			pd[i][j] = (pd[i-1][j-1]+pd[i-1][j])%MOD;
		pd[i][i+1] = (pd[i-1][i]*2)%MOD;
	}
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= i; j++)
			printf("%d ", pd[i][j]);
		printf("\n");
	}
	printf("%d\n", pd[2500][2000]);
	return 0;
}
