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

struct Retangulo{
	
	int left_x, right_x, upper_y, lower_y;
	int id;
	
	Retangulo(){}
	void set(int x1, int y1, int x2, int y2, int id)
	{
		left_x = x1;
		right_x = x2;
		lower_y = y2;
		upper_y = y1;
		
		this->id = id;
	}
};

Retangulo vet_ret[100001];
vii X_vals;
int N;
set<pii> sweep_set;

int main() 
{
	
	scanf("%d", &N);
	int x1, y1, x2, y2;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		vet_ret[i].set(x1, y1, x2, y2, i);
		X_vals.pb({x1, -i});
		X_vals.pb({x2, i});
	}
	
	sort(all(X_vals));
	
	int ans = 0;
	for (int i = 0; i < (int)X_vals.size(); i++)
	{
		
		//~ int x = X_vals[i].first;
		int type = X_vals[i].second;
		int id = abs(X_vals[i].second);
		db(type);
		db(id);
		
		int upper = vet_ret[id].upper_y;
		int lower = vet_ret[id].lower_y;
		auto beg = sweep_set.lower_bound({lower, 0});
		auto end = sweep_set.upper_bound({upper, 0});
		
		db(lower);
		db(upper);
		
		if (type < 0)
		{
			db(sweep_set.size());
			while (beg != sweep_set.end() && beg != end)
			{
				auto aux = beg;
				++beg;
				sweep_set.erase(aux);
			}
			db(sweep_set.size());
			sweep_set.insert({vet_ret[id].upper_y, id});
			
			
		}
		else
		{
			db(sweep_set.size());
			db((*beg).first);
			db((*end).first);
			if (beg == end)
			{
				++ans;
			}
		}
		
	}
	
	printf("%d\n", ans);
	
	return 0;
}
