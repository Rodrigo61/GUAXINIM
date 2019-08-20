#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

#define MAXN 1123

struct max_queue
{
	queue<ll> q;
	deque<ll> s;
	
	int size()
	{
		return (int)q.size();
	}
	
	void push(ll val)
	{
		while (!s.empty() && s.back() < val)
			s.pop_back();
		s.push_back(val);
		
		q.push(val);
	}
	
	void pop()
	{
		ll u = q.front();
		q.pop();
		
		if (!s.empty() && s.front() == u)
			s.pop_front();
	}
	
	ll get_max()
	{
		return s.front();
	}
	
};

ll grid[MAXN][MAXN];
ll grid_sum[MAXN][MAXN];
ll grid_max[MAXN][MAXN];
int N, M;


void calc_sum()
{
	grid_sum[0][0] = grid[0][0];
	for (int i = 1; i < N; i++)
	{
		grid_sum[i][0] = grid_sum[i - 1][0] + grid[i][0];
	}
	for (int j = 1; j < M; j++)
	{
		grid_sum[0][j] = grid_sum[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			grid_sum[i][j] = grid[i][j] + grid_sum[i - 1][j] + grid_sum[i][j - 1] - grid_sum[i - 1][j - 1];
		}
	}
}

ll get_sum(int i, int j, int A, int B)
{
	int y = i;	
	int x = j + B - 1;
	ll res = grid_sum[y][x];
	if (x - B >= 0)
		res -= grid_sum[y][x - B];
	if (y - A >= 0)
		res -= grid_sum[y - A][x];
	if (x - B >= 0 && y - A >= 0)
		res += grid_sum[y - A][x - B];
	return res;
}

int main()
{
	scanf("%d%d",&N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%lld", &grid[i][j]);
		}
	}

	calc_sum();

	int Q;
	scanf("%d", &Q);
	
	for (int q = 0; q < Q; q++)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		
		// 1D
		for (int i = 0; i < N; i++)
		{
			max_queue mq;
			for (int j = 0; j < M; j++)
			{
				mq.push(grid[i][j]);
				if (mq.size() > B)
					mq.pop();
				if (mq.size() == B)
					grid_max[i][j - B + 1] = mq.get_max();
			}
		}

		//2D
		ll res = INF;
		for (int j = 0; j + B - 1 < M; j++)
		{
			max_queue mq;
			for (int i = 0; i < N; i++)
			{
				mq.push(grid_max[i][j]);
				if (mq.size() > A)
					mq.pop();
				if (mq.size() == A)
				{
					ll rect_sum = get_sum(i, j, A, B);
					ll maxi = mq.get_max();
					ll exp_sum = maxi * A * B;
					res = min(res, exp_sum - rect_sum);
				}
			}
		}
		
		printf("%lld\n", res);
	}
	
}
