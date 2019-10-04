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

int main()
{
    int n;
    scanf("%d", &n);
    vii vals(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i].fi);
        vals[i].se = i;
    }

    sort(all(vals));
    reverse(all(vals));

    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        total += (vals[i].fi * i) + 1;
    }

    printf("%lld\n", total);
    for(pii i : vals)
        printf("%d ", i.se + 1);
    printf("\n");
    
    
}