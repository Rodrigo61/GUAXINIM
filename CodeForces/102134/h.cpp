#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 11234
#define ll long long

int vals[MAXN];

int main(){
	int N;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	ll curr_val = 1;
	ll total = 0;
	for (int i = 0; i < 32; i++)
	{
		ll curr_bit (1LL << i);
		ll one_count = 0;
		
		for (int j = 0; j < N; j++)
		{
			if ((vals[j] & curr_bit) != 0)
			{
				++one_count;
			}
		}
		
		ll zero_count = N - one_count;
		
		total += ((one_count * one_count * one_count)  + (3 * (one_count * zero_count * zero_count))) * curr_val;
		curr_val *= 2;
	}
	
	printf("%lld\n", total);
	
	return 0;
}
