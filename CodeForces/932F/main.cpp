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

struct line
{
	ll m, n;
    line(){}
    line(ll _m, ll _n):
        m(_m), n(_n){}
};

#define MAXN 200001

int N;
ll A[MAXN], B[MAXN];
vector<int> tree[MAXN];
line hull[MAXN];
line aux_hull[MAXN];
priority_queue<pair<double, int>> pq;
ll dp[MAXN];

ll y(int idx, ll x, line *hull) 
{
    return hull[idx].m*x + hull[idx].n;
}

double intersection(line t, line r) 
{
    double num = double(r.n - t.n);
    double den = double(t.m - r.m);
    return num / den;
}

int insertline(line l, int init, int end, line *hull)
{
	int hullSize = end - init;
	
	while(hullSize >= 2 && ( intersection(l, hull[init + hullSize-2]) < intersection(hull[init + hullSize-1], hull[init + hullSize-2]) ) ) {
        hullSize--;
    }
    hull[ init + hullSize++ ] = l;
    
    return init + hullSize;
}


ll bb_query(int x, int init, int end, line *hull)
{
	
	//~ printf("bb_query: x = %d,  init = %d,  end = %d\n", x, init, end);
	
	int hullSize = end - init;
	
	if (hullSize == 1)
	{
		//~ printf("bb_query: y(0, x, hull) = %lld\n", y(0, x, hull));
		return y(init, x, hull);
	}
	
	//~ printf("bb_queyr: intersection(hull[end - 1], hull[end - 2]) = %lf\n", intersection(hull[end - 1], hull[end - 2]));
	if (x >= intersection(hull[end - 1], hull[end - 2]))
	{
		return y(end - 1, x, hull);
	}
	
	int hi = end - 2;
	int lo = init;
	int best = init;
	
	//~ printf("bb_query: hi = %d,  lo = %d\n", hi, lo);
	
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
	
	return y(best, x, hull);
}

void prune_tree(int u, int p)
{
	auto it = find(all(tree[u]), p);
	
	if (it != tree[u].end())
	{
		tree[u].erase(it);
	}
	
	for (int v : tree[u])
		prune_tree(v, u);
}


int merge_k_hulls(vii &ranges)
{
	int very_beg = MAXN;
	int size = ranges.size();
	
	//~ printf("merge_k_hulls: size = %d\n", size);
	
	for (int i = 0; i < size; i++)
	{
		pq.push({hull[ranges[i].first].m, i});
		db(ranges[i].first);
		very_beg = min(very_beg, ranges[i].first);
		
		//~ printf("order : ");
		//~ for (int j = ranges[i].first; j < ranges[i].second; ++j)
		//~ {
			//~ printf("%d ", hull[j]);
		//~ }
		//~ printf("\n");
	}

	//~ printf("merge_k_hulls: very_beg = %d\n", very_beg);
	
	int aux_sz = 0;
	while (!pq.empty())
	{
		int id = pq.top().second;
		pq.pop();
		
		//~ printf("merge_k_hulls: id = %d\n", id);	
		
		int i = ranges[id].first;
		
		
		
		//~ printf("merge_k_hulls: i = %d\n", i);	
		
		db(hull[i].m);
		//~ printf("mege_k_hulls: hull[i].m = %lld\n", hull[i].m);
		aux_sz = insertline(hull[i], 0, aux_sz, aux_hull);
		
		//~ printf("merge_k_hulls: aux_sz = %d\n", aux_sz);	
		
		ranges[id].first++;
		
		if (ranges[id].first < ranges[id].second)
		{
			i = ranges[id].first;
			pq.push({hull[i].m, id});
		}
	}
	
	
	for (int i = 0; i <= aux_sz; i++)
	{
		hull[very_beg + i] = aux_hull[i];
	}
	
	return very_beg + aux_sz;
	
	
}


pii solve(int u, int last_it)
{
	int init_it = last_it;
	
	if (tree[u].empty())
	{
		dp[u] = 0;
		last_it = insertline(line(B[u], dp[u]), init_it, last_it, hull);
		return {init_it, last_it};
	}
	
	vii ranges(tree[u].size());
	
	for (int i = 0; i < (int)tree[u].size(); ++i)
	{
		ranges[i] = solve(tree[u][i], last_it);
		last_it = ranges[i].second;
	}
	
	last_it = merge_k_hulls(ranges);
	
	dp[u] = bb_query(A[u], init_it, last_it, hull);

	ranges.clear();
	ranges.resize(2);
	ranges[0] = {init_it, last_it};
	
	last_it = insertline(line(B[u], dp[u]), last_it, last_it, hull);
	ranges[1] = {last_it - 1, last_it};
	
	last_it = merge_k_hulls(ranges);
	
	//~ printf("solve: u = %d dp[u] = %lld\n", u, dp[u]);
	//~ printf("solve: u = %d ret = (%d, %d)\n", u, init_it, last_it);
	return {init_it, last_it};
	
	
}


int main() 
{

	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &A[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &B[i]);
	}
	
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d", &u, &v);
		
		tree[u].pb(v);
		tree[v].pb(u);
	}
	
	prune_tree(1, 0);
	solve(1, 0);
	
	for (int i = 1; i <= N; i++)
	{
		printf("%lld ", dp[i]);
	}
	printf("\n");
	
	
	return 0;
}
