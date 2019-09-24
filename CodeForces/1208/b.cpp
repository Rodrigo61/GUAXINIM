#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main()
{
	int N;
	scanf("%d", &N);
	vi vals(N);
	map<int, int> freq;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
		freq[vals[i]]++;
	}
	
	int total = 0;
	for (auto p : freq)
		if (p.se != 1)
			total++;
			
	int up = N;
	int lo = 0;
	int best = 0;
	db(total);
	while (lo <= up)
	{
		int mid = lo + (up - lo)/2;
		bool poss = false;
		map<int, int> cpy_freq = freq;
		int cpy_total = total;
		
		for (int i = 0; i < mid; i++)
		{
			cpy_freq[vals[i]]--;
			if (cpy_freq[vals[i]] == 1)
				--cpy_total;
		}
		
		if (cpy_total == 0)
		{
			poss = true;
		}
		else
		{
			for (int i = mid; i < N; i++)
			{
				cpy_freq[vals[i - mid]]++;
				if (cpy_freq[vals[i - mid]] == 2)
					++cpy_total;
					
				cpy_freq[vals[i]]--;
				if (cpy_freq[vals[i]] == 1)
					--cpy_total;
					
				if (cpy_total == 0)
				{
					poss = true;
					break;
				}
			}
		}
		
		db(poss);
		if (poss)
		{
			best = mid;
			up = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
		
	}
	
	
	printf("%d\n", best);
	
	
	
}
