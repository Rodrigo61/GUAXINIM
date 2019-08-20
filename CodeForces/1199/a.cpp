#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

 
int main()
{
	int N, X, Y;
	scanf("%d%d%d", &N, &X, &Y);
	vi vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	for (int i = 0; i < N; i++)
	{
		bool poss = true;
		for (int j = 1; i - j >= 0 && j <= X; j++)
		{
			if (vals[i - j] <= vals[i])
			{
				poss = false;
				break;
			}
		}
		for (int j = 1; i + j < N && j <= Y; j++)
		{
			if (vals[i + j] <= vals[i])
			{
				poss = false;
				break;
			}
		}
		
		if (poss)
		{
			return !printf("%d\n", i + 1);
		}
	}
	
	
}
