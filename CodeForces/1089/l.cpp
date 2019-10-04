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
    vector<vi> jobs(n + 1);
    vi B(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        jobs[a].pb(i);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    multiset<int> bkp;
    for (auto v : jobs)
    {
        if (v.size() > 1)
        {
            int max_i = 0;
            int ma = 0;

            for (int i : v)
                if (B[i] > ma)
                {
                    ma = B[i];
                    max_i = i;
                }

            for (int i : v)
                if (i != max_i)
                    bkp.insert(B[i]);
        }
    }

    int missing = 0;
    for (int i = 1; i <= k; i++)
    {
        if (jobs[i].empty()) ++missing;
    }
    

    ll cost = 0;
    for (int i = 0; i < missing; i++)
    {
        cost += *bkp.begin();
        bkp.erase(bkp.begin());
    }
    
    printf("%lld\n", cost);
}
















