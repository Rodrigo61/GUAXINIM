#include <bits/stdc++.h>

using namespace std;

bool equal(vector<string> &a, vector<string> &b)
{
	for (int i = 0; i < (int)a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<string> names;
	int sz;
	cin >> sz;
	string name;
	
	for (int i = 0; i < sz; i++)
	{
		cin >> name;
		names.push_back(name);
	}
	
	auto sorted = names;
	sort(sorted.begin(), sorted.end());
	auto reversed = sorted;
	reverse(reversed.begin(), reversed.end());
	
	if (equal(names, sorted))
	{
		cout << "INCREASING" << endl;
	}
	else if (equal(names, reversed))
	{
		cout << "DECREASING" << endl;
	}
	else
	{
		cout << "NEITHER" << endl;
	}
	
	return 0;
}
