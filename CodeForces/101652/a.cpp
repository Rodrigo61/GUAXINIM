#include "bits/stdc++.h"

using namespace std;

string s;

int main()
{
	cin >> s;
	
	char last =  s[0];
	
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == last)
		{
			return !printf("Or not.");
		}
		last = s[i];
	}
	
	printf("Odd.\n");
	
	return 0;
}
