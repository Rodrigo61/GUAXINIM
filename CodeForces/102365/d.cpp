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

#define MAXN 4123
#define RIGHT 0
#define LEFT 1

int N, J;
int to_right[MAXN], to_left[MAXN];

ll solve(int l, int r, int dir)
{
    if (l >= r)
        return 0;

    ll res = INF;
    if (dir == RIGHT)
    {
        res = to_right[1] + solve(l + 1, r, RIGHT);
        for (int i = 2; i <= J && l + i <= r; i++)
        {
            ll rec = to_right[i] + max(solve(l, l + i - 1, LEFT), solve(l + i + 1, r, RIGHT));
            res = min(res, rec);
        }
    }
    else
    {
        res = to_left[1] + solve(l, r - 1, LEFT);
        for (int i = 2; i <= J && r - i >= l; i++)
        {
            ll rec = to_left[i] + max(solve(l, r - i - 1, LEFT), solve(r - i + 1, r, RIGHT));
            res = min(res, rec);
        }
    }
    
    return res;
}

int main()
{
    scanf("%d%d", &N, &J);
    for (int i = 0; i <= J; i++)
        scanf("%d", &to_right[i]);
    for (int i = 0; i <= J; i++)
        scanf("%d", &to_left[i]);
    
    printf("%lld\n", solve(2, N, RIGHT));
}