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

int ang;

bool possible(int n)
{

	if (((n - 2) * 180) % n != 0)
	{
		return false;
	}
	
	int base = ((n - 2) * 180)/n;
	int ac = (180 - base)/2;
	
	db(n);
	db(base);
	db(ac);
	db((base - ang) % ac);
	
	if (ac == 0)
	{
		return false;
	}
		
	if (base < ang)
	{
		return false;
	}

	
	return (base - ang) % ac == 0;
}

int main() 
{
	int tc;
	scanf("%d", &tc);
	
	while (tc--)
	{
		scanf("%d", &ang);
		
		db(ang);
		bool poss = false;
		
		if (ang == 179)
		{
			printf("360\n");
			continue;
		}
		for (int i = 3; i <= 360; i++)
		{
			if (possible(i))
			{
				poss = true;
				printf("%d\n", i);
				break;
			}
		}
		
		if (!poss)
		{
			printf("-1\n");
		}
	
	}

	return 0;
}
