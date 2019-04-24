#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 112345
#define ll long long
#define fi first
#define se second
#define pll pair<ll, ll>


int most_right[255];

int main()
{
	int N;
	string s;
	
	cin >> N >> s;
	
	for (int i = 0; i < N; i++)
	{
		most_right[s[i]] = i;
	}
	
	for (int i = 0; i < N; i++)
	{
		for (char j = s[i] - 1; j >= 'a'; j--)
		{
			if (most_right[j] > i)
			{
				return !printf("YES\n%d %d\n", i + 1, most_right[j] + 1);
			}
		}
	}
	
	printf("NO\n");
	
	
	return 0;
}
