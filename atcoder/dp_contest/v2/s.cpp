#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MAXN 112345
#define MAXD 112

int d;
string num;
ll dp[MAXN][MAXD][2];
int vis[MAXN][MAXD][2];

ll const mod = 1e9+7;

ll add_mod(ll a, ll b)
{
    return a + b >= mod ? a + b - mod: a + b;
}

ll solve(int idx, int sum, int smaller)
{
    if (idx == (int)num.size())
    {
        return sum == 0;
    }

    if (vis[idx][sum][smaller])
        return dp[idx][sum][smaller];
    vis[idx][sum][smaller] = 1;
    
    ll res = 0;
    if (!smaller)
    {
        res = solve(idx + 1, (sum + (num[idx] - '0')) % d, 0);
        for (int i = 0; i < num[idx] - '0'; i++)
        {
            res = add_mod(res, solve(idx + 1, (sum + i) % d, 1));
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            res = add_mod(res, solve(idx + 1, (sum + i) % d, 1));
        }
    }
    
    return dp[idx][sum][smaller] = res;    
}

int main()
{
    cin >> num >> d;
    cout << (solve(0, 0, 0) - 1 + mod) % mod << endl;
}