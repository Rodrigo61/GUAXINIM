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

#define MAXN 412

int n;
ll vals[MAXN];
ll prefix[MAXN];
int vis[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll sum(int l, int r)
{
    ll res = prefix[r];
    if (l > 0) res -= prefix[l - 1];
    return res;
}

ll solve(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return 0;

    if (vis[l][r])
        return dp[l][r];
    vis[l][r] = 1;

    ll res = INF;
    for (int i = l; i < r; i++)
    {
        ll rec1 = solve(l, i);
        ll rec2 = solve(i + 1, r);

        res = min(res, rec1 + rec2 + sum(l, r));
    }
    
    return dp[l][r] = res;
}

int main()
{
    scanf("%d", &n);
    ll aux = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &vals[i]);
        aux += vals[i];
        prefix[i] = aux;
    }

    printf("%lld\n", solve(0, n - 1));
    
}