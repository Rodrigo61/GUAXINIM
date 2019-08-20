#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

ll N, I;
 
int main()
{
	scanf("%lld%lld", &N, &I);
	ll total_bits = 8 * I;
	ll K = pow(2, total_bits/N);
	db(K);
	
	vi vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	map<int, int> freq;
	vi cleft(N);
	for (int i = 0; i < N; i++)
	{
		cleft[i] = i - freq[vals[i]];
		if (freq.find(vals[i]) == freq.end()) freq[vals[i]] = 0;
		freq[vals[i]]++;
	}
	
	freq.clear();
	vi cright(N);
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		cright[i] = cnt - freq[vals[i]];
		if (freq.find(vals[i]) == freq.end()) freq[vals[i]] = 0;
		freq[vals[i]]++;
		++cnt;
	}
	
	int l = N/2;
	int r = N/2;
	set<int> s;
	int res = INF;
	while (s.size() <= K)
	{
		res = min(res, cleft[l] + cright[r]);
		if (l - 1 >= 0 && s.find(vals[l - 1]) != s.end())
		{
			--l;
			continue;
		}
		if (r + 1 < N && s.find(vals[r + 1]) != s.end())
		{
			++r;
			continue;
		}
		
		if (l == 0)
		{
			r++;
			s.insert(vals[r]);
			continue;
		}
		
		if (r == N - 1)
		{
			l--;
			s.insert(vals[l]);
			continue;
		}
		
		if (abs(cleft[l] - cleft[l - 1]) < abs(cleft[r] - cright[r + 1]))
		{
			l--;
			s.insert(vals[l]);
		}
		else
		{
			r++;
			s.insert(vals[r]);
		}
		
	}
			printf("%d\n", res);

	
}
