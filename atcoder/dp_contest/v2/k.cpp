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

const int MAXN = 112;
const int MAXK = 112345;

int n, k;
int vals[MAXN];
int vis[MAXK][2];
bool dp[MAXK][2];

bool solve(int r, int t)
{
    if (vis[r][t])
        return dp[r][t];
    vis[r][t] = 1;
    
    bool winner;
    if (t)
    {
        winner = 0;
        for (int i = 0; i < n; i++)
        {
            if (r - vals[i] >= 0)
                winner |= solve(r - vals[i], !t);
        }
    }
    else
    {
        winner = 1;
        for (int i = 0; i < n; i++)
        {
            if (r - vals[i] >= 0)
                winner &= solve(r - vals[i], !t);
        }
    }

    return dp[r][t] = winner;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
    }

    if (solve(k, 0))
        printf("Second\n");
    else
        printf("First\n");
}