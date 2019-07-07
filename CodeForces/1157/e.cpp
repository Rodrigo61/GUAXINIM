#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 212345

int vals[MAXN];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	multiset<int> b;
	for (int i = 0; i < N; i++)
	{
		int v;
		scanf("%d", &v);
		b.insert(v);
	}
	
	for (int i = 0; i < N; i++)
	{
		int target = N - vals[i];
		auto it = b.lower_bound(target);
		if (it == b.end())
		{
			it = b.begin();
		}
		
		printf("%d ", (vals[i] + *it) % N);
		b.erase(it);
	}
	
	printf("\n");
	
}
