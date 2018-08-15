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

vi divisores(int n)
{

	int sqr = sqrt(n);
	
	
	set<int> div;
	for (int i = 1; i <= sqr; i++)
	{
		if (n % i == 0)
		{
			div.insert(i);
			div.insert(n/i);
		}
	}
	
	vi res;
	res.assign(all(div));
	reverse(all(res));
	return res;
	
	
}

int main() 
{
	int N;
	
	while (scanf("%d", &N), N != -1)
	{
		//~ db(N);
		for (int d : divisores(2*N))
		{
			if ((2 * N - d*d + d) % (2 * d) == 0 && (2 * N - d*d + d) / (2 * d) > 0)
			{
				//~ db(d);
				int a1 = (2 * N - d*d + d) / (2 * d);
				int an = a1 + d - 1;
				printf("%d = %d + ... + %d\n", N, a1, an);
				break;
			}
		}
	}

	return 0;
}
