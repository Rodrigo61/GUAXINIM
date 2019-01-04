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

int freq[1000005];

int main() 
{

	int N;
	scanf("%d", &N);
	vi vet(N);
	ll sum = 0;
	int first = -1, second = -1;
	int first_i, second_i;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vet[i]);
		freq[vet[i]]++;
		db(freq[vet[i]]);
		sum += vet[i];
		
		if (vet[i] >= first)
		{
			second = first;
			first = vet[i];
			second_i = first_i;
			first_i = i;
		}
		else if (vet[i] > second)
		{
			second = vet[i];
			second_i = i;
		}
	}
	
	db(first);
	db(second);
	
	vi res;
	for (int i = 0; i < N; i++)
	{
		if (i == first_i && (sum - first == 2 * second))
		{
			db(sum - first);
			res.push_back(i);
		}
		else if (i != first_i && sum - vet[i] == 2 * first)
		{
			db(2 * first);
			db(sum - vet[i]);
			res.push_back(i);
		}
	}
	
	
	printf("%d\n", (int)res.size());
	for (auto i : res)
	{
		printf("%d ", i + 1);
	}
	
	return 0;
}
