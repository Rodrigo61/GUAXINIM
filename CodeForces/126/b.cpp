#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 1123456

string word;
int lps[MAXN], m;

void kmpPre(string &target)
{
	int i = 0, j = -1;
	memset(lps, 0, sizeof(lps));
	lps[0] = -1;
	m = target.length();
	while(i < m)
	{
		while(j >= 0 && target[i] != target[j]) 
			j = lps[j];
		i++, j++;
		lps[i] = j;
	}
}

bool kmpSearch(string &T, string &P)
{
	int i = 0, j = 0, n = T.size();
	while(i < n)
	{
		while(j >= 0 && T[i] != P[j]) j = lps[j];
		i++, j++;
		if(j == m)
		{
			return true;
			j = lps[j];
		}
	}
	return false;
}

string solve()
{
	kmpPre(word);
	int t = lps[word.size()];
	
	while (t > 0)
	{
		db(t);
		bool found = false;
		for (int i = 1; i < word.size(); i++)
		{
			if (lps[i] == t)
			{
				found = true;
			}
		}
		
		if (found)
		{
			break;
		}
		
		t = lps[t];
	}
	
	if (t == 0)
	{
		return "Just a legend";
	}
	
	return word.substr(0, t);
}

int main()
{
	cin >> word;
	//~ kmpPre(word);
	//~ for (int i = 0; i < word.size() + 1; i++)
	//~ {
		//~ printf("%d ", lps[i]);
	//~ } printf("\n");
	
	
	cout << solve() << endl;
}
