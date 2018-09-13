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

struct Point
{
	ll x, y;
	Point(){}
	Point(ll x, ll y)
	{
		this->x = x;
		this->y = y;
	}
	Point operator+(Point B)
	{
		Point C;
		C.x = this->x + B.x;
		C.y = this->y + B.y;
		return C;
	}
	Point operator-(Point B)
	{
		Point C;
		C.x = this->x - B.x;
		C.y = this->y - B.y;
		return C;
	}
	bool operator==(Point B)
	{
		return this->x == B.x && this->y == B.y;
	}
};

ll cross(Point a, Point b, Point c)
{
	ll dx1 = a.x - b.x, dy1 = a.y - b.y;
	ll dx2 = c.x - b.x, dy2 = c.y - b.y;
	
	return dx1*dy2 - dx2*dy1;
}

struct Segment{
	
	Point p1, p2;
	int id;
	
	Segment(){}
	
	void set(Point a, Point b, int id)
	{
		this->id = id;
		
		if (a.x < b.x)
		{
			p1 = a;
			p2 = b;
		}
		else
		{
			p1 = b;
			p2 = a;
		}
	}
	
};

vector<Segment> vet_seg;
int n_seg;

bool cross_cmp(int id_a, int id_b)
{
	Segment &seg_a = vet_seg[id_a];
	Segment &seg_b = vet_seg[id_b];

	if (seg_a.p1.x > seg_b.p1.x)
	{
		return cross(seg_b.p1, seg_a.p1, seg_b.p2) > 0;
	}
	else
	{
		return cross(seg_a.p1, seg_b.p1, seg_a.p2) < 0;
	}
}


set<int, bool(*)(int, int)> set_seg(cross_cmp);
vector<vi> above_segs;
vi direct_water;
vii X_vals;
vi dp;

int get_next_seg(int id)
{
	auto it = set_seg.find(id);
	
	if (it != set_seg.end())
	{
		++it;
		return it != set_seg.end() ? *it:0;
	}
	
	return 0;
}

void sweep_line()
{
	sort(all(X_vals));
	
	int last_x = X_vals[0].first;
	
	for (int i = 0; i < (int)X_vals.size(); ++i)
	{
		int x = X_vals[i].first;

		if (!set_seg.empty())
		{
			int first = *set_seg.begin();
			direct_water[first] += x - last_x;
		}
		last_x = x;

		
		vii x_buffer;
		x_buffer.push_back(X_vals[i]);
		++i;
		
		while (i < (int)X_vals.size() && X_vals[i].first == x)
		{
			x_buffer.push_back(X_vals[i]);
			++i;
		}
		--i;
		
		
		// Insertions
		for (auto &p : x_buffer)
		{
			int type = p.second;
			int id = abs(type);
			
			if (type < 0)
			{
				set_seg.insert(id);
			}
			
		}
		
		for (auto &p : x_buffer)
		{
			int type = p.second;
			int id = abs(type);
			
			if (type < 0)
			{
				
				if (vet_seg[id].p1.y < vet_seg[id].p2.y)
				{
					int next_seg = get_next_seg(id);
					if (next_seg != 0)
					{
						above_segs[next_seg].push_back(id);
					}
				}
			}
			else
			{
				if (vet_seg[id].p2.y < vet_seg[id].p1.y)
				{
					int next_seg = get_next_seg(id);
					if (next_seg != 0)
					{
						above_segs[next_seg].push_back(id);
					}
				}
				
			}
		}
			
		// Erases
		for (auto &p : x_buffer)
		{
			int type = p.second;
			int id = abs(type);
			
			if (type > 0)
			{
				set_seg.erase(id);
			}
			
		}
	}
}

int total_water(int id)
{
	if (above_segs[id].empty())
	{
		return direct_water[id];
	}
	
	int &res = dp[id];
	if (res != -1)
	{
		return res;
	}
	
	res = direct_water[id];
	for (auto &v : above_segs[id])
	{
		res += total_water(v);
	}
	
	return res;
}


int main() 
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d", &n_seg);
		
		set_seg.clear();
		above_segs.clear();
		above_segs.resize(n_seg + 1);
		direct_water.clear();
		direct_water.resize(n_seg + 1);
		X_vals.clear();
		vet_seg.clear();
		vet_seg.resize(n_seg + 1);
		
		int x1, y1, x2, y2;
		for (int i = 1; i <= n_seg; i++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			vet_seg[i].set(Point(x1, y1), Point(x2, y2), i);
			X_vals.push_back({x1, -i});
			X_vals.push_back({x2, i});
		}
		
		sweep_line();
		
		
		dp.clear();
		dp.resize(n_seg + 1, -1);
		for (int i = 1; i <= n_seg; i++)
		{
			printf("%d\n", total_water(i));
		}
		
		
		
	}
	return 0;
}
