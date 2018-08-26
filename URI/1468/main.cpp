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

ll cross(Point O, Point A, Point B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

//~ ll cross(Point a, Point b, Point c)
//~ {
	//~ ll dx1 = a.x - b.x, dy1 = a.y - b.y;
	//~ ll dx2 = c.x - b.x, dy2 = c.y - b.y;
	
	//~ return dx1*dy2 - dx2*dy1;
//~ }

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

bool cross_cmp(int, int);


pii NULL_PAIR = {-1, -1};
int N, C;
Segment vet_seg[100005];
int vet_query[100005];
set<int, bool(*)(int, int)> activated_seg(cross_cmp);
int next_seg[100005];
int first_seg[1000005];
pii X_vals[200005];
pii dp[100005];


bool cross_cmp(int id_a, int id_b)
{
	Segment &seg_a = vet_seg[id_a];
	Segment &seg_b = vet_seg[id_b];

	if (seg_a.p1.x >= seg_b.p1.x)
	{
		return cross(seg_b.p1, seg_a.p1, seg_b.p2) > 0;
	}
	else
	{
		return cross(seg_a.p1, seg_b.p1, seg_a.p2) < 0;
	}
}

int get_next_seg(int id)
{
	auto it = activated_seg.find(id);
	
	if (it != activated_seg.end())
	{
		++it;
		return it != activated_seg.end() ? *it:0;
	}
	
	return 0;
	
}

void sweep_line()
{
	int sz = (2 * N + C);
	sort(X_vals, X_vals + sz);
	
	for (int i = 0; i < sz; i++)
	{
		pii p = X_vals[i];

		if (p.second == 0)
		{
			// init point
			if (!activated_seg.empty())
			{
				first_seg[p.first] = *activated_seg.begin();
			}
			
		}
		else
		{
			int seg_id = abs(p.second);
			Segment &seg = vet_seg[seg_id];
			
			if (p.second < 0)
			{
				activated_seg.insert(seg_id);
				if (seg.p1.y > seg.p2.y)
				{
					next_seg[seg_id] = get_next_seg(seg_id);
					db(next_seg[seg_id]);
				}
				
			}
			else if (p.second > 0)
			{
				if (seg.p1.y < seg.p2.y)
				{
					next_seg[seg_id] = get_next_seg(seg_id);
					db(next_seg[seg_id]);
				}
				
				activated_seg.erase(seg_id);
			}
		}	
	}
	
}

pii get_exit_point(int curr_seg)
{
	if (vet_seg[next_seg[curr_seg]].p1.y == vet_seg[next_seg[curr_seg]].p2.y)
	{
		// next horizontal block
		if (vet_seg[curr_seg].p1.y > vet_seg[curr_seg].p2.y)
		{
			return {vet_seg[curr_seg].p1.x, vet_seg[next_seg[curr_seg]].p1.y};
		}
		else
		{
			return {vet_seg[curr_seg].p2.x, vet_seg[next_seg[curr_seg]].p1.y};
		}
		
	}	
	
	pii &res = dp[curr_seg];
	if (res != NULL_PAIR)
	{
		return res;
	}
	
	res = get_exit_point(next_seg[curr_seg]);
	return res;
}


int main() 
{

	while (scanf("%d%d", &N, &C) != EOF)
	{
		
		activated_seg.clear();
		
		ll x1, y1, x2, y2;
		for (int i = 0; i < N; i++)
		{
			scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
			vet_seg[i + 1].set(Point(x1, y1), Point(x2, y2), (i + 1));
			X_vals[i] = {vet_seg[i + 1].p1.x, -(i + 1)};
			X_vals[i + N] = {vet_seg[i + 1].p2.x, (i + 1)};
		}
		
		for (int i = 0; i < C; i++)
		{
			scanf("%d", &vet_query[i]);
			X_vals[2 * N + i] = {vet_query[i], 0};
		}
		db("d2");
		
		sweep_line();
		
		for (int i = 0; i < 100001; i++)
		{
			dp[i] = NULL_PAIR;
		}
		
		for (int i = 0; i < C; i++)
		{
			int first = first_seg[vet_query[i]];
			
			db(first);
			if (first == 0)
			{
				printf("%d\n", vet_query[i]);
			}
			else if (vet_seg[first].p1.y == vet_seg[first].p2.y)
			{
				
				printf("%d %lld\n", vet_query[i], vet_seg[first].p2.y);
			}
			else
			{
				pii exit = get_exit_point(first);
				
				if (exit.second != 0)
				{
					printf("%d %d\n", exit.first, exit.second);
				}
				else
				{
					printf("%d\n", exit.first);
				}
				
			}
			
		}
		
	}

	return 0;
}
