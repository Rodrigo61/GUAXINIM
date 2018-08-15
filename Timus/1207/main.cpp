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

ll dot(pt A, pt B)
{
	return A.x*B.x + A.y*B.y;
}

ll cross(pt O, pt A, pt B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double angle(pt O, pt A, pt B)
{
	return abs(atan2(cross(O, A, B), dot(A-O, B-O)));
}


int main() 
{
	
	int N;
	
	scanf("%d", &N);
	
	vector<pt> points(N);
	int min_y = 1000000001;
	int min_id;
	
	
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		
		points[i].x = x;
		points[i].y = y;
		
		if (y < min_y)
		{
			min_y = y;
			min_id = i;
		}
	}
	
	pt refe(200, min_y);
	
	vector<pair<double, int>> vet;
	
	for (int i = 0; i < N; i++)
	{
		if (i == min_id) continue;
		
		db(points[i].x);
		db(points[i].y);
		
		db(i);
		db(angle(refe, points[min_id], points[i]));
		vet.pb({angle(refe, points[min_id], points[i]), i});
	}
	
	sort(all(vet));
	
	printf("%d %d\n", min_id + 1, vet[vet.size()/2].second + 1);
	
	return 0;
}
