#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define pll pair<ll, ll>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define p fi.fi
#define w fi.se

#define MAXN 512

int N;
vector<pair<pll, int>> lab[MAXN];

int main()
{
	freopen("student.in", "r", stdin);
	freopen("student.out", "w", stdout);
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int k;
		scanf("%d", &k);
		lab[i].resize(k);
	}
	
	int id = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < (int)lab[i].size(); j++)
		{
			scanf("%lld", &lab[i][j].p);
			lab[i][j].se = id;
			++id;
		}
			
	for (int i = 0; i < N; i++)
		for (int j = 0; j < (int)lab[i].size(); j++)
			scanf("%lld", &lab[i][j].w);
			
	vi classes_idx(N);
	vector<pll> classes_consts(N);
	vll B_const(N);
	for (int i = 0; i < N; i++)
	{
		classes_idx[i] = i;

		sort(all(lab[i]), [](pair<pll, int> &a, pair<pll, int> &b)
		{
			return a.w * b.p > b.w * a.p;
		});
		
		ll acu_p = 0;
		ll A = 0;
		ll B = 0;
		for (auto pr : lab[i])
		{
			acu_p += pr.p;
			A += pr.w;
			B += pr.w * acu_p;
		}
		classes_consts[i] = {A, acu_p};
		B_const[i] = B;
	}
	
	sort(all(classes_idx), [&](int i, int j)
	{
		return classes_consts[i].fi * classes_consts[j].se > classes_consts[j].fi * classes_consts[i].se;
	});
	
	ll res = 0;
	ll T = 0;
	for (int i : classes_idx)
	{
		res += T * classes_consts[i].fi + B_const[i];
		T += classes_consts[i].se;
	}
	
	printf("%lld\n", res);
	for (int i : classes_idx)
		for (auto j : lab[i])
		printf("%d ", j.se);
	printf("\n");
	
}
