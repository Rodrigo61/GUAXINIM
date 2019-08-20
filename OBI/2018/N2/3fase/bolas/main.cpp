#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
int main()
{
	vi vals(8);
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &vals[i]);
	}
	sort(all(vals));
	
	do
	{
		bool poss = true;
		for (int i = 1; i < 8; i++)
		{
			if (vals[i] == vals[i - 1])
			{
				poss = false;
				break;
			}
		}
		
		if (poss)
		{
			return !printf("S\n");
		}
	} while (next_permutation(all(vals)));
	
	printf("N\n");
	
	
}
