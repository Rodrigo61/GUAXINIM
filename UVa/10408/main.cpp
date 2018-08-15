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

int main() 
{

	int N, K;
	
	while (scanf("%d%d", &N, &K) != EOF)
	{
		
		vector<pair<double, pair<int, int>>> seq;
		
		db(N);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (__gcd(i, j) == 1)
				{
					db(i);
					seq.pb({(double)j/i, {j, i}});
				}
			}
		}
		
		seq.pb({1, {1, 1}});
		
		sort(all(seq));
		printf("%d/%d\n", seq[K - 1].second.first, seq[K - 1].second.second);
	}
	return 0;
}
