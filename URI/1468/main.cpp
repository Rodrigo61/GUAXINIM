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

bool cross_cmp(int, int);


pii NULL_PAIR = {-1, -1};
int N, C;
vector<Segment> vet_seg;
vector<int> vet_query;
set<int, bool(*)(int, int)> activated_seg(cross_cmp);
vi next_seg;
vi first_seg;
vector<pair<int, pii>> X_vals;
vector<pii> dp;


bool cross_cmp(int id_a, int id_b)
{
	Segment &seg_a = vet_seg.at(id_a);
	Segment &seg_b = vet_seg.at(id_b);

	if (seg_a.p1.x >= seg_b.p1.x)
	{
		return cross(seg_b.p1, seg_a.p1, seg_b.p2) < 0;
	}
	else
	{
		return cross(seg_a.p1, seg_b.p1, seg_a.p2) > 0;
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
	sort(all(X_vals));
	
	for (int i = 0; i < (int)X_vals.size(); i++)
	{
		pair<int, pii> p = X_vals.at(i);
		int type = p.second.second;
		int id = p.second.first;

		if (id == 0) //Query point
		{
		
			db(type);
			if (!activated_seg.empty())
			{
				first_seg.at(type) = *activated_seg.begin();
			}
			
		}
		else
		{
			int seg_id = abs(id);
			Segment &seg = vet_seg.at(seg_id);
			
			if (id < 0) // Ponto mais a esquerda desse segmento
			{
				activated_seg.insert(seg_id);
				
				if (seg.p1.y > seg.p2.y) // Verifica se é ponto de escape
				{
					next_seg.at(seg_id) = get_next_seg(seg_id);
				}
				
			}
			else if (id > 0) // Ponto mais a direita desse segmento
			{
				if (seg.p1.y < seg.p2.y) // Verifica se é ponto de escape
				{
					next_seg.at(seg_id) = get_next_seg(seg_id);
				}
				
				activated_seg.erase(seg_id);
			}
		}	
	}
	
}

pii get_exit_point(int curr_seg)
{
	
	if (vet_seg.at(next_seg.at(curr_seg)).p1.y == vet_seg.at(next_seg.at(curr_seg)).p2.y) // verifica se o proximo é segmento horizontal
	{
		// Verifica o ponto de escape para determinar o X final
		if (vet_seg.at(curr_seg).p1.y > vet_seg.at(curr_seg).p2.y)
		{
			return {vet_seg.at(curr_seg).p1.x, vet_seg.at(next_seg.at(curr_seg)).p1.y};
		}
		else
		{
			return {vet_seg.at(curr_seg).p2.x, vet_seg.at(next_seg.at(curr_seg)).p1.y};
		}
		
	}	
	
	pii &res = dp.at(curr_seg);
	if (res != NULL_PAIR)
	{
		return res;
	}

	res = get_exit_point(next_seg.at(curr_seg));
	return res;
}


int main() 
{

	while (scanf("%d%d", &N, &C) != EOF)
	{
		
		activated_seg.clear();
		vet_seg.clear();
		vet_seg.resize(N + 1);
		vet_query.clear();
		vet_query.resize(C);

		next_seg.clear();
		next_seg.resize(N + 1);
		
		first_seg.clear();
		first_seg.resize(C);
		
		X_vals.clear();
		X_vals.resize((2 * N + C));
		
		dp.clear();
		dp.resize(N + 1, NULL_PAIR);
		
		ll x1, y1, x2, y2;
		for (int i = 0; i < N; i++)
		{
			scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
			vet_seg.at(i + 1).set(Point(x1, y1), Point(x2, y2), (i + 1));
			X_vals.at(i) = {vet_seg.at(i + 1).p1.x, {-(i + 1), 1}};
			X_vals.at(i + N) = {vet_seg.at(i + 1).p2.x, {(i + 1), 1}};
		}
		
		for (int i = 0; i < C; i++)
		{
			scanf("%d", &vet_query.at(i));
			X_vals.at(2 * N + i) = {vet_query.at(i), {0, i}};
		}
		
		sweep_line();
		
		db(C);
		for (int i = 0; i < C; i++)
		{
			db(vet_query.at(i));
			db(first_seg.size());
			int first = first_seg.at(i);
			db(first);
			db(i);
			if (first == 0) // Nao há segmentos acima, trivial
			{
				printf("%d\n", vet_query.at(i));
			}
			else if (vet_seg.at(first).p1.y == vet_seg.at(first).p2.y) // Primeiro segmento já é um horizontal, trivial
			{
				
				printf("%d %lld\n", vet_query.at(i), vet_seg.at(first).p2.y);
			}
			else
			{
				db("oi");
				pii exit = get_exit_point(first);
				
				if (exit.second != 0)
				{
					printf("%d %d\n", exit.first, exit.second);
				}
				else
				{
					printf("%d\n", exit.first);
				}
				db("OIe");
				
			}
			
		}
		
	}

	return 0;
}
