#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

int main()
{
	int n, i;
	scanf("%d%d", &n, &i);
	i *= 8;

	if (i/n > 20)
		return !printf("0\n");
	db(i/n);
	int k = (1 << i/n);

	db(k);

	set<int> used;
	map<int, int> freq;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		used.insert(a);
		freq[a]++;
	}

	vector<int> used_vet(all(used));

	if (k > (int)used_vet.size())
		return !printf("0\n");
	
	int will_change = n;
	int best = INF;
	for (int i = 0; i < k; i++)
	{
		will_change -= freq[used_vet[i]];
	}

	best = min(best, will_change);

	for (int i = k; i < (int)used_vet.size(); i++)
	{
		will_change += freq[used_vet[i - k]];
		will_change -= freq[used_vet[i]];
		best = min(best, will_change);
	}
	
	printf("%d\n", best);

	

}