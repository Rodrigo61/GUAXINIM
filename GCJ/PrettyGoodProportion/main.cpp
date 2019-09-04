#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define EPS 0.000000000001

int main()
{
	int T;
	scanf("%d", &T);
	int tc = 0;
	while (T--)
	{
		int N;
		double target;
		scanf("%d%lf\n", &N, &target);
		vi vals;
		for (int i = 0; i < N; i++)
		{
			char c;
			scanf("%c", &c);
			vals.pb(c - '0');
		}
		
		vector<pair<pii, int>> points;
		int acu_len = 0, acu_ones = 0;
		for (int i = 0; i < N; i++)
		{
			acu_len += 1;
			acu_ones += vals[i] == 1;
			points.pb({{acu_len, acu_ones}, i});
		}
		points.pb({{0, 0}, -1});
		
		sort(all(points), [=] (pair<pii, int> &a, pair<pii, int> &b){
			return a.fi.se - target * a.fi.fi > b.fi.se - target * b.fi.fi;
		});
		
		
		double best = INF;
		int best_idx = -2;
		
		for (int i = 0; i < N; i++)
		{
			double alpha =  ((double)points[i + 1].fi.se - points[i].fi.se) /
							  (points[i + 1].fi.fi - points[i].fi.fi);
			double new_diff = abs(target - alpha);
							  
			if (new_diff < best)
			{
				best = new_diff;
				best_idx = min(points[i].se, points[i + 1].se);
			}
			if (abs(new_diff - best) < EPS)
			{
				best_idx = min(best_idx, min(points[i].se, points[i + 1].se));
			}
		}
		
		printf("Case #%d: %d\n", ++tc, best_idx + 1);
	}
	
	
}
