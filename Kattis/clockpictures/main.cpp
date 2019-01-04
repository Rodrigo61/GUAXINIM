#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define MAXL 100001
typedef vector<int> vi;
#define db(x) cerr << #x << " = " << x << endl;

int N;
int c1[MAXN], c2[MAXN];
vector<int> d1, d2;
int b[MAXL], m;


void compute_prefix_function(vi& word, vi& pi) {
	pi.assign(word.size(), 0);
	pi[0] = -1;
	if (word.size() > 1) pi[1] = 0;
	int i = 2, k = 0;
	while (i < pi.size()) {
		if (word[i - 1] == word[k]) 
			pi[i++] = ++k;
		else if (k > 0) k = pi[k];
		else pi[i++] = 0;
	}
}


void kmpPre()
{
	int i = 0, j = -1;
	b[0] = -1;
	m = d2.size();
	while(i < m)
	{
		while(j >= 0 && d2[i] != d2[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}
	
	vi pi;
	compute_prefix_function(d2, pi);
	
	for (int i = 0; i < pi.size(); i++)
	{
		printf("(%d x %d)\n", pi[i], b[i]);
		if (pi[i] != b[i])
		{
			printf("ERRO DE PRECALC = %d (%d x %d)\n", i, pi[i], b[i]);
			exit(1);
		}
	}
	
}

bool kmpSearch()
{
	int i = 0, j = 0, n = d1.size();
	while(i < n)
	{
		while(j >= 0 && d1[i] != d2[j]) j = b[j];
		i++, j++;
		if(j == m)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	
	db(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &c1[i]);
	}
	sort(c1, c1 + N);
	c1[N] = c1[0] + 360000;
	d1.resize(2*N);
	for (int i = 0; i < N; i++)
	{
		d1[i] = (c1[i + 1] - c1[i] + 360000) % 360000;
		d1[i + N] = d1[i];
	}
	
	//~ printf("d1: ");
	//~ for (int i = 0; i < 2*N + 1; i++)
	//~ {
		//~ printf("%d ", d1[i]);
	//~ }
	//~ printf("\n");
	
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &c2[i]);
	}
	sort(c2, c2 + N);
	c2[N] = c2[0] + 360000;
	d2.resize(N);
	for (int i = 0; i < N; i++)
	{
		d2[i] = (c2[i + 1] - c2[i] + 360000) % 360000;
	}
	
	
	//~ printf("d2: ");
	//~ for (int i = 0; i < N; i++)
	//~ {
		//~ printf("%d ", d2[i]);
	//~ }
	//~ printf("\n");
	
	
	kmpPre();
	if (kmpSearch())
	{
		return !printf("possible\n");
	}
	
	
	printf("impossible\n");
	return 0;
}
