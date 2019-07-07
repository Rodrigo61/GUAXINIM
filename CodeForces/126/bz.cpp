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

int main() 
{
	
	char aux[1000001];
	string s;
	
	scanf("%s", aux);
	s = aux;
	
	auto v = Z_function(s);
	int max_z = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (v[i] == (int)v.size() - i && max_z >= v[i])
		{
			return !printf("%s\n", s.substr(0, v[i]).c_str());
		}
		max_z = max(max_z, v[i]);
	}
	
	printf("Just a legend\n");
	
	
	return 0;
}
