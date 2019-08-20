#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 212345

string T, P;

int main()
{
	cin >> T >> P;
	for (int k = T.size() - P.size(); k >= 0; k--)
	{
		bool poss = false;
		db(k);
		for (int j = 0; j + k - 1 < (int)T.size(); j++)
		{
			db(j);
			string newT;
			for (int i = 0; i < j; i++)
			{
				newT += T[i];
			}
			for (int i = j + k; i < (int)T.size(); i++)
			{
				newT += T[i];
			}
			db(newT);
			int itP = 0;
			for (char c : newT)
			{
				if (c == P[itP])
				{
					++itP;
				}
				if (itP == (int)P.size())
				{
					poss = true;
					break;
				}
			}
			
			if (poss) break;
		}
		
		if (poss)
		{
			return !printf("%d\n", k);
		}
		
	}
	
}
