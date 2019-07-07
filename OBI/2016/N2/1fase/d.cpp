#include <bits/stdc++.h>

using namespace std;

#define MAXN 1123456
#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;

int vals[MAXN];
int pref[MAXN];

int main()
{
	int N, D;
	scanf("%d%d", &N, &D);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	ll acu = 0;
	for (int i = 0; i < N; i++)
	{
		pref[i] = acu + vals[i];
		acu = pref[i];
	}
	
	int total = 0;
	set<int> freq;
	freq.insert(0);
	for (int i = 0; i < N; i++)
	{
		int target = pref[i] - D;
		if (target >= 0)
		{
			if (freq.find(target) != freq.end())
			{
				db("found");
				total += 1;
			}
		}
		freq.insert(pref[i]);
	}
	
	db("border");
	acu = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		freq.erase(freq.find(pref[i]));
		acu += vals[i];
		int target = D - acu;
		if (target > 0)
		{
			if (freq.find(target) != freq.end())
			{
				total += 1;
			}
		}
	}
	
	
	printf("%d\n", total);
	
}
