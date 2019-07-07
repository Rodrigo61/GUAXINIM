#include <bits/stdc++.h>

using namespace std;
#define db(x) cerr << #x << " = " << x << endl;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	if (M == 0)
	{
		printf("1\n");
	}
	else if (M <= N/2)
	{
		printf("%d\n", M);
	}
	else
	{
		printf("%d\n", N - M);
	}
}
