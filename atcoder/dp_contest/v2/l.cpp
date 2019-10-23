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

#define MAXN 3123

int n;
ll vals[MAXN];
ll dp[MAXN][MAXN];
int vis[MAXN][MAXN];

ll solve(int l, int r)
{
    if (l > r)
        return 0;

    if (vis[l][r])
        return dp[l][r];
    vis[l][r] = 1;

    return dp[l][r] = max(vals[l] - solve(l + 1, r), vals[r] - solve(l, r - 1));
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &vals[i]);
    }
    
    printf("%lld\n", solve(0, n - 1));
}