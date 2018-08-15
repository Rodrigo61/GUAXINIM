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
	
	vector<pair<ll, ll>> points;
	for (int i = 0; i < N; i++)
	{
		ll u, v;
		scanf("%lld%lld", &u, &v);
		db(u);
		db(v);
		
		points.pb({u, 0});
		points.pb({v, 1});
	}
	
	sort(all(points));
	
	vll vet_count(N + 1, 0);
	ll count = 0;
	ll last_x = 0;
	
	for (int i = 0; i < 2 * N;)
	{
		pair<ll, ll> p = points[i];
		
		db("---");
		db(p.first);
		db(last_x);
		vet_count[count] += p.first - last_x;
		db(count);
		db(vet_count[count]);
		
		ll maxi_count = count;
		ll x = p.first;
		while ((i < 2 * N) && (p = points[i], p.first == x))
		{
			db("aqui");
			if (p.second == 1)
			{
				count--;
			}
			else
			{
				count++;
				maxi_count = count;
			}
			++i;
		}
		
		db(maxi_count);
		vet_count[maxi_count] += 1;
		db(vet_count[maxi_count]);
		
		last_x = x + 1;
		
	}
	
	for (int i = 1; i <= N; i++)
	{
		printf("%lld ", vet_count[i]);
	}
	
	

	return 0;
}
