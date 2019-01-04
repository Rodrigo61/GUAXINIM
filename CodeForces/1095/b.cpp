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
	int n;
	scanf("%d\n", &n);
	
	vi vals(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	int maxi = *max_element(all(vals));
	int mini = *min_element(all(vals));
	
	vals.erase(find(all(vals), maxi));
	int aux = *max_element(all(vals)) - *min_element(all(vals));
	vals.push_back(maxi);
	
	vals.erase(find(all(vals), mini));
	aux = min(*max_element(all(vals)) - *min_element(all(vals)), aux);
	
	printf("%d\n", aux);

	return 0;
}
