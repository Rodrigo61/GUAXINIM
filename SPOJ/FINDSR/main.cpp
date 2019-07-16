#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) //cerr << #x << " = " << x << endl
#define ll long long
#define vi vector<int>

#define MAXN 112345

char aux[MAXN];
string s;
vi divs;

void calc_divs()
{
	divs.clear();
	int target = (int)s.size();
	for (int i = 1; i * i <= target; i++)
	{
		if (target % i == 0)
		{
			divs.pb(i);
			if (target / i != i) 
				divs.pb(target / i);
		}
	}
	
	sort(all(divs));
	reverse(all(divs));
}


int main()
{
	while (scanf("%s", aux), s = aux, s != "*")
	{
		calc_divs();
		for (int d : divs)
		{
			int len = (int)s.size() / d;
			string p = s.substr(0, len);
			int it = 0;
			bool found = true;
			for (auto c : s)
			{
				if (c != p[it])
				{
					found = false;
					break;
				}
				it = (it + 1) % len;
			}
			if (found)
			{
				printf("%d\n", d);
				break;
			}
		}
	}
}
