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

int N;
ll tree[1000001];

void update(int i, ll val)
{
	while (i <= N)
	{
		tree[i] += val;
		i += (i&-i);
	}
}

ll sum(int i)
{
	ll s = 0;
	while (i > 0)
	{
		s += tree[i];
		i -= (i & -i);
	}
	return s;
}



int main() 
{
	
	while (scanf("%d", &N) != EOF)
	{
		db(N);
		
		memset(tree, 0, sizeof(tree));
		ll prefix;
		
		int vals[N];
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &vals[i]);
		}
		
		
		ll left_bigger[N];
		for (int i = 0; i < N; i++)
		{
			prefix = sum(N) - sum(vals[i]);
			left_bigger[i] = prefix;
			update(vals[i], 1);
		}
		
		memset(tree, 0, sizeof(tree));
		ll right_lower[N];
		for (int i = N - 1; i >= 0; i--)
		{
			prefix = sum(vals[i]);
			right_lower[i] = prefix;
			update(vals[i], 1);
		}
		
		ll total = 0;
		for (int i = 1; i < N - 1; i++)
		{
			if (left_bigger[i] != 0 && right_lower[i] != 0)
			{
				total += left_bigger[i] * right_lower[i];
			}
		}
		
		
		printf("%lld\n", total);

	}
	return 0;
}
