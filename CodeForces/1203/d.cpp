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

bool possible(int K)
{
	int r_it = P.size() - 1;
	int l_it = 0;
	
	vi pos(MAXN);
	db(r_it);
	db(l_it);
	
	for (int i = T.size() - 1; i >= K; --i)
	{
		db(i);
		if (r_it >= 0 && T[i] == P[r_it])
		{
			db(i);
			r_it--;
			if (r_it >= 0)
				pos[r_it] = i;
			db(r_it);
		}
	}
	
	if (r_it < 0) return true;
	for (int i = 0; i < (int)T.size() - K; i++)
	{
		if (l_it < (int)P.size() && T[i] == P[l_it])
		{
			++l_it;
			if (l_it == (int)P.size()) return true;
		}
		if (r_it < (int)P.size() && i + K == pos[r_it])
		{
			r_it++;
		}
		if (l_it + (P.size() - r_it - 1) >= P.size())
			return true;
		
	}
	
	return false;
}

int main()
{
	cin >> T >> P;
	int up = T.size() - P.size();
	int lo = 0;
	int best = 0;
	//~ db(up);
	//~ db(possible(9));
	//~ db(possible(8));
	//~ db(possible(7));
	//~ db(possible(6));
	//~ db(possible(5));
	//~ db(possible(4));
	//~ db(possible(3));
	//~ db(possible(2));
	//~ db(possible(1));
	//~ db(possible(0));
	//~ exit(1);
	while (lo <= up)
	{
		int mid = lo + (up - lo) / 2;
		if (possible(mid))
		{
			best = max(best, mid);
			lo = mid + 1;
		}
		else
		{
			up = mid - 1;
		}
	}
	
	printf("%d\n", best);
	
}
