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
#define sz(x) (int)(x.size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

const int mod = 2e9+33;

int main()
{
    int sqr = 1000000;
    int block = 0;
    vi indexes;
    vi vals;
    ll curr = 1;

    indexes.pb(0);
    vals.pb(1);
    for (int i = 1; i <= 2e9+33; i++)
    {
        curr = (curr * i) % mod;
        if (i / sqr != block)
        {
            indexes.pb(i);
            vals.pb(curr);
            block++;
        }
    }

    for (int i : indexes)
        printf("%d, ", i);
    printf("\n");
    
    for (int i : vals)
        printf("%d, ", i);
    printf("\n");
}