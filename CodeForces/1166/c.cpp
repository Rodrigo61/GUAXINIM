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

int main()
{
    int n;
    scanf("%d", &n);
    vi vals(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
        vals[i] = abs(vals[i]);
    }
    sort(all(vals));

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        res += upper_bound(vals.begin() + i + 1, vals.end(), 2 * vals[i]) - (vals.begin() + i + 1);
    }
    
    printf("%lld\n", res);
    
}