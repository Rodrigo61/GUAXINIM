#include<bits/stdc++.h>
#define ll long long
using namespace std;

char str[100001];

int acum[100001];

main()
{
	int N, M;
	ll ans = 0;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%s", str);
		M = strlen(str);
		for(int i = 0; i < M; i++)
			acum[i+1] = acum[i] + (str[i] == 'L');
		ans = 0;
		for(int i = 1; i < M; i++)
			if(str[i] == 'O')
			{
				//printf("%d %d\n", acum[i], acum[M]-acum[i+1]);
				ans += (acum[i]*1LL)*(acum[M]-acum[i+1]);
			}
		printf("%lld\n", ans);
	}
	return 0;
}
