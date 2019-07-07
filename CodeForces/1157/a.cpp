#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;

int main()
{
	int N;
	scanf("%d", &N);
	
	set<int> vals;
	while (vals.find(N) == vals.end())
	{
		vals.insert(N);
		++N;
		while (N % 10 == 0)
		{
			N /= 10;
		}
	}
	
	printf("%d\n", (int)vals.size());
	
}
