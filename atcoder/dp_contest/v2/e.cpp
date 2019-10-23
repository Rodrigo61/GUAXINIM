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

#define MAXN 112
#define MAXV 1123

int n, w;
int V[MAXN];
ll W[MAXN];
int target;
int vis[MAXN][MAXV * MAXN];
ll dp[MAXN][MAXV * MAXN];

ll solve(int idx, int r)
{
    if (r <= 0)
        return 0;
    
    if (idx == n)
        return r <= 0 ? 0:INF;

    if (vis[idx][r])
        return dp[idx][r];
    vis[idx][r] = 1;

    ll res = min(solve(idx + 1, r), solve(idx + 1, r - V[idx]) + W[idx]);
    return dp[idx][r] = res;
}

int main()
{
    scanf("%d%d", &n, &w);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &W[i], &V[i]);
    }
    int up = 100000;
    int lo = 0;
    int best = -1;

    while (lo <= up)
    {
        int mid = lo + (up - lo)/2;
        if (solve(0, mid) <= w)    
        {
            best = mid;
            lo = mid + 1;
        }
        else
        {
            up = mid - 1;
        }
    }
    
    printf("%d\n", best);
}