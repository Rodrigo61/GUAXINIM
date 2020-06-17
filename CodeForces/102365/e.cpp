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
    int n, k;
    scanf("%d%d", &n, &k);
    vi vals(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
    }
    sort(all(vals));
    reverse(all(vals));
    ll res = 0;
    for (int i = 0; i < k; i++)
    {
        res += vals[i];
    }
    printf("%lld\n", res);
    
}