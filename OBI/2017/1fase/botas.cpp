#include <bits/stdc++.h>

using namespace std;

#define MAXM 65
#define db(x) cerr << #x <<  " = " << x << endl;

int le[MAXM], ri[MAXM];

int main()
{
	
	int N;
	scanf("%d", &N);
	
	int sz;
	char side;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d %c\n", &sz, &side);
		if (side == 'D')
		{
			ri[sz]++;
		}
		else
		{
			le[sz]++;
		}
	}
	
	int total = 0;
	for (int i = 0; i < MAXM; i++)
	{
		total += min(ri[i], le[i]);
	}
	
	
	printf("%d\n", total);
	return 0;
}
