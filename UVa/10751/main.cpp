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

#define sqr 1.414213562

int N;

int main() 
{
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		if (i != 0)
		{
			printf("\n");
		}
		scanf("%d", &N);
		
		if (N == 1)
		{
			printf("0.000\n\n");
		}
		else
		{
			int normal = 4 * (N - 1);
			int diag = N * N - normal;
			
			printf("%.3lf\n", normal + diag * sqr);
		}
	}
	

	return 0;
}
