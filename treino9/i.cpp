#include<bits/stdc++.h>

using namespace std;


main()
{
	int N;
	scanf("%d", &N);
	if(N == 1)
		return !printf("no\n");
	for(int i = 2; i*i <= N; i++)
	{
		if(N%i == 0)
		{
			while(N%i == 0)
			{
				N /= i;
			}
			if(N != 1)
				return !printf("no\n");
		}
	}
	printf("yes\n");
	return 0;
}
