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
	int t;
	scanf("%d", &t);
	
	int n, k;
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &n, &k);
		string s;
		
		char it = 0;
		for (int j = 0; j < n; j++)
		{
			s += it + 'a';
			it = (it + 1) % k;
		}
		
		printf("%s\n", s.c_str());
	}
	
	return 0;
}
