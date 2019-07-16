#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>

int main()
{
	int N, M;
	scanf("%d%d\n", &N, &M);
	priority_queue<int> pq;
	
	for (int i = 1; i <= N; i++)
	{
		int c;
		scanf("%d", &c);
		if (c == 1)
		{
			pq.push(i);
		}
	}
	for (int i = 1; i <= M; i++)
	{
		int c;
		scanf("%d", &c);
		if (c == 1)
		{
			pq.push(i);
		}
	}

	vi res;
	while (!pq.empty())
	{
		int u = pq.top();
		pq.pop();
		
		if (!pq.empty() && pq.top() == u)
		{
			pq.pop();
			pq.push(u - 1);
		}
		else
		{
			res.pb(u);
		}
	}
	
	reverse(all(res));
	int num = 1;
	auto it = res.begin();
	while (it != res.end())
	{
		while (num < *it)
		{
			printf("0 ");
			num++;
		}
		printf("1 ");
		num++;
		++it;
	}
	printf("\n");
	
	
	
}
