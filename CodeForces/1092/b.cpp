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

int main() 
{
	int n;
	scanf("%d", &n);
	vi vet(n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	sort(all(vet));
	int diff = 0;
	for (int i = 1; i < n; i += 2)
	{
		diff += vet[i] - vet[i-1];
	}
	
	printf("%d\n", diff);
	return 0;
}
