#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define fi first
#define se second


int main()
{
	vector<pii> in(3);
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &in[i].fi);
		in[i].se = i;
	}
	sort(all(in));
	for (pii i : in)
		printf("%d\n", i.se + 1);
	
	
}
