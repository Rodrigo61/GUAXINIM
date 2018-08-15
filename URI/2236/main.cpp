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

int N, Q;
vi min_reachable;
vi adj;

int set_min_reachable(int u)
{
	if (min_reachable[u] == -1)
	{
		min_reachable[u] = u;
		min_reachable[u] = min(u, set_min_reachable(adj[u]));
	}
	
	return min_reachable[u];
}

void init_min_reachable()
{
	min_reachable.assign(N, -1);
	for (int i = 0; i < N; i++)
	{
		if (min_reachable[i] == -1)
		{
			set_min_reachable(i);
		}
	}
}

ll tree[50001];

void update(int i, int val)
{
	++i;
	while (i <= N)
	{
		tree[i] += val;
		i += (i&-i);
	}
}

int sum(int i)
{
	int s = 0;
	++i;
	while (i > 0)
	{
		s += tree[i];
		i -= (i & -i);
	}
	return s;
}


struct query
{
	int L, R, A, ind, BL;
};

int ans[100001];
query queries[100001];

bool possible(int M, int L, int R)
{
	db(sum(M));
	return sum(M) <= (R - L + 1) / 2;
}
int solve(int L, int R)
{
	db("solve");
	int upper = N - 1;
	int lower = 0;
	int best = 0;
	
	
	while (lower <= upper)
	{
		int mid = lower + (upper - lower)/2;
		
		db(upper);
		db(lower);
		db(mid);
	
		if (possible(mid, L, R))
		{
			if (sum(best) < sum(mid))
			{
				best = mid;
				db(best);
			} else if (sum(best) == sum(mid))
			{
				best = min(mid, best);
			}
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
	}
	
	return best;
}

bool possible2(int M, int L, int R)
{
	db(sum(M));
	db((R - L + 1) / 2);
	return sum(M) >= (R - L + 1) / 2;
}
int solve2(int L, int R)
{
	db("solve2");
	int upper = N - 1;
	int lower = 0;
	int best = N - 1;
	
	
	while (lower <= upper)
	{
		int mid = lower + (upper - lower)/2;
		
		db(upper);
		db(lower);
		db(mid);
	
		if (possible2(mid, L, R))
		{
			if (sum(best) > sum(mid))
			{
				best = mid;
				db(best);
			}else if (sum(best) == sum(mid))
			{
				best = min(best, mid);
			}
			upper = mid - 1;
		}
		else
		{
			lower = mid + 1;
		}
	}
	
	return best;
}

bool cmp(query x, query y)
{
	if(x.BL != y.BL)
		return x.BL < y.BL;
	return x.R < y.R;
}

void MO()
{
	int i, L, R, curL, curR;
	
	sort(queries,queries+Q, cmp);
	
	curL = queries[0].L;
	curR = queries[0].R;
	
	multiset<int> mset;
	for(int i = curL; i <= curR; i++)
	{
		db(min_reachable[i]);
		update(min_reachable[i], 1);
		mset.insert(min_reachable[i]);
	}
	
	int s1 = solve(curL, curR);
	auto it = mset.lower_bound(s1);
	if (*it != s1)
	{
		if (it != mset.begin())
		{
			--it;
			s1 = *it;
		}
		else
		{
			s1 = 0;
		}
	}
	db(s1);
	int s2 = solve2(curL, curR);
	it = mset.lower_bound(s2);
	if (*it != s2)
	{
		if (it != mset.begin())
		{
			--it;
			s2 = *it;
		}
		else
		{
			s2 = 0;
		}
	}
	db(s2);
	int diff1 = abs(2 * sum(s1) - (curR - curL + 1));
	int diff2 = abs(2 * sum(s2) - (curR - curL + 1));
	
	if (diff1 <= diff2)
	{
		ans[queries[0].ind] = s1;	
	}
	else
	{
		ans[queries[0].ind] = s2;	
	}
	
	
	for(i = 1; i < Q; i++)
	{
		L = queries[i].L;
		R = queries[i].R;
		
		while(curL < L)
		{
			mset.erase(mset.find(min_reachable[curL]));
			update(min_reachable[curL], -1);
			curL++;
		}
			
		while (curL > L)
		{
			curL--;
			mset.insert(min_reachable[curL]);
			update(min_reachable[curL], 1);
		}
	
		while (curR < R)
		{
			curR++;
			mset.insert(min_reachable[curR]);
			update(min_reachable[curR], 1);
		}
		
		while (curR > R)
		{
			mset.erase(mset.find(min_reachable[curR]));
			update(min_reachable[curR], -1);
			curR--;
		}
		
		int s1 = solve(curL, curR);
		auto it = mset.lower_bound(s1);
		if (*it != s1)
		{
			if (it != mset.begin())
			{
				--it;
				s1 = *it;
			}
			else
			{
				s1 = 0;
			}
		}
		db(s1);
		int s2 = solve2(curL, curR);
		it = mset.lower_bound(s2);
		if (*it != s2)
		{
			
			if (it != mset.begin())
			{
				--it;
				s2 = *it;
			}
			else
			{
				s2 = 0;
			}
		}
		db(s2);
		int diff1 = abs(2 * sum(s1) - (curR - curL + 1));
		int diff2 = abs(2 * sum(s2) - (curR - curL + 1));
		
		if (diff1 <= diff2)
		{
			ans[queries[i].ind] = s1;	
		}
		else
		{
			ans[queries[i].ind] = s2;	
		}
		
	}
}


int main() 
{	
		
	scanf("%d%d", &N, &Q);
	adj.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &adj[i]);
		--adj[i];
	}
	
	init_min_reachable();
	//~ print_vector_debug(min_reachable);
	
	int blocks = sqrt(N);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d%d", &queries[i].L, &queries[i].R);
		--queries[i].L, --queries[i].R;
		
		queries[i].ind = i;
		queries[i].BL = queries[i].L / blocks;
	}	
	
	db("MO");
	MO();
	
	for (int i = 0; i < Q; i++)
	{
		printf("%d\n", ans[i] + 1);
	}
	
	return 0;
}
