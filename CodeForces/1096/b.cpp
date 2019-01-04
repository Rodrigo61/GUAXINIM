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

#define MOD 998244353 

int main() 
{
	string s;
	int n;
	
	cin >> n >> s;
	
	
	ll total_left = 1, total_right = 1;

	for (int i = 1; i < n && s[i] == s[0]; i++)
	{
		++total_left;
	}
	
	for (int i = n - 2; i >= 0 && s[i] == s[n - 1]; i--)
	{
		++total_right;
	}
	
	//~ db(total_left);
	//~ db(total_right);
	
	if (s[0] == s[n - 1])
	{
		//~ db(((total_right * total_left) % MOD));
		printf("%lld\n", (total_left + total_right + 1 + (((total_right) * (total_left)) % MOD)) % MOD);
	}
	else
	{
		printf("%lld\n", (total_left + total_right + 1) % MOD);
	}
	
	

	return 0;
}
