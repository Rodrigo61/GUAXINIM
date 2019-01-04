#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 100005

int N;
string s;
int left_chunk[MAXN], right_chunk[MAXN];

int main()
{

	cin >> N >> s;
	
	int last_s = -1;
	int chunk = 0;
	int first_G = s.size(), last_G = -1;
	int maxi = 0;
	
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == 'S')
		{
			right_chunk[last_s] = chunk;
			left_chunk[i] = chunk;
			last_s = i;
			chunk = 0;
		}
		else
		{
			first_G = min(first_G, i);
			last_G = max(last_G, i);
			++chunk;
			maxi =  max(maxi, chunk);
		}
	}
	right_chunk[last_s] = chunk;
	
	
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == 'S')
		{
			int l = i - left_chunk[i];
			int r = i + right_chunk[i];
			
			if (first_G < l || last_G > r)
			{
				maxi = max(maxi, left_chunk[i] + right_chunk[i] + 1);
			}
			else
			{
				maxi = max(maxi, left_chunk[i] + right_chunk[i]);
			}
		}
	}
	
	printf("%d\n", maxi);
	
}
