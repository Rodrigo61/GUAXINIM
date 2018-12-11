#include "bits/stdc++.h"

using namespace std;
#define db(x) //cerr << #x << " = " << x << endl;


int main()
{
	string s;
	cin >> s;
	
	int maxi = 0;
	int bi = 0, bj = 0;
	
	int acu = 0;
	int start = 0;
	
	for (int i = 0; i < (int)s.size(); i++)
	{
		
		if (s[i] == 'R')
		{
			acu++;
			
			if (acu > maxi || (acu == maxi && start < bi))
			{
				db(i);
				db(acu);
				maxi = acu;
				bi = start;
				bj = i;
			}
			
			maxi = max(maxi, acu);
		}
		else
		{
			acu--;
			
			if (acu < 0)
			{
				acu = 0;
				start = i+1;
			}
			
		}
	}
	
	acu = 0;
	start = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != 'R')
		{
			acu++;
			
			if (acu > maxi || (acu == maxi && start < bi))
			{
				db(acu);
				maxi = acu;
				bi = start;
				bj = i;
			}
			
			maxi = max(maxi, acu);
		}
		else
		{
			acu--;
			
			if (acu < 0)
			{
				acu = 0;
				start = i+1;
			}
		}
	}
	
	printf("%d %d", bi+1, bj+1);
	
	return 0;
}
