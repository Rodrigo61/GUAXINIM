#pragma once
 
#include <bits/stdc++.h>
using namespace std;
 
template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }
 
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}
 
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}
 
template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}
 
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
 
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;
 
#define sz(x) ((int)(x).size())
 
// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }
 
template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }
 
// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out
 
#define MAXN 312
#define MAXK 1123
 
bitset<MAXN> graph[MAXN];
vector<pii> doc[MAXK];
vector<int> l[MAXN][MAXN];
int doc_done[MAXK];
int n = 0;
 
void add_edge(int a, int b)
{
	if (graph[a][b])
		return;
	
	graph[a][b] = 1;
	graph[a] |= graph[b];
 
	for (int i = 1; i <= n; i++)
		if (graph[i][a])
			graph[i] |= graph[a];
}
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	map<string, int> rdm;
	int a, b;
	string s1, s2;
 
	cin >> s1 >> s2;
	rdm[s1] = ++n;
	rdm[s2] = ++n;
	tie(a, b) = {rdm[s1], rdm[s2]};
 
	graph[a][b] = 1;
 
	int k = 0, m;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> m;
		while (m--)
		{
			cin >> s1 >> s2;
			if (rdm[s1] == 0)
				rdm[s1] = ++n;
 
			if (rdm[s2] == 0)
				rdm[s2] = ++n;
			tie(a, b) = {rdm[s1], rdm[s2]};
 
			doc[i].push_back({a, b});
			l[a][b].push_back(i);
		}
	}
 
	bool ans = true;
	while (ans)
	{
		int cur = -1;
		for (int i = 1; cur == -1 && i <= n; i++)
			for (int j = 1; cur == -1 && j <= n; j++)
				if (graph[i][j] && !l[i][j].empty())
				{
					int tmp = l[i][j].back();
					l[i][j].pop_back();
					if (!doc_done[tmp])
						cur = tmp;
					else
						j--;					
				}
		
		// debug(cur);
 
		if (cur == -1)
			break;
		
		doc_done[cur] = true;
		for (int i = 0; i < doc[cur].size(); i++)
			add_edge(doc[cur][i].first, doc[cur][i].second);
 
		for (int i = 1; i <= n; i++)
			if (graph[i][i])
				ans = false;
	}

	cout << (ans ? "Yes" : "No") << endl;
}