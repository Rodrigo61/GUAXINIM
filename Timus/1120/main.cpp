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

#define EPS 0.000000001

int main() 
{
	
	int N;
	scanf("%d", &N);
	
	set<int> divisores;
	
	N *= 2;
	
	for (int i = 1; i <= sqrt(N); i++)
	{
		if ((N) % i == 0)
		{
			divisores.insert(i);
			divisores.insert(N/i);
		}
	}
	
	vi divs;
	divs.assign(all(divisores));
	
	reverse(all(divs));
	
	for (auto &p : divs)
	{
		if ((N/p - p + 1) > 0 && (N/p - p + 1) % 2 == 0)
		{
			return !printf("%d %d", (N/p - p + 1)/2, p);
		}
		
	}
	
	
	return 0;
}
