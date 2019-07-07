#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x <<  " = " << x << endl;

int main()
{
	int N;
	scanf("%d", &N);
	int last;
	scanf("%d", &last);
	
	int c;
	int acu = 1;
	int maxi = 1;
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &c);
		
		if (abs(c - last) > 1)
		{
			acu = 0;
		}
		
		++acu;
		maxi = max(maxi, acu);
		last = c;
	}
	
	printf("%d\n", maxi);
	


	return 0;
}
