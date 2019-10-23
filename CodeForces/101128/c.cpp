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
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        int n;
        scanf("%d", &n);
        multiset<ll> mset;
        for (int i = 0; i < n; i++)
        {
            ll v;
            scanf("%lld", &v);
            mset.insert(v);
        }

        ll res = 0;
        while (mset.size() >= 2)
        {
            ll a = *mset.begin();
            mset.erase(mset.begin());
            ll b = *mset.begin();
            mset.erase(mset.begin());
            res += a + b;
            mset.insert(a + b);
        }
        
        printf("%lld\n", res);
    }
    
}