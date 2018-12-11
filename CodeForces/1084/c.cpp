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

#define MOD 1000000007

string s;

int main()
{
	
	cin >> s;
	
	ll acu_right = 0, acu_left = 0;
	
	int j;
	ll total = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == 'a')
		{
			j = i;
			total = 1;
			break;
		}
	}
	
	db(s);
	
	acu_left = 1;
	for (int i = j - 1; i >= 0; i--)
	{
		if (s[i] == 'b')
		{
			db("found b");
			acu_right = (acu_left + acu_right) % MOD;
			acu_left = 0;
		}
		else if (s[i] == 'a')
		{
			db("found a");
			ll sum = (1 + acu_right) % MOD;
			total = (total + sum) % MOD;
			acu_left = (acu_left + sum) % MOD;
		}
		db(total);
	}
	
	printf("%lld\n", total);
	
	
	return 0;
}
