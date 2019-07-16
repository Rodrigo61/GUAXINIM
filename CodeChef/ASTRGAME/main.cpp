#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
#define db(x) cerr << #x << " = " << x << endl;

string target;
set<string> dict;
int dp[35][35];
int vis[35][35];
int t;
 
int mex(set<int> &grundy_set)
{
	int res = 0;
	while (true)
	{
		if (grundy_set.find(res) == grundy_set.end())
			return res;
		++res;
	}
}
 
int grundy(int left, int right)
{
	if (left > right)
		return 0;
		
	if (left < 0 || right >= (int)target.size())
		return 0;
		
	if (vis[left][right] == t)
	{
		return dp[left][right];
	}
	vis[left][right] = t;
	
	set<int> grundy_set;
	for (int i = left; i <= right; i++)
	{
		for (int j = i; j <= right; j++)
		{
			if (dict.find(target.substr(i, j - i + 1)) != dict.end())
			{
				grundy_set.insert(grundy(left, i - 1) ^ grundy(j + 1, right));
			}
		}
	}
	
	if (grundy_set.empty())
	{
		dp[left][right] = 0;
		return 0;
	}

	dp[left][right] = mex(grundy_set);
	return dp[left][right];
	
}
int main()
{
	int tc;
	cin >> tc;
	
	while (tc--)
	{
		int dict_sz;
		string word;
		cin >> target;
		cin >> dict_sz;
		
		dict.clear();
		
		for (int i = 0; i < dict_sz; i++)
		{
			cin >> word;
			dict.insert(word);
		}
		
		++t;
		if (grundy(0, target.size() - 1) != 0)
		{
			printf("Teddy\n");
		}
		else
		{
			printf("Tracy\n");
		}
		
	}
	return 0;
}
