#include<bits/stdc++.h>

using namespace std;

main()
{
	int n;
	string a = "a";
	for(char i = 'b'; i < 'l'; i++)
	{
		a = (a + i)+a;
		//cout << a << endl;
	}
	scanf("%d", &n);
	printf("%c\n", a[n-1]);
	return 0;
}
