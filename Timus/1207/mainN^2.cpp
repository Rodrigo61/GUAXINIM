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

struct pt
{
	ll x, y;
	pt(){}
	pt(ll x, ll y)
	{
		this->x = x;
		this->y = y;
	}
	pt operator+(pt B)
	{
		pt C;
		C.x = this->x + B.x;
		C.y = this->y + B.y;
		return C;
	}
	pt operator-(pt B)
	{
		pt C;
		C.x = this->x - B.x;
		C.y = this->y - B.y;
		return C;
	}
	bool operator==(pt B)
	{
		return this->x == B.x && this->y == B.y;
	}
};

ll cross(pt v, pt w) {
	//~ db(v.x*w.y - v.y*w.x);
	return v.x*w.y - v.y*w.x;
}

ll ccw(pt a, pt b, pt c)
{
	//~ db(cross(b - a, c - a));
	return cross(b - a, c - a);
}


int main() 
{
	
	ll N;
	
	scanf("%lld", &N);
	
	vector<pt> points(N);
	ll min_y = 1000000001;
	int min_id;
	
	for (ll i = 0; i < N; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		
		points[i].x = x;
		points[i].y = y;
		
		//~ db(points[i].x);
		//~ db(points[i].y);
		
		if (y < min_y)
		{
			min_y = y;
			min_id = i;
		}
		
	}
	
	for (int i = 0; i < N; i++)
	{
		if (i == min_id)
		{
			continue;
		}
		
		int left = 0, right = 0;
		for (int j = 0; j < N; j++)
		{
			if (j == min_id || j == i)
			{
				continue;
			}
			
			//~ db(i);
			//~ db(points[i].x);
			//~ db(points[i].y);
			//~ db(min_id);
			
			//~ db(ccw(points[min_id], points[i], points[j]));
			if (ccw(points[min_id], points[i], points[j]) > 0)
			{
				++left;
			}
			else
			{
				++right;
			}
		}
		
		//~ db(left);
		//~ db(right);
		
		if (left == right)
		{
			return !printf("%d %d\n", min_id + 1, i + 1);
		}
		
	}
	
	
	return 0;
}
