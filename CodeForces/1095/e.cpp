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

int main() 
{
	int n;
	string s;
	cin >> n >> s;
	
	vi r(n), a(n);
	
	int acu = 0;
	
	for (int i = 0; i < n; i++)
	{
		a[i] = acu;
		if (s[i] == '(')
		{
			++acu;
		}
		else
		{
			--acu;
		}
		
	}
	
	int rev = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		r[i] = rev;
		if (s[i] == '(')
		{
			rev++;
		}
		else
		{
			rev--;
		}
		
	}
	
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			if ()
			{
				++total;
			}
		}
	}
	
	

	return 0;
}
