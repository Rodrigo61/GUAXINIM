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
    ll n, curr;
    scanf("%lld%lld", &n, &curr);

    multiset<ll> mset;
    vll A(n), C(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
    }

    ll add;
    scanf("%lld", &add);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &C[i]);
    }

    int i = 0;
    ll cost = 0;
    while (i < n)
    {
        if (A[i] <= curr)
            mset.insert(C[i]);
        else
        {
            mset.insert(C[i]);
            while (A[i] > curr && !mset.empty())
            {
                curr += add;
                cost += *mset.begin();
                mset.erase(mset.begin());
            }

            if (A[i] > curr)
                return !printf("-1\n");
        }

        i++;
    }
    
    printf("%lld\n", cost);
    
    
}