#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>
#include <random>
#define db(x) //cerr << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef long long ll;
typedef long double ld;

#define INF 2000000000
#define LLINF 9000000000000000000

struct edge {
	int v;
	list<edge>::iterator rev;
	int m;
	bool isred = false;
	edge(int _v, int _m) : v(_v), m(_m) {};
};

void add_edge(vector< list<edge> >& adj, int u, int v, int m) {
	adj[u].push_front(edge(v, m));
	adj[v].push_front(edge(u, m));
	adj[u].begin()->rev = adj[v].begin();
	adj[v].begin()->rev = adj[u].begin();
}

void remove_edge(vector< list<edge> >& adj, int s, list<edge>::iterator e) {
	adj[e->v].erase(e->rev);
	adj[s].erase(e);
}

bool eulerian_circuit(vector< list<edge> >& adj, vii& c, vb& vis, vi& deg, int start = 0) {
	stack<ii> st; 
	st.push({ start, -1 });
	
	while (!st.empty()) {
		int u = st.top().first, m = st.top().second;
		vis[u] = true;

		if (adj[u].empty()) {
			c.push_back({ u, m });
			st.pop();
		}
		else {
			st.push({ adj[u].front().v, adj[u].front().m });
			vis[adj[u].front().v] = true;
			deg[u]--;
			deg[adj[u].front().v]--;
			remove_edge(adj, u, adj[u].begin());
		}
	}

	return true;
}

#define MAX 2e5

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector< list<edge> > adj(2 * MAX);
	vector<int> deg(2 * MAX, 0);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		y += MAX;
		deg[x]++;
		deg[y]++;
		add_edge(adj, x, y, i);
	}

	// find odd degree vertices
	stack<iii> e;
	queue<int> q;
	for (int i = 0; i < 2 * MAX; ++i) {
		if(deg[i] > 0) q.push(i);
	}

	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (deg[i] % 2 == 0) continue;
		edge rm = adj[i].front();
		remove_edge(adj, i, adj[i].begin());
		deg[i]--;
		deg[rm.v]--;
		e.push({ { i, rm.v }, rm.m });
		q.push(rm.v);
	}

    db(e.size());

	// all degrees are even now
	vii c;
	vb vis(2 * MAX, false);
	for (int i = 0; i < 2 * MAX; ++i) {
		if (deg[i] > 0 && !vis[i])
			eulerian_circuit(adj, c, vis, deg, i);
	}

	// Store the circuit
	vi balance(2 * MAX, false);
	vi color(n, 0);
	const int RED = 1, BLUE = 2;
	int v = -1;
	for (int i = c.size() - 1; i >= 0; --i) {
        
		int u = c[i].first, m = c[i].second;
		if (m == -1) { v = u; continue; }
        db(i);
		if ((c.size() - 1 - i) % 2 == 1) // RED 
		{
			balance[u]++;
			balance[v]++;
			color[m] = RED;
		}
		else { // BLUE
			balance[u]--;
			balance[v]--;
			color[m] = BLUE;
		}
		v = u;
	}

	// Push remaining edges
	while (!e.empty()) {
		iii t = e.top(); e.pop();
		int m = t.second;
		int u = t.first.first, v = t.first.second;
		if (balance[v] > 0)  {
			balance[u] --;
			balance[v] --;
			color[m] = BLUE;
		}
		else {
			balance[u] ++;
			balance[v] ++;
			color[m] = RED;
		}
	}

	// Print
	for (int i = 0; i < n; ++i) {
		cout << (color[i] == RED ? 'r' : 'b');
	}
	cout << endl;

	return 0;
}