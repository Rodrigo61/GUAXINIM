#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back


int main()
{
	int N;
	scanf("%d", &N);
	vector<int> vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	vector<int> res(N);
	for (int i = 1; i < N - 1; i++)
	{
		res[i] += vals[i - 1] + vals[i] + vals[i + 1];
	}
	
	res[0] = vals[0];
	if (N > 1) res[0] += vals[1];
	
	res[N - 1] = vals[N - 1];
	if (N > 1) res[N - 1] += vals[N - 2];
	
	for (int i : res)
		printf("%d\n", i);
}
