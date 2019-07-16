#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

int main()
{
	int N;
	scanf("%d", &N);
	
	vi order = {0, 3, 1, 2};
	char val[] = {'D', 'A', 'C', 'B'};
	int o1 = N % 4;
	int o2 = (N + 1) % 4;
	int o3 = (N + 2) % 4;
	
	if (order[o1] > order[o2] && order[o1] > order[o3])
	{
		printf("0 %c\n", val[o1]);
	}
	else if (order[o2] > order[o1] && order[o2] > order[o3])
	{
		printf("1 %c\n", val[o2]);
	}
	else
	{
		printf("2 %c\n", val[o3]);
	}
	
}
