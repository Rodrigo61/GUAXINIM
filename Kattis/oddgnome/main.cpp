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

int main() 
{
	
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		int G;
		scanf("%d", &G);
		
		
		int val;
		int last_val;
		scanf("%d", &last_val);
		bool found = false;
		for (int j = 1; j < G; j++)
		{
			scanf("%d", &val);
			
			//~ db(last_val);
			//~ db(val);
			if (!found && val != last_val + 1)
			{
				printf("%d\n", j + 1);
				found = true;
			}
			
			last_val = val;
		}
		
	}
	

	return 0;
}
