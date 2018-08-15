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

set<int> dividers;

void calc_dividers(int num)
{

	dividers.clear();
	int sqr = sqrt(num);
	
	for (int i = 1; i <= sqr; i++)
	{
		if (num % i == 0)
		{
			dividers.insert(-1*i);
			dividers.insert(-1*num/i);
		}
	}
	
}


int main() 
{
	
	int N;
	
	while (scanf("%d", &N), N != -1)
	{

		calc_dividers(N - 1);
		bool ans = false;

		for (auto i : dividers)
		{
			i = -i;
			bool found = true;
			int val = N;
			db(i);
			for (int j = 0; j < i; j++)
			{
				db(val);
				if (val % i != 1) 
				{
					found = false;
					break;
				}
				
				val -= val/i + 1;
			}
			
			if (found && val % i == 0)
			{
				
				printf("%d coconuts, %d people and 1 monkey\n", N, i);
				ans = true;
				break;
			}
		}
	
		if (!ans)
		{
			printf("%d coconuts, no solution\n", N);
		}
		
	}

	return 0;
}
