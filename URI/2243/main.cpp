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
	
	vi values(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &values[i]);
	}
	
	vi esq(N, 1), dir(N, 1);
	
	for (int i = 1; i < N; i++)
	{
		if (values[i] > esq[i - 1])
		{
			esq[i] = esq[i - 1] + 1;
		}
		else if (esq[i - 1] > 1)
		{
			esq[i] = values[i];
		}
		
	}
	
	for (int i = N - 2; i >= 0; i--)
	{
		if (values[i] > dir[i + 1])
		{
			dir[i] = dir[i + 1] + 1;
		}
		else if (dir[i + 1] > 1)
		{
			dir[i] = values[i];
		}
		
	}
	
	
	int maxi = 0;
	for (int i = 0; i < N; i++)
	{
		maxi = max(maxi, min(esq[i], dir[i]));
	}
	
	printf("%d\n", maxi);
	
	

	return 0;
}
