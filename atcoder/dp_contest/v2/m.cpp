#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
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
#define MAXK 112345

const int MOD = 1e9+7;

int n, k;
int a[MAXN];
int vis[MAXN][MAXK];
ll dp[MAXN][MAXK];
ll prefix[MAXN][MAXK];

ll sub_mod(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll add_mod(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll get_prefix(int i, int l, int r)
{
    ll res = prefix[i][min(r, MAXK - 1)];
    if (l > 0)
        res = sub_mod(res, prefix[i][l - 1]);
    return res;
}

void solve(int idx)
{
    if (idx == n)
    {
        for (int i = k; i < MAXK; i++)
        {
            prefix[idx][i] = 1;
        }
        return;
    }

    solve(idx + 1);
    for (int i = 0; i < MAXK; i++)
    {
        dp[idx][i] = get_prefix(idx + 1, i, i + a[idx]);
    }

    //prefix
    db(idx);
    prefix[idx][0] = dp[idx][0];
   // printf("%d ", prefix[idx][0]);
    for (int i = 1; i < MAXK; i++)
    {
        prefix[idx][i] = add_mod(prefix[idx][i - 1], dp[idx][i]);
        //printf("%d ", prefix[idx][i]);
    }
   // printf("\n");
    
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    solve(0);
    printf("%lld\n", dp[0][0]);
    
}