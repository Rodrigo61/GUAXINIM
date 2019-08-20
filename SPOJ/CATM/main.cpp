#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define RAT 1
#define CAT 2

int N, M;

int main()
{
	int T;
	scanf("%d%d%d", &N, &M, &T);
	while (T--)
	{
		pii rat, cat1, cat2;
		scanf("%d%d", &rat.fi, &rat.se);
		scanf("%d%d", &cat1.fi, &cat1.se);
		scanf("%d%d", &cat2.fi, &cat2.se);
		
		bool possible = false;
		for (int i = 0; i < N + 1; i++)
		{
			int drat = abs(rat.fi - i) + abs(rat.se - 1);
			int dcat1 = abs(cat1.fi - i) + abs(cat1.se - 1);
			int dcat2 = abs(cat2.fi - i) + abs(cat2.se - 1);
			if (drat < dcat1 && drat < dcat2)
			{
				possible = true;
				break;
			}
			drat = abs(rat.fi - i) + abs(rat.se - N);
			dcat1 = abs(cat1.fi - i) + abs(cat1.se - N);
			dcat2 = abs(cat2.fi - i) + abs(cat2.se - N);
			if (drat < dcat1 && drat < dcat2)
			{
				possible = true;
				break;
			}
		}
		for (int i = 0; i < M + 1; i++)
		{
			int drat = abs(rat.fi - 1) + abs(rat.se - i);
			int dcat1 = abs(cat1.fi - 1) + abs(cat1.se - i);
			int dcat2 = abs(cat2.fi - 1) + abs(cat2.se - i);
			if (drat < dcat1 && drat < dcat2)
			{
				possible = true;
				break;
			}
			drat = abs(rat.fi - N) + abs(rat.se - i);
			dcat1 = abs(cat1.fi - N) + abs(cat1.se - i);
			dcat2 = abs(cat2.fi - N) + abs(cat2.se - i);
			if (drat < dcat1 && drat < dcat2)
			{
				possible = true;
				break;
			}
		}
		
		
		if (possible)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
	}
	
}
