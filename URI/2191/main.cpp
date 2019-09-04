#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

int main()
{
	int N;
	int tc = 0;
	while (scanf("%d", &N), N != 0)
	{
		vi vals(N);
		for (int i = 0; i < N; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			vals[i] = a - b;
		}
		
		int best = 0;
		pii best_pair;
		
		int curr = -1;
		int beg = -1;
		
		for (int i = 0; i < N; i++)
		{
			if (curr < 0)
			{
				curr = 0;
				beg = i;
			}
			
			curr += vals[i];
			
			if (curr > best)
			{
				best = curr;
				best_pair = {beg, i};
			}
			else if (curr == best && i - beg > best_pair.se - best_pair.fi)
			{
				best = curr;
				best_pair = {beg, i};
			}
		}
		
		printf("Teste %d\n", ++tc);
		if (best > 0)
		{
			printf("%d %d\n\n", best_pair.fi + 1, best_pair.se + 1);
		}
		else
		{
			printf("nenhum\n\n");
		}
		
		
		
		
	}
	
}
