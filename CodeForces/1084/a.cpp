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

int move_to(int a, int b, int x)
{
	db(a);
	db(b);
	db(x);
	db(abs(x - a));
	db(abs(a - b));
	return abs(x - a) + abs(a - b) + abs(x - b);
}

int main()
{
	int N;
	scanf("%d", &N);
	
	vi v(N + 1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &v[i]);
	}
	
	int mini = 9999999;
	for (int i = 1; i <= N; i++)
	{
		int res = 0;
		db(i);
		for (int j = 1; j <= N; j++)
		{
			db(j);
			res += v[j] * (move_to(j, 1, i) + move_to(1, j, i));
		}
		
		mini = min(mini, res);
		db(mini);
	}
	
	printf("%d\n", mini);
	
	return 0;
}
