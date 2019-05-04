#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 112345
#define ll long long
#define fi first
#define se second
#define pll pair<ll, ll>


int erase[MAXN];

int main()
{
	
	int N;
	string s;
	
	cin >> N >> s;
	
	int second_play = (N - 11) / 2;
	int first_play = (N - 11 + 1) / 2;
	
	int last_eight = -1;
	int count = second_play;
	for (int i = 0; i < N; i++)
	{
		if (s[i] == '8')
		{
			if (count)
			{
				--count;
				continue;
			}
			
			last_eight = i;
			break;
		}
	}
	
	if (last_eight != -1 && first_play >= last_eight - second_play)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	
	return 0;
}
