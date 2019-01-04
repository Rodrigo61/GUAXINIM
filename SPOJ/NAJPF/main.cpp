#include<bits/stdc++.h>
#define MAXL 100001
#define ll long long

using namespace std;

string P, T;
int b[MAXL], m;
char aux[1000005];

void kmpPre()
{
	int i = 0, j = -1;
	b[0] = -1;
	m = P.length();
	while( i < m)
	{
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}
}

vector<int> kmpSearch()
{
	vector<int> res;
	int i = 0, j = 0, n = T.size();
	while(i < n)
	{
		while(j >= 0 && T[i] != P[j]) j = b[j];
		i++, j++;
		if(j == m)
		{
			res.push_back(i - m + 1);
			j = b[j];
		}
	}
	
	return res;
}

int main()
{
	
	int N;
	scanf("%d\n", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%s", aux);
		T = aux;
		scanf("%s", aux);
		P = aux;
		
		kmpPre();
		auto r = kmpSearch();
		if (r.empty())
			printf("Not Found\n");
		else
		{
			printf("%d\n", (int)r.size());
			for (int n : r)
			{
				printf("%d ", n);
			}
			printf("\n");
		}
		
			
		
		if (i != N - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
