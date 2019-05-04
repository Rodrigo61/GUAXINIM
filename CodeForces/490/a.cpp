#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	int N;
	scanf("%d", &N);
	
	vector<queue<int>> q(3);
	
	int v;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v);
		q[v - 1].push(i + 1);
	}
	
	int mini = min({q[0].size(), q[1].size(), q[2].size()});
		
	printf("%d\n", mini);
	for (int i = 0; i < mini; i++)
	{
		printf("%d %d %d\n", q[0].front(), q[1].front(), q[2].front());
		q[0].pop();
		q[1].pop();
		q[2].pop();
	}
	
	
	
	return 0;
}
