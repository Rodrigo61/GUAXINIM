#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
#define db(x) cerr << #x << " = " << x << endl;

int main()
{
	int tc;
	scanf("%d", &tc);
	
	while (tc--)
	{
		vector<int> vals(3);
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &vals[i]);
		}
		int d;
		scanf("%d", &d);
		
		sort(vals.begin(), vals.end());
		
		ull calc = vals[0]*vals[0] + vals[1]*vals[1] + (vals[2]+d)*(vals[2]+d) + vals[0]*7;
		db(calc);
		int i = 1;
		while (i <= d && vals[0]+i <= vals[1])
		{
			ull new_calc = (vals[0]+i)*(vals[0]+i) + vals[1]*vals[1] + (vals[2]+d-i)*(vals[2]+d-i) + (vals[0]+i)*7;
			db(new_calc);
			if (new_calc > calc)
			{
				calc = new_calc;
			}
			else
			{
				break;
			}
			++i;
		}
		
		printf("%llu\n", calc);
	}
	
	
	return 0;
}
