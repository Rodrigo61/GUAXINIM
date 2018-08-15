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

	int N, M;
	scanf("%d%d", &N, &M);
	
	vi filled(M + 1, 0);
	
	for (int i = 0; i < N; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		
		for (int j = u; j <= v; j++)
		{
			filled[j] = 1;
		}
	}
	
	db("aqui");
	int acu = 0;
	for (int i = 1; i <= M; i++)
	{
		db(i);
		if (filled[i] == 0)
		{
			++acu;
		}
	}
	
	printf("%d\n", acu);
	for (int i = 1; i <= M; i++)
	{
		if (filled[i] == 0)
		{
			printf("%d ", i);
		}
	}
	
	return 0;
}
