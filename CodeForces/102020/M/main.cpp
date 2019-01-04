#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;



int main()
{
	string s;
	cin >> s;
	
	int sz = s.size();
	
	int A_count = 0, B_count = 0;
	
	for (char c : s)
	{
		if (c == 'A')
		{
			++A_count;
		}
		else
		{
			++B_count;
		}
	}
	
	if (A_count % 2 != 0 || B_count % 2 != 0)
	{
		return !printf("NO\n");
	}
	
	A_count /= 2;
	B_count /= 2;
	
	s += s;
	
	int begi = 0;
	int endi = A_count + B_count - 1;
	
	int cA = 0, cB = 0;
	for (int i = begi; i <= endi; i++)
	{
		if (s[i] == 'A')
		{
			cA++;
		}
		else
		{
			cB++;
		}
	}
	db(begi);
	db(endi);
	db(A_count);
	db(B_count);
	
	while ((cA != A_count && cB != B_count) && endi < int(s.size()))
	{
		if (s[begi % sz] == 'A')
		{
			--cA;
		}
		else
		{
			--cB;
		}
		++begi;
		
		++endi;
		if (s[endi % sz] == 'A')
		{
			++cA;
		}
		else
		{
			++cB;
		}
	
	}
	
	db(cA);
	db(cB);
	db(begi);
	db(endi);
	if (cA == A_count && cB == B_count)
	{
		printf("YES\n");
		printf("%d %d\n", begi%sz + 1,  endi%sz + 2);
	}
	else
	{
		printf("NO\n");
	}
	
	
	return 0;
}
