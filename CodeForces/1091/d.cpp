#include "bits/stdc++.h"
using namespace std;

#define db(x) cout << #x << " == " << x << endl
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

vi total;

int main() 
{
	int N;
	scanf("%d", &N);
	int MOD = (N*(N+1))/2;
	vi seq;
	for (int i = 1; i <= N; i++)
	{
		seq.pb(i);
	}
	
	do
	{
		total.insert(total.end(), all(seq));
	} while (next_permutation(all(seq)));
	
	
	int val = MOD;
	int beg = 0, end = N - 1;
	int res = 1;
	int yes = 1;
	int a = 0;
	int contador = 0;
	while (end < total.size())
	{
		++end;
		val += total[end];
		val -= total[beg];
		++beg;
		
		if (val == MOD) 
		{
			++res;
			++yes;
		}
		else
		{
			if (yes > 0)
				db(yes);
			if (yes == 1)
			{
				db(contador + 1);
				contador = 0;
				db("------------------");
			}
			else if (yes > 0)
			{
				++contador;
			}
			yes = 0;
		}
	}
	
	printf("%d\n", res);
	//~ vi sum;
	//~ vi mod;
	//~ int acu = 0;
	//~ for (int i = 0; i < total.size(); i++)
	//~ {
		//~ sum.pb(acu+total[i]);
		//~ acu += total[i];
		//~ mod.pb(sum[i] % MOD);
	//~ }
	
	//~ print_vector_debug(mod);
	//~ acu = 0;
	//~ for (int i = 0; i < MOD; i++)
	//~ {
		//~ printf("%d = %d\n", i, count(all(mod), i) - 1);
		//~ acu += count(all(mod), i) - 1;
	//~ }
	//~ db(acu);
	
	
	return 0;
}
