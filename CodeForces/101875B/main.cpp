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

vi Z_function(const string &s)
{
	int n = (int)s.size();
	vi z(n);
	
	for (int i = 1, l = 0, r = 0; i < n; ++i) 
	{
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
            
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
            
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
            
    }
    return z;
	
}

char aux[500001];

int main() 
{
	int sz;
	string s;
	
	scanf("%d\n%s", &sz, aux);
	s = aux;
	
	s += s;
	
	auto z = Z_function(s);
	//~ print_vector_debug(z);
	
	for (int i = 1; i < sz; ++i)
	{
		if (z[i] < sz && s[z[i] + i] < s[z[i]])
		{
			return !printf("No\n");
		}
	}
	
	printf("Yes\n");

	return 0;
}
