#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

struct point{
	int x, max_y, max_x, min_y, min_x, id;
};

bool cmp(const point &a, const point &b)
{
	return a.x < b.x;
}

int main() 
{
	
	int N, Q;
	while(scanf("%d%d", &N, &Q) != EOF)
	{
	
		db(N);
		db(Q);

		vi max_height(1000001, 200000);
		vector<point> vet_point;
		vet_point.reserve(N);
		
		int xa, ya, xb, yb;
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
			
			if (ya == yb)
			{
				for (int l = min(xa, xb); l <= max(xa, xb); l++)
				{
					max_height[l] = min(max_height[l], ya);
				}
				
				continue;
			}
			
			point a, b;
			
			a.x = xa;
			b.x = xb;
			a.id = b.id = i;
			
			if (ya > yb)
			{
				a.max_y = ya;
				a.max_x = xa;
				b.max_y = ya;
				b.max_x = xa;
				
				a.min_y = yb;
				a.min_x = xb;
				b.min_y = yb;
				b.min_x = xb;
			}
			else
			{
				a.max_y = yb;
				a.max_x = xb;
				b.max_y = yb;
				b.max_x = xb;
				
				a.min_y = ya;
				a.min_x = xa;
				b.min_y = ya;
				b.min_x = xa;
			}
			
			vet_point.pb(a);
			vet_point.pb(b);
			
		}
		
		db(vet_point.size());
		sort(all(vet_point), cmp);
		
		set<int> active_points;
		vector<pair<int, int>> escape_point(100001, {-1, -1});
		int last_x = 0;
		set<pair<int, int>, greater<pair<int, int>>> pq;
		
		for (auto &p : vet_point)
		{
			
			if (active_points.empty())
			{
				last_x = p.x;
			}
			
			if (p.min_y > max_height[p.min_x])
			{
				continue;
			}
			
			db(p.id);
			db(p.max_y);
			db(p.max_x);
			
			if (active_points.find(p.id) != active_points.end())
			{
				db("Sweep line");
				active_points.erase(p.id);
				
				pair<int, int> max_point = *pq.begin();
			
				db(max_point.second);
				db(last_x);
				db(p.x);
				for (int i = last_x; i <= p.x; i++)
				{
					escape_point[i] = {max_point.second, max_point.first};
				}
				
				last_x = p.x + 1;
				pq.erase({p.max_y, p.max_x});

			}
			else
			{
				active_points.insert(p.id);
				pq.insert({p.max_y, p.max_x});
			}
		}


		pair<int, int> null = {-1, -1};
		for (int i = 0; i < Q; i++)
		{
			int x;
			scanf("%d", &x);
			
			if (escape_point[x] == null)
			{
				escape_point[x] = {x, 0};
			}
			
			if (max_height[escape_point[x].first] != 200000 && max_height[escape_point[x].first] > escape_point[x].second)
			{
				printf("%d %d\n", escape_point[x].first, max_height[escape_point[x].first]);
			}
			else
			{
				printf("%d\n", escape_point[x].first);
			}
		}
	}
	

	return 0;
}
