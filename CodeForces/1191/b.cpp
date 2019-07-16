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
	vi vals[26];
	for (int i = 0; i < 3; i++)
	{
		string s;
		cin >> s;
		vals[s[1] - 'a'].pb(s[0] - '0');
	}
	int best = 2;
	for (int i = 0; i < 26; i++)
	{
		sort(all(vals[i]));
		int seq_e = 0;
		int best_e = 0;
		int seq_i = 0;
		int best_i = 0;
		int last = -INF;
		for(int v : vals[i])
		{
			db(v);
			if (v != last)
			{
				seq_e = 0;
			}
			if (v != last + 1)
			{
				db(last);
				seq_i = 0;
			}
			if (v == last + 2)
			{
				best_i = 2;
			}
			++seq_e;
			++seq_i;
			best_e = max(best_e, seq_e);
			best_i = max(best_i, seq_i);
			last = v;
		}
		db(best_i);
		db(best_e);
		best = min(best, 3 - max(best_i, best_e));
	}
	
	printf("%d\n", best);
	
}
