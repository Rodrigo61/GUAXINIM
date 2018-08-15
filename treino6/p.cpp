#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main()
{
	
	string s;
	cin >> s;
	
	vi freq(26, 0);
	int complexity = 0;
	for(char &c : s)
	{
		if (freq[c - 'a'] == 0)
		{
			++complexity;
		}
		
		freq[c - 'a']++;
	}
	
	vi sorted;
	
	for (int i = 0; i < 26; i++)
	{
		if (freq[i] != 0)
		{
			sorted.push_back(freq[i]);
		}
	}
	
	sort(sorted.begin(), sorted.end());
		
	int it = 0;
	int cost = 0;
	while (complexity > 2)
	{
		cost += sorted[it];
		++it;
		complexity--;
	}
	
	printf("%d\n", cost);
	
	
	return 0;
}


