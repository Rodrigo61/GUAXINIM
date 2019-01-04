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

#define MAXN 200005
#define fi first
#define se second

int N;
pair<int, int> vet[MAXN];
int prox[MAXN];
vi points[MAXN];

int main() 
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d", &vet[i].fi, &vet[i].se);
		points[vet[i].fi].pb(i);
		points[vet[i].se].pb(i);
	}
	
	if (N == 3)
	{
		printf("1 2 3\n");
		return 0;
	}
	
	for (int i = 1; i <= N; i++)
	{
		prox[i] = -1;
		if (vet[vet[i].fi].fi == vet[i].se || vet[vet[i].fi].se == vet[i].se)
		{
			if (vet[points[i][0]].fi == vet[i].fi || vet[points[i][0]].se == vet[i].fi
			  ||vet[points[i][1]].fi == vet[i].fi || vet[points[i][1]].se == vet[i].fi)
			{
				prox[i] = vet[i].fi;
			}
			else
			{
				prox[vet[i].fi] = i;
			}
			
		}
		else if (vet[vet[i].se].fi == vet[i].fi || vet[vet[i].se].se == vet[i].fi)
		{
			if (vet[points[i][0]].fi == vet[i].se || vet[points[i][0]].se == vet[i].se
			  ||vet[points[i][1]].fi == vet[i].se || vet[points[i][1]].se == vet[i].se)
			{
				prox[i] = vet[i].se;
			}
			else
			{
				prox[vet[i].se] = i;
			}
		}
		
	}
	
	int curr = 1;
	for (int i = 0; i < N; i++)
	{
		printf("%d ", curr);
		curr = prox[curr];
	}
	
	
	return 0;
}
