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
	int N;
	scanf("%d", &N);
	vi vet(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	int result = 0;
	for (int i = 1; i < N - 1; i++)
	{
		if (vet[i] == 0 && vet[i - 1] == 1 && vet[i + 1] == 1)
		{
			++result;
			vet[i + 1] = 0;
		}
	}
	
	
	printf("%d\n", result);
	return 0;
}
