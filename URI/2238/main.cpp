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
	
	int A, B, C, D;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	
	int sqr = sqrt(C);
	vi complementary;
	
	for (int i = 1; i <= sqr; i++)
	{
		if (C % i == 0)
		{
			db(i);
			if (i % A == 0 && i % B != 0 && D % i != 0)
			{
				return !printf("%d\n", i);
			}
			
			int j = C/ i;
			complementary.pb(j);
		}
	}
	
	db("complementary");
	reverse(all(complementary));
	for (int i : complementary)
	{
		if (C % i == 0)
		{
			db(i);
			if (i % A == 0 && i % B != 0 && D % i != 0)
			{
				return !printf("%d\n", i);
			}
			
			int j = C/ i;
			complementary.pb(j);
		}
	}
	
	printf("-1\n");
	return 0;
}
