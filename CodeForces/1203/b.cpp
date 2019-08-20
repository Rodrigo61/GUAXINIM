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

#define MAXA 11234

int main()
{
	int Q;
	scanf("%d", &Q);
	for (int w = 0; w < Q; w++)
	{
		int N;
		scanf("%d", &N);
		vi freq(MAXA);
		set<int> s;
		for (int i = 0; i < 4 * N; i++)
		{
			int v;
			scanf("%d", &v);
			freq[v]++;
			s.insert(v);
		}
		vi used;
		used.assign(all(s));
		bool poss = true;
		for (int i = 0; i < MAXA; i++)
		{
			if (freq[i] % 2 != 0)
			{
				poss = false;
				break;
			}
		}
		
		if (!poss)
		{
			printf("NO\n");
			continue;
		}
		
		int l = 0;
		int r = used.size() - 1;
		int target = used[l] * used[r];
		db(target);
		while (l <= r)
		{
			if (l == r && freq[used[l]] < 4)
			{
				poss = false;
				break;
			}
			
			if (freq[used[l]] != freq[used[r]])
			{
				poss = false;
				break;
			}
			if (used[l] * used[r] != target)
			{
				poss = false;
				break;
			}
			++l, --r;
		}
		
		if (poss)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
		
		
		
	}
	
	
}
