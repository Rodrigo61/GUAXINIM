#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()


int main()
{
	int N, B;
	scanf("%d%d", &N, &B);
	vector<int> vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	sort(all(vals));
	
	int total = 0;
	int l = 0, r = N - 1;
	
	while (l <= r)
	{
		if (l != r && vals[l] + vals[r] <= B)
		{
			l++;
			r--;
		}
		else
		{
			r--;
		}
		++total;
	}
	
	
	printf("%d\n", total);
}
