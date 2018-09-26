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

#define MAXN 100001
#define SQRN 320
#define int long long

ll N, Q;
vi tree[MAXN];
int node_height[MAXN];

int curr_time;
int beg_time[MAXN], end_time[MAXN];
int time2node[MAXN];

int sqr;
int block_sum[SQRN];
int h_acu[SQRN][MAXN];
int h_freq[SQRN][MAXN];


void ett(int u)
{
	beg_time[u] = curr_time;
	
	for (int v : tree[u])
	{
		ett(v);
	}
	
	end_time[u] = curr_time;
	time2node[curr_time] = u;
	++curr_time;
}

void sqrt_dfs(int u, int dist)
{
	h_freq[end_time[u]/sqr][dist]++;
	node_height[u] = dist;
	
	for (int v : tree[u])
	{
		sqrt_dfs(v, dist + 1);
	}
}

int get_sum(int L, int R)
{
	int c_l = L/sqr;
	int c_r = R/sqr;

	int sum = 0;
	
	db(L);
	db(R);
	db(c_l);
	db(c_r);
	
	if (c_l == c_r)
	{
		for (int i = L; i <= R; i++)
		{
			int node = time2node[i];
			sum += h_acu[c_l][node_height[node]];
		}
	}
	else
	{
		for (int i = L, end = (c_l + 1) * sqr; i < end; ++i)
		{
			int node = time2node[i];
			sum += h_acu[c_l][node_height[node]];
		}
		//~ printf("sum1 = %d\n", sum);
		for (int i = c_l + 1; i < c_r; ++i)
		{
			sum += block_sum[i];
		}
		//~ printf("sum2 = %d\n", sum);
		for (int i = (c_r) * sqr; i < R + 1; ++i)
		{
			int node = time2node[i];
			db(i);
			db(node);
			db(node_height[node]);
			db(h_acu[c_r][node_height[node]]);
			sum += h_acu[c_r][node_height[node]];
		}
		//~ printf("sum3 = %lld\n", sum);
		
	}
	
	return sum;
}

void update_height(int h, int val)
{
	for (int i = 0; i < sqr; i++)
	{
		if (h_freq[i][h])
		{
			db(h);
			db(i);
			h_acu[i][h] += val;
		}
		block_sum[i] += val * h_freq[i][h];
	}
	
}


main() 
{
	scanf("%lld%lld", &N, &Q);
	
	int u, v;
	
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%lld%lld", &u, &v);
		tree[u].pb(v);
	}
	
	ett(1);
	
	sqr = (int) sqrt(N + .0) + 1;
	sqrt_dfs(1, 0);
	
	int cmd, X, L, Y;
	for (int i = 0; i < Q; i++)
	{
		scanf("%lld", &cmd);
		db(cmd);
		if (cmd == 1)
		{
			
			scanf("%lld%lld", &L, &Y);
			update_height(L, Y);
		}
		else
		{
			scanf("%lld", &X);
			printf("%lld\n", get_sum(beg_time[X], end_time[X]));
		}
		
	}
	
	
	return 0;
}
