#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

#define db(x) cerr << #x << " = " << x << endl;
#define se second
#define fi first
#define all(x) x.begin(), x.end()
#define MAXN 2123
#define INF 1123456789

int N, M, K;
vector<int> ordered_vals;
vector<pair<int, int>> useful_offers;
int dp[MAXN], vis[MAXN];
int prefix[MAXN];

int get_prefix(int i, int j)
{
	if (j < i)
	{
		return 0;
	}
	if (i == 0)
	{
		return prefix[j];
	}
	
	return prefix[j] - prefix[i - 1];
}

int solve(int n)
{
	if (n == N)
	{
		return 0;
	}
	
	if (vis[n])
	{
		return dp[n];
	}
	vis[n] = 1;
	
	int mini = INF;
	
	for (auto offer : useful_offers)
	{
		if (offer.fi + n <= N)
		{
			int have_to_pay = offer.fi - offer.se;
			int rec = get_prefix(n, n + have_to_pay - 1) + solve(offer.fi + n);
			mini = min(mini, rec);
		}
	}
	
	dp[n] = mini;
	return dp[n];
	
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	vector<int> vals(N);
	vector<pii> offers(M);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &offers[i].fi, &offers[i].se);
	}
	
	sort(all(vals));
	sort(all(offers));
	reverse(all(offers));
	
	N = K;
	for (int i = 0; i < N; i++)
	{
		ordered_vals.push_back(vals[i]);
	}
	sort(all(ordered_vals), greater<int>());
	int acu = 0;
	for (int i = 0; i < N; i++)
	{
		acu += ordered_vals[i];
		prefix[i] = acu;
	}
	
	auto it = offers.begin();
	while (it != offers.end())
	{
		int cost = it->fi;
		if (cost <= N)
		{
			useful_offers.push_back(*it);
		}
		while (it != offers.end() && it->fi == cost)
		{
			++it;
		}
	}
	
	if (find(all(useful_offers), make_pair(1,0)) == useful_offers.end())
	{
		useful_offers.push_back({1,0});
	}
	
	printf("%d\n", solve(0));
	
	return 0;
}
