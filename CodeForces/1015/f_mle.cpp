#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 105
#define MOD 1000000007 

int N;
string seq;
int vis[MAXN][MAXN][MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN][MAXN];

ll add(ll a, ll b)
{
	a += b;
	if (a >= MOD)
	{
		a -= MOD;
	}
	return a;
}

ll solve(int l, int r, int r_left, int r_right)
{
	if (r_left == 0 && r_right== 0)
	{
		return l == 0 && r == 0;
	}
	
	if (vis[l][r][r_left][r_right])
	{
		return dp[l][r][r_left][r_right];
	}
	vis[l][r][r_left][r_right] = 1;
	
	
	int res = 0;
	
	if (r_left)
	{
		if (l)
		{
			res = add(res, solve(l - 1, r, r_left - 1, r_right));
		}
		else
		{
			res = add(res, solve(l, r + 1, r_left - 1, r_right));
		}
		res = add(res, solve(l + 1, r, r_left - 1, r_right));
	}
	else
	{
		if (r)
		{
			res = add(res, solve(l, r - 1, r_left, r_right - 1));
		}
		else
		{
			res = add(res, solve(l + 1, r, r_left, r_right - 1));
		}
		res = add(res, solve(l, r + 1, r_left, r_right - 1));
	}
	
	dp[l][r][r_left][r_right] = res;
	return res;
}

int main()
{
	scanf("%d\n", &N);
	cin >> seq;
	int l = 0, r = 0;
	
	int reserv = 0;
	for (char c : seq)
	{
		if (c == ')')
		{
			if (reserv)
			{
				--reserv;
			}
			else
			{
				++l;
			}
		}
		else
		{
			++reserv;
		}
	}
	reserv = 0;
	reverse(seq.begin(), seq.end());
	for (char c : seq)
	{
		if (c == '(')
		{
			if (reserv)
			{
				--reserv;
			}
			else
			{
				++r;
			}
		}
		else
		{
			++reserv;
		}
	}
	reverse(seq.begin(), seq.end());
	int total = 0;
	
	for (int i = 0; i <= 2*N-seq.size(); i++)
	{
		int l_left = i;
		int r_left = 2*N-seq.size() - i;
		total = add(total, solve(l, r, l_left, r_left));
	}
	
	cout << total << endl;
}
