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
#define MAXN 200005

int freq[MAXN];
int N, K;
vi aux, res;

bool possible(int M)
{
	int it = 0;
	for (int i = 0; i < MAXN; i++)
	{
		//~ db(i);
		//~ db(freq[i]);
		if (freq[i] >= M)
		{
			int rep = freq[i]/M;
			for (int j = 0; j < rep && it < K; j++)
			{
				aux[it] = i;
				++it;
			}
		}
		
		if (it == K)
		{
			break;
		}
	}
	
	db(it);
	return it == K;
}

void solve()
{
	int upper = N;
	int lower = 1;
	int mid;
	aux.resize(K);
	res.resize(K);
	
	while (lower <= upper)
	{
		
		mid = lower + (upper - lower) / 2;
		db(upper);
		db(lower);
		db(mid);

		if (possible(mid))
		{
			db("possible");
			res = aux;
			lower = mid + 1;
		}
		else
		{
			db("impossible");
			upper = mid - 1;
		}
	}
}

int main() 
{
	scanf("%d%d", &N, &K);
	
	int v;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v);
		freq[v]++;
	}
	
	solve();
	
	for (int i : res)
	{
		printf("%d ", i);
	}
	
	
	return 0;
}
