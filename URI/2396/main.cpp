#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back


int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	vector<pii> player;
	
	for (int i = 0; i < N; i++)
	{
		int total = 0;
		for (int j = 0; j < M; j++)
		{
			int v;
			scanf("%d", &v);
			total += v;
		}
		player.pb({total, i + 1});
	}
	
	sort(all(player));
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", player[i].se);
	}
	
		
	
}
