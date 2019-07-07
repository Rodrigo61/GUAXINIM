#include <bits/stdc++.h>

using namespace std;
#define db(x) cerr << #x << " = " << x << endl;

int main()
{
	int C, A;
	scanf("%d%d", &C, &A);
	printf("%d\n", (int)ceil((double)A/(C-1)));
}
