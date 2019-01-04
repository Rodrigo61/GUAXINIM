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

#define MAXN 200005

int N;
map<int, int> mapa;
vi freq;

int solve(int curr)
{
	auto it = freq.begin();
	int res = 0;
	while (it = lower_bound(it, freq.end(), curr), it != freq.end())
	{
		res += curr;
		curr *= 2;
		++it;
	}
	
	return res;
}

int main() 
{
	scanf("%d", &N);
	
	int v;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v);
		mapa[v]++;
	}
	
	for (auto i : mapa)
	{
		freq.push_back(i.second);
	}
	sort(all(freq));
	
	int maxi = 0;
	for (int i = 1; i <= N; i++)
	{
		maxi = max(maxi, solve(i));
	}
	
	printf("%d\n", maxi);
	
	return 0;
}
