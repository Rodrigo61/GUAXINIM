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
	int N, M;
	scanf("%d%d", &N, &M);
	
	int left = 1, right = 16;
	int level = 0;
	
	while (1)
	{
		int mid = (left + right) / 2;
		
		if (N <= mid && M <= mid)
		{
			++level;
			right = mid;
		}
		else if (N >= mid + 1 && M >= mid + 1)
		{
			++level;
			left = mid + 1;
		}
		else
		{
			break;
		}
	}
	
	if (level == 0)
	{
		printf("final\n");
	}
	else if (level == 1)
	{
		printf("semifinal\n");
	}
	else if (level == 2)
	{
		printf("quartas\n");
	}
	else if (level == 3)
	{
		printf("oitavas\n");
	}
	
	
	return 0;
}
