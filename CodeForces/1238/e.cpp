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

#define MAXN 212345

int n, m;
char str[MAXN];
int freq[25][25];
int vis[1058576];
ll dp[1058576];

ll solve(int used)
{
    if (used == (1 << m) - 1)
        return 0;

    if (vis[used])
        return dp[used];
    vis[used] = 1;

    db(used);
    int pos = __builtin_popcount(used);
    ll res = INF;
    for (int i = 0; i < m; i++)
    {
        if ((used & (1 << i)) == 0)
        {
            ll rec = solve(int(used | (1 << i)));
            for (int j = 0; j < m; j++)
            {
                if (i == j) continue;
                if (used & (1 << j))
                {
                    rec += freq[i][j] * (pos + 1);
                }
                else
                {
                    rec -= freq[i][j] * (pos + 1);
                }
                
            }

            res = min(res, rec);
        }
    }

    return dp[used] = res;
    
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", str);

    for (int i = 0; i < n - 1; i++)
    {
        freq[str[i] - 'a'][str[i + 1] - 'a']++;
        freq[str[i + 1] - 'a'][str[i] - 'a']++;
    }

    printf("%lld\n", solve(0));
}