#include<bits/stdc++.h>

using namespace std;

set< pair< double, int> > conjunto;

int ant[100001];
int dep[100001];
int S[100001];
int V[100001];

pair<int, int> A[100001];

int main()
{
	int N, x;
	pair<double, int> p;
	double t = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &A[i].first, &A[i].second);
	}
	sort(A, A+N);
	for(int i = 1; i <= N; i++)
	{
		S[i] = A[i-1].first;
		V[i] = A[i-1].second;
		if(i != 1)
			ant[i] = i-1;
	}
	for(int i = 2; i <= N; i++)
	{
		//printf("%d %d %d\n", V[i], V[i-1], V[i] < V[i-1]);
		if(V[i] < V[i-1])
		{
			//printf("%.2lf\n", double(S[i]-S[i-1])/(V[i-1]-V[i]));
			conjunto.insert({double(S[i]-S[i-1])/(V[i-1]-V[i]), i});
		}
	}
	while(conjunto.size())
	{
		//printf("OI\n");
		p = *conjunto.begin();
		t = p.first;
		x = ant[p.second];
		ant[p.second] = ant[x];
		conjunto.erase(p);
		if(ant[x] == 0)
			continue;
		conjunto.erase({double(S[x]-S[ant[x]])/(V[ant[x]]-V[x]), x});
		if(V[p.second] < V[ant[p.second]])
			conjunto.insert({double(S[p.second]-S[ant[p.second]])/(V[ant[p.second]]-V[p.second]), p.second});
	}
	printf("%.5lf\n", t);
	return 0;
}
