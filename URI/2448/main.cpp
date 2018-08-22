#include <bits/stdc++.h>

using namespace std;


int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	map<int, int> val2ind;

	int val;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &val);
		
		val2ind[val] = i;
	}
	
	
	int curr_ind = 0;
	int dist = 0;
	int ind;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &val);
		
		ind = val2ind[val];
		dist += abs(curr_ind - ind);
		
		curr_ind = ind;
	}
	
	printf("%d\n", dist);
	
	
	return 0;
}
