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

#define MAXN  100005

string hard = "hard";
int N;
string s;
ll vals[MAXN];
int vis[MAXN][5];
ll dp[MAXN][5];

ll solve(int idx, int pos)
{
	
	if (idx == N)
	{
		return 0;
	}
	
	if (vis[idx][pos])
	{
		return dp[idx][pos];
	}
	vis[idx][pos] = 1;
	
	ll res = 0;
	if (s[idx] != hard[pos])
	{
		res = solve(idx + 1, pos);
	}
	else
	{
		if (pos < 3)
		{
			res = min(solve(idx + 1, pos + 1), solve(idx + 1, pos) + vals[idx]);
		}
		else
		{
			res = solve(idx + 1, pos) + vals[idx];
		}
	}
	dp[idx][pos] = res;
	return res;
}

int main() 
{
	
	scanf("%d", &N);
	char aux[N + 1];
	scanf("%s", aux);
	s = aux;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	printf("%lld\n", solve(0, 0));

	return 0;
}
