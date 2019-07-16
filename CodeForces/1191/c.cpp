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

int main()
{
	ll N, M, P;
	scanf("%lld%lld%lld", &N, &P, &M);
	vll vet(P);
	for (int i = 0; i < P; i++)
	{
		scanf("%lld", &vet[i]);
	}
	
	db(M);
	auto it = vet.begin();
	ll offset = 0;
	ll res = 0;
	while (it != vet.end())
	{
		++res;
		db(res);
		ll pivo = *it - offset;
		ll limit = pivo % M == 0 ? pivo : (pivo/M + 1) * M;
		db(pivo);
		db(limit);
		db(offset);
		++it;
		ll new_offset = 1;
		while (it != vet.end() && *it - offset <= limit)
		{
			db(*it);
			++new_offset;
			++it;
		}
		offset += new_offset;
	}
	
	printf("%lld\n", res);
	
}
