#include <bits/stdc++.h>

using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 112345

int N;
int vals[MAXN];
int freq[MAXN];
map<int, int> map_freq;

bool valid()
{
	if (map_freq.size() == 1)
	{
		return map_freq.find(1) != map_freq.end() || map_freq.begin()->second == 1; // tudo 1
	}
	
	if (map_freq.size() > 2)
	{
		return false;
	}
	
	if (map_freq.size() == 2)
	{
		vector<int> keys;
		for (auto p : map_freq)
			keys.push_back(p.first);
			
		sort(keys.begin(), keys.end());
		
		if (keys[0] == 1 && map_freq[1] == 1)
		{
			return true;
		}
		
		if (keys[1] == keys[0] + 1 && map_freq[keys[1]] == 1)
		{
			return true;
		}
	}
	
	return false;
	
}

void dec_map(int freq)
{
	if (freq == 0)
		return;
		
	if (map_freq.find(freq) == map_freq.end())
		return;
		
	map_freq[freq]--;
	
	if (map_freq[freq] == 0)
	{
		map_freq.erase(map_freq.find(freq));
	}
}

void inc_map(int freq)
{
	if (map_freq.find(freq) == map_freq.end())
		map_freq[freq] = 0;
		
	map_freq[freq]++;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	int result = 0;
	for (int i = 0; i < N; i++)
	{

		dec_map(freq[vals[i]]);
		freq[vals[i]]++;
		inc_map(freq[vals[i]]);
		
		if (valid())
		{
			result = i;
		}
	}
	
	printf("%d\n", result + 1);
}
