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

int N;
vi changes;
string s, t;

void solve(int idx)
{
	db(idx);
	db(t);
	db(s);
	
	if (idx == N) return;
	if (s[idx] != t[idx]) {
		int it = idx;
		for (it = idx; it < N; ++it)
		{
			if (s[it] == t[idx])
			{
				break;
			}
		}
		db(it);
		
		while (it > idx)
		{
			changes.pb(it);
			swap(s[it - 1], s[it]);
			--it;
		}
	}
	
	solve(idx + 1);
}

int main() 
{
	
	cin >> N >> s >> t;
	
	string a = s, b = t;
	sort(all(a));
	sort(all(b));
	
	if (a != b)
	{
		return !printf("-1\n");
	}
	
	if (s == t)
	{
		return !printf("0\n");
	}
	
	
	solve(0);
	printf("%d\n", changes.size());
	for (int i = 0; i < changes.size(); i++)
	{
		printf("%d ", changes[i]);
	}
	
	return 0;

}
