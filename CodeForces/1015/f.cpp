#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 205
#define MOD 1000000007 

int N;
string seq;
vector<int> lps;
int vis[MAXN][MAXN][MAXN][2];
ll dp[MAXN][MAXN][MAXN][2];

int add(ll a, ll b)
{
	a += b;
	if (a >= MOD)
	{
		a -= MOD;
	}
	return a;
}

void kmpPre(string &target, vector<int> &lps)
{
	int i = 0, j = -1;
	lps.resize(target.size() + 1);
	lps[0] = -1;
	int m = target.length();
	while(i < m)
	{
		while(j >= 0 && target[i] != target[j]) j = lps[j];
		i++, j++;
		lps[i] = j;
	}
}

ll solve(int i, int bal, int it, int f)
{
	if (i == 2*N)
	{
		db(c);
		db(bal);
		db(f);
		return bal == 0 && f;
	}
	
	if (bal < 0)
	{
		return 0; // impossible to be valid
	}
	
	// TODO DP
	if (vis[i][bal][it][f])
	{
		return dp[i][bal][it][f];
	}
	vis[i][bal][it][f] = 1;
	
	ll res = 0;
	
	// using )
	int t = it;
	while (t >= (int)seq.size() || (t >= 0 && seq[t] != ')'))
	{
		t = lps[t];
	}
	int fin = t == (int)seq.size() - 1;
	res = add(res, solve(i + 1, bal - 1, t + 1, f|fin));
	
	// using (
	t = it;
	while (t >= (int)seq.size() || (t >= 0 && seq[t] != '('))
	{
		t = lps[t];
	}	
	fin = t == (int)seq.size() - 1;
	res = add(res, solve(i + 1, bal + 1, t + 1, f|fin));
	
	dp[i][bal][it][f] = res;
	return res;
}

int main()
{
	scanf("%d\n", &N);
	cin >> seq;
	kmpPre(seq, lps);
	
	cout << solve(0, 0, 0, 0) << endl;
}
