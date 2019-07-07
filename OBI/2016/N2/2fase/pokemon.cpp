#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A;
	scanf("%d", &A);
	vector<int> v(3);
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	
	int total = 0;
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (total + v[i] <= A)
		{
			total += v[i];
			count++;
		}
	}
	
	printf("%d\n", count);
}
