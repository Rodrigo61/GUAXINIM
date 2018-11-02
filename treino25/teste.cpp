#include<bits/stdc++.h>

using namespace std;

main()
{
	int sum = 0, pot = 2;
	for(int i = 2; i <= 7; i++)
	{
		pot = 2*pot;
		sum += pot*(i-1);
		printf("%d\n", sum/4);
	}
	
	return 0;
}
