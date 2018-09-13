#include<bits/stdc++.h>

#define MAXN 300001

using namespace std;

struct query
{
	int L, R, ind, BL;
};

int total, N;

int ans[MAXN+1], freq[MAXN+1], B[MAXN+1];
int freqs[MAXN+1];

query queries[MAXN+1];

bool cmp(query x, query y)
{
	if(x.BL != y.BL)
		return x.BL < y.BL;
	return x.R > y.R;
}

void checkmais(int x)
{
	freq[B[x]]++;
	freqs[freq[B[x]]]++;
	if(freq[B[x]] == 1)
		total++;
}

void checkmenos(int x)
{
	if(x == 0)
		return;
	freqs[freq[B[x]]]--;
	freq[B[x]]--;
	if(freq[B[x]] == 0)
		total--;
}

int bb()
{
	int lo = 1, hi = N, mid, best = 0;
	while(lo <= hi)
	{
		mid = (lo+hi)/2;
		//printf("%d -> %d\n", mid, freqs[mid]);
		if(freqs[mid] >= mid)
		{
			best = mid;
			lo = mid+1;
		}
		else
			hi = mid-1;
	}
	return best;
}

void MO(int M)
{
	int i, L, R, curL, curR;
	sort(queries, queries+M, cmp);
	curL = queries[0].L;
	curR = queries[0].R;
	for(int i = curL; i <= curR; i++)
		checkmais(i);
	
	ans[queries[0].ind] = bb();
	//printf("\n");
	for(i = 1; i < M; i++)
	{
		L = queries[i].L;
		R = queries[i].R;
		while(curL < L)
			checkmenos(curL++);
		while(curL > L)
			checkmais(--curL);
		while(curR < R)
			checkmais(++curR);
		while(curR > R)
			checkmenos(curR--);
		ans[queries[i].ind] = bb();
		//printf("\n");
	}
}

set<int> setX;
vector<int> vetX;

int main()
{
	int M, block;
	scanf("%d %d", &N, &M);
	block = sqrt(M);
	freqs[0] = N;
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &B[i]);
		setX.insert(B[i]);
	}
	vetX.assign(setX.begin(), setX.end());
	for(int i = 1; i <= N; i++)
	{
		B[i] = lower_bound(vetX.begin(), vetX.end(), B[i])-vetX.begin();
	}
	for(int i = 0; i < M; i++)
	{
		queries[i].ind = i;
		scanf("%d %d", &queries[i].L, &queries[i].R);
		queries[i].BL = queries[i].L/block;
	}
	MO(M);
	for(int i = 0; i < M; i++)
		printf("%d\n", ans[i]);
	return 0;
}
