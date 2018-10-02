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

#define INF (ll)1e18
#define MAXN 1001
using namespace std;

int N, M;

ll F[MAXN][MAXN];
int P[MAXN][MAXN];
ll cost[MAXN][MAXN];
int vals[MAXN];

ll prefix[MAXN];

ll sum(int i, int j)
{
	--i;
	
	return prefix[j] - prefix[i];
}

void calc_prefix()
{
	prefix[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		db(vals[i]);
		prefix[i] = prefix[i - 1] + vals[i];
	}
	
	//~ for (int i = 1; i <= N; i++)
	//~ {
		//~ printf("%lld ", prefix[i]);
	//~ }
	//~ printf("\n");
	
	
}

void pre_calc_cost()
{
	
	calc_prefix();
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			cost[i][j] = 0;
		}
	}
	
	for (int i = 0; i <= N; i++)
	{
		cost[i][i] = 0;
	}
	
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			cost[i][j] = cost[i][j - 1] + vals[j] * sum(i, j - 1);

			//~ printf("%lld ", cost[i][j]);
		}
		//~ printf("\n");
	}
	//~ printf("\n");
	
}

void fill(int g, int l1, int l2, int p1, int p2) 
{
    int lm, k;
    
    db(g);
    db(l1);
    db(l2);
    db(p1);
    db(p2);
	
	if (l1 > l2) 
		return;
	
	lm = (l1+l2)/2;
    P[g][lm] = -1;
    F[g][lm] = INF;
    for (k = p1; k <= p2; k++) 
	{
		db(lm);
        ll new_cost = F[g-1][k] + cost[k+1][lm];
        if (new_cost < F[g][lm]) 
		{
            F[g][lm] = new_cost;
            P[g][lm] = k;
        }
    }
    
	fill(g, l1, lm-1, p1, P[g][lm]);
    fill(g, lm+1, l2, P[g][lm], p2);
} 

int main() 
{
	
	while (scanf("%d%d", &N, &M), N+M)
	{
		
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &vals[i]);
		}
		
		M++;
		pre_calc_cost();
		
		for (int i = 1; i <= N; i++)
		{
			F[1][i] = cost[1][i];
		}
		
		for (int i = 2; i <= M; i++)
		{
			fill (i, 1, N, 1, N);
		}
		
		
		printf("%lld\n", F[M][N]);
		
	}

	return 0;
}
