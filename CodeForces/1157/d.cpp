#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 112345

int N, K;


int main()
{
	scanf("%d%d", &N, &K);
	
	vector<int> result(K);
	ll sum = 0;
	for (int i = 0; i < K; i++)
	{
		result[i] = i + 1;
		sum += result[i];
	}
	db(sum);
	
	if (sum > N)
	{
		return !printf("NO\n");
	}
	
	int factor = (N / sum);
	db(factor);
	sum = 0;
	for (int i = 0; i < K; i++)
	{
		db(result[i]);
		result[i] += (factor - 1);
		db(result[i]);
		sum += result[i];
	}
	
	int remainder = N % sum;
	db(remainder);
	
	int j = K - 1;
	for (int i = 0; i < remainder; i++)
	{
		while (j > 0 && result[j] + 1 > 2*result[j - 1])
		{
			j--;
			if (j == -1)
			{
				return !printf("NO\n");
			}
		}
		result[j]++;
		j = min(K - 1, j + 1);
		if (j < K && result[j] == result[j - 1])
		{
			result[j]++;

		}
	}

	bool possible = true;
	sum = result[0];
	for (int i = 1; i < K; i++)
	{
		sum += result[i];
		if (result[i] > 2*result[i-1] || result[i] <= result[i - 1])
		{
			possible = false;
			break;
		}
	}
	
	if (sum != N)
	{
		possible = false;
	}
	
	if (!possible)
	{
		return !printf("NO\n");
	}
	
	
	
	printf("YES\n");

	for (int i : result)
	{
		printf("%d ", i);
	}
	printf("\n");
	
}
