#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;

int main()
{
	int N;
	string str;
	cin >> N >> str;
	
	for (int i = 0; i < str.size() - 1; i++)
	{
		
		if (str[i] == str[i + 1])
		{
			str[i] = '*';
		}
		else
		{
			++i;
		}
		
	}
	
	string res;
	int total = 0;
	for (auto c : str)
	{
		if (c != '*')
		{
			res += c;
		}
		else
		{
			++total;
		}
		
	}
	
	if (res.size() % 2 != 0)
	{
		res.pop_back();
		++total;
	}
	
	cout << total << endl;
	cout << res << endl;
	
}
