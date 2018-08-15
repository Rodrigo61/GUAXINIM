#include<bits/stdc++.h>
#define MAXN 100000

using namespace std;

int N, T;
int tree[MAXN+1];

void update(int i, int val)
{
	i++;
	while(i <= T)
	{
		tree[i] += val;
		i += (i&-i);
	}
}

int sum(int i)
{
	int s = 0;
	i++;
	while(i > 0)
	{
		s += tree[i];
		i -= (i & -i);
	}
	return s;
}

set<int> conju;
vector<int> v;
int vet[MAXN+1];

int id(int x)
{
	return lower_bound(v.begin(), v.end(), x)-v.begin();
}

main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &vet[i]);
		conju.insert(vet[i]);
	}
	v.assign(conju.begin(), conju.end());
	T = v.size();
	for(int i = 0; i < N; i++)
	{
		printf("%d\n", N-(i-sum(id(vet[i])-1)));
		update(id(vet[i]), 1);
	}
	return 0;
}
