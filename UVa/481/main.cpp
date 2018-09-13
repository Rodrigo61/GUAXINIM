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

vi LIS(vll &values) {

    int sz = values.size();
    vi res(sz);
    vll ends_list(sz);
    int max_size = 0;
    
    for (int i = 0; i < sz; ++i) {
        
        int pos = distance(ends_list.begin(), lower_bound(ends_list.begin(), ends_list.begin() + max_size, values[i]));

        ends_list[pos] = values[i];
        
		if (pos == max_size)
		{
            max_size = pos + 1;
		}
        
		res[i] = pos + 1;
    }
    
    return res;

}


int main() 
{
	
	vll values;
	ll val;
	
	while (scanf("%lld", &val) != EOF)
	{
		values.pb(val);
	}
	
	vi res = LIS(values);
	//~ print_vector_debug(res);
	
	int greater = 0;
	int greater_end = 0;
	
	for (int i = 0; i < (int)res.size(); i++)
	{
		if (res[i] >= greater)
		{
			greater = res[i];
			greater_end = i;
		}
	}
	
	
	printf("%d\n-\n", greater);
	
	vll ans;
	ll last_val = numeric_limits<long long>::max();
	for (int i = greater_end; greater > 0 && i >= 0; i--)
	{
		if (res[i] == greater && values[i] < last_val)
		{
			ans.pb(values[i]);
			greater--;
			last_val = values[i];
		}
	}
	
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		printf("%lld\n", ans[i]);
	}
	

	return 0;
}
