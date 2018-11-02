#include<bits/stdc++.h>

using namespace std;

#define MAXN (int)1e5+5
string in;

int vet[MAXN];
int prec[MAXN];

int main()
{
	
	cin >> in;
	
	for (int i = 0; i < (int)in.size(); i++)
	{
		vet[i + 1] = in[i] - '0';
	}
	
	prec[1] = vet[1];
	for (int i = 2; i <= (int)in.size() ; i++)
	{
		prec[i] = prec[i - 1] ^ vet[i];
	}
	
	int last = prec[in.size() - 2];
	int c;
	
	for (int i = in.size() - 2; i >= 0; i--)
	{
		c = prec[i - 1] ^ last;
		
		if (c != vet[i])
		{
			return !printf("NO\n");
		}
		
		last ^= vet[i];
	}
	
	printf("YES\n");
	
	
	
	
	
	return 0;
}
