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
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n;
        scanf("%d", &n);
        ll sum = 0;
        for (size_t i = 0; i < n; i++)
        {
            ll v;
            scanf("%lld", &v);
            sum += v;
        }

        printf("%lld\n", (ll)(ceil(sum/(double)n)));
        
    }
    
}