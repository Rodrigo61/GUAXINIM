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

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

void solve()
{
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "No negative cycle found.";
    } else {
		
		//~ printf("init x = %d\n", x);
        //~ for (int i = 0; i < n; ++i)
        //~ {
			//~ printf("init x = %d & p[x] = %d\n", x, p[x]);
            //~ x = p[x];
            //~ printf("end x = %d & p[x] = %d\n", x, p[x]);
		//~ }

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

int main() 
{

	n = 6;
	m = 8;
	
	edges.push_back(Edge{0, 1, 1});
	edges.push_back(Edge{1, 2, 1});
	edges.push_back(Edge{2, 0, -2});
	edges.push_back(Edge{2, 3, 2});
	edges.push_back(Edge{4, 2, 4});
	edges.push_back(Edge{0, 5, -3});
	edges.push_back(Edge{5, 3, 3});
	edges.push_back(Edge{5, 4, -2});
	
	solve();
	return 0;
}
