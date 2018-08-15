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

	int N;

		
	while (scanf("%d", &N) != EOF)
	{
		
		vi A[3], B[3];
		
		ll aux;
		
		for (int i = 0; i < N; i++)
		{
			scanf("%lld", &aux);
			A[i%3].pb(aux);
		}
		
		for (int i = 0; i < N; i++)
		{
			scanf("%lld", &aux);
			B[i%3].pb(aux);
		}
		
		
		ll ans[3] = {0,0,0};
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < A[i].size(); k++)
				{
					for (int l = 0; l < B[j].size(); l++)
					{
						ans[(i+j)%3] += A[i][k] * B[j][l];
					}
				}
			}
		}
		
	
		printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
	
	}


	return 0;
}
