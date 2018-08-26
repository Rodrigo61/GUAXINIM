#include <bits/stdc++.h>
#define ll long long
#define MAXN 600000
#define MOD 1000000007
#define MOD2 2739726019178082LL

using namespace std;

vector<int> V;
vector<int> suf[100000];
int ptr[100000];

int SA[MAXN], LCP[MAXN], pos[MAXN], tmp[MAXN], val[MAXN];
int gap, N;

bool cmp(int i, int j)
{
	if(pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
	N = V.size();
	tmp[0] = 0;
	
	for(int i = 0; i < N; i++)
		SA[i] = i, pos[i] = V[i];
		
	for(gap = 1;; gap *= 2)
	{
		sort(SA, SA + N, cmp);
		
		for(int i = 0; i < N-1; i++)
			tmp[i+1] = tmp[i] + cmp(SA[i], SA[i+1]);
		for(int i = 0; i < N; i++)
			pos[SA[i]] = tmp[i];
		
		if(tmp[N-1] == N-1)
			break;
	}
}

void buildLCP()
{
	for(int i = 0, k = 0; i < N; i++)
	{
		if(pos[i] != N-1)
		{
			int j = SA[pos[i] + 1];
			
			while(V[i+k] == V[j+k])
				k++;
				
			LCP[pos[i]] = k;
			if(k) k--;
		}
	}
	LCP[N-1] = 0;
}

int main()
{
	int T, M, x, y;
	ll sum = 0;
	priority_queue< pair<int, int> > pq;
	while(scanf("%d", &T) == 1)
	{
		sum = 0;
		for(int i = 0; i < T; i++)
		{
			scanf("%d", &M);
			for(int j = 0; j < M; j++)
			{
				scanf("%d", &x);
				suf[i].push_back(V.size());
				V.push_back(x);	
			}
			V.push_back(301);
		}
		buildSA();
		buildLCP();
		/*for(int i = 0; i < N; i++)
		{
			printf("%d %d:", SA[i], LCP[i]);
			for(int j = SA[i]; j < V.size(); j++)
				printf(" %d", V[j]);
			printf("\n");
		}*/
		for(int i = 0; i < N; i++)
			val[SA[i]] = i;
		/*printf("\n");
		for(int i = 0; i < N; i++)
			printf("%d: %d\n", i, val[i]);*/
		for(int i = 0; i < T; i++)
		{
			//printf("%d %d %d\n", i, suf[i][0], val[suf[i][0]]);
			pq.push(make_pair(-val[suf[i][0]], i));
		}
		while(!pq.empty())
		{
			x = -pq.top().first;
			y = pq.top().second;
			x = V[SA[x]];
			pq.pop();
			sum = (365*sum + x);
			if(sum >= MOD2)
				sum %= MOD;
			ptr[y]++;
			if(ptr[y] < suf[y].size())
				pq.push(make_pair(-val[suf[y][ptr[y]]], y));
		}
		printf("%lld\n", (sum*365)%MOD);
		for(int i = 0; i < T; i++)
			suf[i].clear(), ptr[i] = 0;
		V.clear();
	}
	return 0;
}
