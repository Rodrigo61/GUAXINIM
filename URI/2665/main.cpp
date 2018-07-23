#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


int N;
int X[3], Y[3];
vii points;
vector<vi> dp;

int ccw(int x1, int y1, int x2, int y2)
{
	return x1*y2 - x2*y1;
}

int pointInPolygon(int x, int y) 
{
	int windingNumber = 0;
	for(int i = 0; i < 3; i++) 
	{
		if (x == X[i] && y == Y[i]) 
			return 0;
		int j = (i+1)%3;
		if(Y[i] == y && Y[j] == y) 
		{
			if(min(X[i], X[j]) <= x && x <= max(X[i], X[j])) 
				return 0;
		} 
		else 
		{
			bool below = Y[i] < y;
			if (below != (Y[j] < y)) 
			{
				int orientation = ccw(X[i]-x, Y[i]-y, X[j]-x, Y[j]-y);
				if (orientation == 0) 
					return 0;
				if (below == (orientation > 0)) 
					windingNumber += below ? 1 : -1;
			}
		}
	}
	return windingNumber == 0 ? 1 : -1;
	
}

int solve(int idx, int last_point_id) 
{
	
	if (idx == N)
	{
		return 0;
	}
	
	db(idx);
	db(last_point_id);
	if (last_point_id != -1 && dp[idx][last_point_id] != -1)
	{
		return dp[idx][last_point_id];
	}
	
	
	int not_take = solve(idx + 1, last_point_id);
	int take = -99999;
	
	if (last_point_id == -1)
	{
		take = solve(idx + 1, idx);
	}
	else
	{
		X[2] = points[last_point_id].first;
		Y[2] = points[last_point_id].second;
		if (pointInPolygon(points[idx].first, points[idx].second) == -1)
		{
			take = solve(idx + 1, idx);
		}
	}
	
	if (last_point_id != -1)
	{
		dp[idx][last_point_id] = max(not_take, take + 1);
	}
	
	return max(not_take, take + 1);
}

int main() 
{
	
	scanf("%d%d%d", &N, &X[0], &X[1]);
	
	points.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &points[i].second, &points[i].first);
	}
	
	sort(all(points));
	reverse(all(points));
	for (int i = 0; i < N; i++)
	{
		swap(points[i].first, points[i].second);
	}
	
	dp.resize(N, vi(N, -1));
	printf("%d\n", solve(0, -1));
	
	return 0;
}
