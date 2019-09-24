#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;


int main()
{
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n;
		scanf("%d", &n);
		multiset<ll> ms;
		bool found = false;
		for (int i = 0; i < n; i++)
		{
			ll v;
			scanf("%lld", &v);
			ms.insert(v);
			if (v == 2048)
				found = true;
		}
		
		while (!found && ms.size() > 1)
		{
			ll a = *ms.begin();
			ms.erase(ms.begin());
			ll b = *ms.begin();
			
			if (a == 2048 || b == 2048)
			{
				found = true;
				break;
			}
			
			if (a != b)
				continue;
				
			ms.erase(ms.begin());
			
			ll c = a + b;
			if (c == 2048)
			{
				found = true;
				break;
			}
			ms.insert(c);
		}
		
		if (found)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
	}
	
}
