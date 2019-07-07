#include <bits/stdc++.h>

using namespace std;

#define MAXN 212345
#define pii pair<int, int>
#define db(x) //cerr << #x << " = " << x << endl;

int N;
int A[MAXN], B[MAXN];

void inc(map<pii, int> &m, pii frac)
{
	if (frac.second == 0)
	{
		return;
	}
	
	if (m.find(frac) == m.end())
		m[frac] = 0;
	m[frac]++;
	db("inc");
}

pii min_frac(int a, int b)
{
	if (a == 0)
	{
		return {0, 0};
	}
	
	int gcd = __gcd(a, b);
	return {b/gcd, a/gcd};
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &B[i]);
	}
	
	map<pii, int> freq;
	
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		inc(freq, min_frac(A[i], B[i]));
		
		if (A[i] == 0 && B[i] == 0)
		{
			total++;
		}
		
	}
	
	int maxi = 0;
	for (auto p : freq)
	{
		maxi = max(maxi, p.second);
	}
	printf("%d\n", total + maxi);
	
	
}
