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


#define MAXN 1005
#define fi first
#define se second

int N;
pair<int, int> ob[MAXN];
pair<int, int> points[MAXN];

int main() 
{
	scanf("%d", &N);
	db(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &ob[i].first, &ob[i].se);
	}
	db("d1");
	
	int x, y;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &x, &y);
		points[i].fi = x;
		points[i].se = y;
	}
	sort(points, points + N);
	
	for (int j = 0; j < N; j++)
	{
		x = ob[0].fi + points[j].fi;
		y = ob[0].se + points[j].se;
		
		db(x);
		db(y);
		
		bool poss = true;
		for (int i = 1; i < N; i++)
		{
			db(x - ob[i].fi);
			db(y - ob[i].se);
			if (!binary_search(points, points + N, make_pair(x - ob[i].fi, y - ob[i].se)))
			{
				poss = false;
				break;
			}
		}
		
		if (poss)
		{
			return !printf("%d %d\n", x, y);
		}
	}
	
	
	return 0;
}
