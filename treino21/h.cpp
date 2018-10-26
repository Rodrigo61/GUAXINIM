#include<bits/stdc++.h>

using namespace std;

char str[1000001];

main()
{
	int T, N, S;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &S);
		if(S > 9*N)
			printf("-1\n");
		else
		{
			for(int i = 0; i < N/2; i++)
			{
				if(S >= 18)
				{
					str[i] = str[N-1-i] = '9';
					S -= 18;
				}
				else
				{
					str[i] = str[N-1-i] = '0'+S/2;
					S -= 2*(S/2);
				}
			}
			if(N&1)
			{
				str[N/2] = '0'+S;
				S = 0;
			}
			if(S || str[0] == '0')
			{
				printf("-1\n");
				continue;
			}
			str[N] = 0;
			printf("%s\n", str);
		}
	}
	return 0;
}
