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

	int N;
	
	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &N), N)
	{
		
		int sum = 0;
		int sqr = sqrt(N);
		
		for (int i = 1; i <= sqr; i++)
		{
			if (N % i == 0)
			{
				if (i != N)
				{
					sum += i;
				}
				if (N/i != i && N/i != N)
				{
					sum += N/i;
				}
				
			}
		}
		
		if (sum == N)
		{
			printf("%5d  PERFECT\n", N);
		}
		else if (sum < N)
		{
			printf("%5d  DEFICIENT\n", N);
		}
		else
		{
			printf("%5d  ABUNDANT\n", N);
		}
	}
	printf("END OF OUTPUT\n");


	return 0;
}
