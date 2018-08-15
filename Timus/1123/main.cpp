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

bool palin(const string &s)
{

	int i = 0;
	int j = s.size() - 1;
	
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		
		++i;
		--j;
	}
	
	return true;
}

int main() 
{

	string s;
	cin >> s;
	
	string t = s.substr(0, s.size()/2);
	string aux = t;
	reverse(all(aux));
	
	if (s.size() & 1)
	{
		t += s[s.size()/2];
	}
	t += aux;
	
	//~ db(s);
	//~ db(t);
	int it = s.size()/2;
	
	if (t < s)
	{
		while (s[it] == '9')
		{
			--it;
		}
		
		t[it]++;
		if (it != s.size() - it - 1)
		{
			t[s.size() - it - 1]++;
		}
		
		for (int i = it + 1; i < s.size() - it - 1; i++)
		{
			t[i] = '0';
		}
		
		
	}
	
	cout << t << endl;
	return 0;
}
