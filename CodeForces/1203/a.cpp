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
	int Q;
	scanf("%d", &Q);
	for (int w = 0; w < Q; w++)
	{
		int N;
		scanf("%d", &N);
		vi vals(N);
		int one_pos = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &vals[i]);
			if (vals[i] == 1)
				one_pos = i;
		}
		
		if (N == 1)
		{
			printf("YES\n");
			continue;
		}
		
		int poss = true;
		int i = (one_pos + 1) % N;
		int last = 1;
		while (vals[i] != 1)
		{
			if (vals[i] != last + 1)
			{
				poss = false;
				break;
			}
			last = vals[i];
			i = (i + 1) % N;
		}
		
		if (poss)
		{
			printf("YES\n");
			continue;
		}
		
		poss = true;
		i = one_pos - 1;
		if (i < 0) i = N - 1;
		last = 1;
		while (vals[i] != 1)
		{
			if (vals[i] != last + 1)
			{
				poss = false;
				break;
			}
			last = vals[i];
			i--;
			if (i < 0) i = N - 1;
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
