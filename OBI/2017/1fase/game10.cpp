#include <bits/stdc++.h>

using namespace std;

#define MAXM 65
#define db(x) cerr << #x <<  " = " << x << endl;

int main()
{
	int N, D, A;
	scanf("%d%d%d", &N, &D, &A);
	
	if (A <= D)
	{
		printf("%d\n", D - A);
	}
	else
	{
		printf("%d\n", N - A + D);
	}

	return 0;
}
