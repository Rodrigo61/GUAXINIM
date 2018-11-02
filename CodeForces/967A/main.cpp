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

int N, S;

int c_min = 0;

int main() 
{

	scanf("%d%d", &N, &S);
	
	int h, m;
	int n_min;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &h, &m);
		
		n_min = h * 60 + m;
		
		db(i);
		db(c_min);
		db(n_min);
		db(n_min - c_min);
		
		if (i == 0 && n_min >= S + 1)
		{
			return !printf("%d %d", 0, 0);
		}
		
		
		if (n_min - c_min >= 2*S + 2)
		{
			c_min += S + 1;
			db(c_min + 2 + S);
			db(n_min);
			return !printf("%d %d", c_min/60, c_min % 60);
		}
		
		c_min = n_min;
		
	}
		
	c_min += 1 + S;
	printf("%d %d", c_min/60, (c_min) % 60);

	return 0;
}
