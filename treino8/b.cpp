#include<bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int main()
{
	char aux[1000];
	scanf("%s", aux);
	
	string s = aux;
	
	int S_acu = 0, C_acu = 0;
	
	for (char c : s)
	{
		if (c == 'C')
		{
			++C_acu;
			S_acu = 0;
		}
		else
		{
			++S_acu;
			C_acu = 0;
		}
		
		if (C_acu == 3)
		{
			printf("P");
			C_acu = 0;
		} 
		else if (S_acu == 3)
		{
			printf("T");
			S_acu = 0;	
		}
		else if (c == 'C')
		{
			printf("B");
		}
		else
		{
			printf("D");
		}
		
		
		
		
		
		
	}
	

	return 0;
}
