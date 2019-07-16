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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		string s, t, p;
		cin >> s >> t >> p;
		vi cnt(26);
		for (auto c : p)
			cnt[c-'a']++;
		
		int its = 0, itt = 0;
		string res;
		
		while ((int)res.size() < (int)t.size())
		{
			if (s[its] == t[itt])
			{
				db("s");
				res += s[its];
				++its;
			}
			else
			{
				if (cnt[t[itt] - 'a'])
				{
					db("p");
					db(cnt[t[itt] - 'a']);
					res += t[itt];
					--cnt[t[itt] - 'a'];
				}
				else
				{
					break;
				}
			}
			++itt;
		}
		
		db(res);
		if (its == (int)s.size() && res.size() == t.size())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
	}
	
}
