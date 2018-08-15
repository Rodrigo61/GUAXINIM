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
	int primes[] = {2, 3, 5, 7};
	
	set<int> box;
	box.insert(1);
	
	for (auto prime : primes)
	{
		for (int num : box)
		{
			for (ll i = num; i < 2000000001; i *= prime)
			{
				box.insert(i);
			}	
		}
		
	}
	
	int N;
	while (scanf("%d", &N), N)
	{
		string aux = to_string(N);
		
		string suffix;
		
		if (aux.back() == '1')
		{
			suffix = "st";
		}
		else if (aux.back() == '2' && N != 12)
		{
			suffix = "nd";
		}
		else if (aux.back() == '3' && N != 13)
		{
			suffix = "rd";
		}
		else
		{
			suffix = "th";
		}
		
		if (aux.size() >= 2 && aux[aux.size() - 2] == '1')
		{
			suffix = "th";
		}
		
		printf("The %d%s humble number is %d.\n", N, suffix.c_str(), *next(box.begin(), N - 1));
		
	}

	return 0;
}
