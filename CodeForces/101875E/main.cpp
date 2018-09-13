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

#define MAXN 451
#define INF 1000000000

int N, K;
int compressed[MAXN];
int n_chunks;
int dp[MAXN][MAXN];

int first_n(int n)
{
	return (n*(n+1))/2;
}

int cost(int size, int i)
{
	size -= i;
	int result = 0;
	
	if (size <= 0)
	{
		result = 0;
	}
	else if (i == 0)
	{
		result = first_n(size);
	}
	else
	{
		i++;
		int n_complete = size % i;
		int n_missing = i - n_complete;
		int missing_size = size/i;
	
		result = first_n(missing_size) * n_missing + first_n(missing_size + 1) * n_complete;
	}
	
	return result;
}

int get_min_effort(int idx, int T)
{
	if (idx == n_chunks)
	{
		return 0;
	}
	
	int &res = dp[idx][T];
	
	if (res != -1)
		return res;
		
	res = INF;
	for (int i = 0; i <= T && i <= compressed[idx]; i++)
	{
		res = min(res, get_min_effort(idx + 1, T - i) + cost(compressed[idx], i));
	}
	
	return res;
	
}


bool possible(int M)
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			dp[i][j] = -1;
		}
	}
	
	int min_effort = get_min_effort(0, M);
	
	db(min_effort);
	db(K);
	return min_effort <= K;
}

int solve()
{
	int upper = 450;
	int lower = 0;
	int best = 0;
	
	while (lower <= upper)
	{
		int mid = lower + (upper - lower) / 2;
		
		db(mid);
		
		if (possible(mid))
		{
			best = mid;
			upper = mid - 1;
		}
		else
		{
			lower = mid + 1;
		}
	}
	
	return best;
}

int main() 
{

	scanf("%d%d\n", &N, &K);
	
	int chunck_size = 0;
	char val;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%c", &val);
		
		if (val == '1')
		{
			++chunck_size;
		}
		else if (chunck_size != 0)
		{
			compressed[n_chunks] = chunck_size;
			chunck_size = 0;
			++n_chunks;
		}
	}
	
	if (chunck_size != 0)
	{
		compressed[n_chunks] = chunck_size;
		++n_chunks;
	}
	
	printf("%d\n", solve());
	
	return 0;
}
