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

struct line
{
	ll m, n;
    line(){}
    line(ll _m, ll _n):
        m(_m), n(_n){}
};

#define MAXN 1000001

line hull[MAXN];
int hullSize, hullPtr;

ll y(int idx, ll x) 
{
    return hull[idx].m*x + hull[idx].n;
}

double intersection(line t, line r) 
{
    double num = double(r.n - t.n);
    double den = double(t.m - r.m);
    return num / den;
}

void insertline(line l)
{
	while(hullSize >= 2 && ( intersection(l, hull[hullSize-2]) < intersection(hull[hullSize-1], hull[hullSize-2]) ) ) {
        if (hullPtr == hullSize - 1) hullPtr--;
        hullSize--;
    }
    hull[ hullSize++ ] = l;
}

ll query(int x)
{
	while(hullPtr+1 < hullSize && y(hullPtr, x) < y(hullPtr+1, x)) hullPtr++;
	
	return y(hullPtr, x);
}

ll bb_query(int x)
{
	if (hullSize == 1)
	{
		return y(0, x);
	}
	
	if (x >= intersection(hull[hullSize - 1], hull[hullSize - 2]))
	{
		return y(hullSize - 1, x);
	}
	
	int hi = hullSize - 2;
	int lo = 0;
	int best = 0;
	
	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		
		if (x <= intersection(hull[mid], hull[mid + 1]))
		{
			hi = mid - 1;
			best = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	
	return y(best, x);
}

ll a, b, c, N;
ll X[MAXN];
ll prefix[MAXN];

int main() 
{
	int T;
	scanf("%d", &T);
	
	for (int w = 0; w < T; w++)
	{
		hullPtr = hullSize = 0;
		
		scanf("%lld%lld%lld%lld", &N, &a, &b, &c);
		
		ll acu = 0;
		for (int j = 0; j < N; j++)
		{
			scanf("%lld", &X[j]);
			acu += X[j];
			prefix[j] = acu;
		}
		
		ll dp[N];
		fill(dp, dp + N, 0);
		
		insertline(line(0, 0));
		ll ans = 0;
		
		for (int i = 0; i < N; i++)
		{
			ll indep = (a * prefix[i] * prefix[i]) + (b * prefix[i]) + c;
			ans = bb_query(prefix[i]) + indep;
			
			if (i < N - 1)
			{
				insertline(line(-2 * a * prefix[i], ans + (a * prefix[i] * prefix[i]) - (b * prefix[i])));
			}
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
