#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define INF 100100100100100100
#define all(x) x.begin(), x.end()
#define MAXN 11234567
#define M 10000001
#define fi first
#define se second
#define ll long long

int N;
int freq[MAXN][2];

int main()
{
	scanf("%d", &N);
	
	int num;
	ll mini_val = INF;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		freq[num][1] = freq[num][0];
		freq[num][0] = i + 1;
	}
	
	
	pair<int, int> mini_pair;
	
	for (int i = 1; i < M; i++)
	{
		vector<int> vals;
		vector<int> pos;
		for (int j = i; j < M && vals.size() < 2; j += i)
		{	
			int it = 0;
			while (vals.size() < 2 && freq[j][it] != 0)
			{
				pos.pb(freq[j][it]);
				vals.pb(j);
				++it;
			}
		}
		
		if (vals.size() == 2)
		{
			ll c = ((ll)vals[0] * (ll)vals[1]) / (ll)i;
			if (c < mini_val)
			{
				mini_val = c;
				mini_pair = {pos[0], pos[1]};
			}
		}
		
	}
	
	printf("%d %d\n", min(mini_pair.fi, mini_pair.se), max(mini_pair.fi, mini_pair.se));
	
	return 0;
}
