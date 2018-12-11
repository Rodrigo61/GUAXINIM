#include "bits/stdc++.h"

using namespace std;


int main()
{
	int num;
	scanf("%d", &num);
	
	num+=1;
	string s = to_string(num);
	
	for (char &c : s)
	{
		if (c == '0')
		{
			c = '1';
		}
	}
	
	printf("%s\n", s.c_str());
	
	return 0;
}
