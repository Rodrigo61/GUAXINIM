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


int N, F;
vi periodos;

bool possible(int M)
{
	ll total = 0;
	for (auto &e : periodos){
		total += M / e;
	}
	
	return total >= F;
	
}

int solve()
{
	
	int upper = 100000001;
	int lower = 1;
	int best;
	
	while (lower <= upper)
	{
		int mid = lower + (upper - lower)/2;
		
		if (possible(mid))
		{
			best = mid;
			upper = mid - 1;
		}
		else
		{
			lower = mid + 1;
		}
	}
	
	return best;
	
}

int main() 
{
	
	scanf("%d%d", &N, &F);
	
	periodos.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &periodos[i]);
	}
	
	printf("%d\n", solve());
	
	
	return 0;
}
