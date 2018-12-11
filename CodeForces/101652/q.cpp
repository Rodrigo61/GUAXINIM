#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;

ll mid;
ll N;

bool possible (ll M)
{
	//~ db((N-M)*((N-M)-1)/2);
	return (N-M+1)*(N-M)/2 <= mid;
}

int solve()
{
	ll up = N;
	ll lo = 1;
	ll middle;
	ll best = 1;
	
	while (lo <= up)
	{
		middle = lo + (up-lo)/2;
		db(middle);
		if (possible(middle))
		{
			db("pos");
			best = middle;
			up = middle - 1;
		}
		else
		{
			db("impos");
			lo = middle + 1;
		}
	}
	
	return best;
}

int main()
{
	scanf("%lld", &N);
	
	db(N);
	mid = (N * (N - 1) + 1)/4;
	
	db(mid);
	
	printf("%d", solve() - 1);
	
	return 0;
}
