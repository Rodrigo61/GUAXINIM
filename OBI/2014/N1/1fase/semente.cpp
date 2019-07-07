#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()


int main()
{
	int F, R;
	scanf("%d%d", &F, &R);
	vector<int> vals(R);
	for (int i = 0; i < R; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	int maxi = 0;
	
	maxi = max(maxi, vals[0] - 1);
	db(vals[0] - 1);
	maxi = max(maxi, F - vals[R - 1]);
	db(F - vals[R - 1]);
	for (int i = 0; i < R - 1; i++)
	{
		maxi = max(maxi, (vals[i + 1] - vals[i]) / 2);
	}
	
	printf("%d\n", maxi);
	
}
