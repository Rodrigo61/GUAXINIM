#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

#define MOD 998244353

ll mul(ll a, ll b)
{
	return (a * b) % MOD;
}

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}
int main()
{
	int N;
	cin >> N;
	vector<string> vet(N);
	vi len_freq(20);
	for (int i = 0; i < N; i++)
	{
		cin >> vet[i];
		len_freq[(int)vet[i].size()]++;
	}
	
	ll res = 0;
	for (int i = 0; i < N; i++)
	{
		db(vet[i]);
		for (int s = 0; s < 20; s++)
		{
			if (len_freq[s] == 0)
			{
				continue;
			}
			
			db(s);
			db(res);
			ll pot = 1;
			for (int j = (int)vet[i].size() - 1, d = 0; j >= 0; j--, ++d)
			{
				db(vet[i][j]);
				db(pot);
				db(d);
				ll part = mul(pot, vet[i][j] - '0');
				part = mul(part, len_freq[s]);
				db(part);
				res = add(res, part);
				if (d < s)
					pot = mul(pot, 100);
				else
					pot = mul(pot, 10);
			}
			pot = 10;
			for (int j = (int)vet[i].size() - 1, d = 0; j >= 0; j--, ++d)
			{
				ll part = mul(pot, vet[i][j] - '0');
				part = mul(part, len_freq[s]);
				res = add(res, part);
				db(part);
				if (d < s - 1)
					pot = mul(pot, 100);
				else
					pot = mul(pot, 10);
			}
			db(res);
		}
	}
	
	printf("%lld\n", res);
}
