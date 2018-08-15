#include "bits/stdc++.h"
using namespace std;

#define db(x) //err << #x << " == " << x << endl
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

ll pow16[] = {1, 16, 256, 4096, 65536, 1048576, 16777216, 268435456};

ll val(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	
	return c - 'a' + 10;
}

char inv_val(ll digit)
{
	
	if (digit >= 0 && digit <= 9)
	{
		return digit + '0';
	}
	
	return digit + 'a' - 10;
	
}

ll to_decimal(string &s)
{
	ll result = 0;
	reverse(all(s));
	for (int i = 0; i < s.size(); i++)
	{
		result += val(s[i]) * pow16[i];
	}
	
	return result;
}

string to_hexa(ll num)
{
	string result;
	
	while (num)
	{
		int r = num % 16;
		result += inv_val(r);
		num /= 16;
	}
	
	reverse(all(result));
	return result;
}

int main() 
{
	char s[10];
	string a1, a2, a3;
	
	scanf("%s", s);
	a1 = s;
	scanf("%s", s);
	a2 = s;
	scanf("%s", s);
	a3 = s;
	
	ll R = to_decimal(a1);
	ll G = to_decimal(a2);
	ll B = to_decimal(a3);
	
	ll G2R = R / G;
	ll B2G = G / B;
	
	printf("%s\n", to_hexa(1 + (G2R)*(G2R) + (G2R)*(G2R)*B2G*B2G).c_str());
	
	return 0;
}
