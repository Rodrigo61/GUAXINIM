#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	int res = (1 << N) - 1 - N;
	printf("%d\n", res);
	return 0;
}
