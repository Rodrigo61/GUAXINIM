#include "bits/stdc++.h"

using namespace std;



int main()
{
	int K, P, X;
	scanf("%d%d%d", &K, &P, &X);
	
	int M1 = ceil(sqrt((double)K*P/(X)));
	int M2 = floor(sqrt((double)K*P/(X)));
	
	printf("%.3lf\n", min(M1*X + (double)K/M1 * P, M2*X + (double)K/M2 * P));
	return 0;
}
