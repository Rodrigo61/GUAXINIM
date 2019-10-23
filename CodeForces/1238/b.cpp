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
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        multiset<int> mset;
        for (int i = 0; i < n; i++)
        {
            int v;
            scanf("%d", &v);
            mset.insert(v);
        }

        int res = 0;
        int offset = 0;
        while (!mset.empty())
        {
            res++;
            auto it = mset.end();
            ll maxi = *(--it);
            mset.erase(it);
            
            if (mset.empty())
            {
                goto fim;
            }

            it = --(mset.end());
            while (*it == maxi)
            {
                if (it == mset.begin())
                {
                    goto fim;
                }
                mset.erase(it);
                it = --(mset.end());
            }
            offset += k;
            it = mset.begin();
            while (it != mset.end() && *it <= offset)
                it = mset.erase(it);
        }
        fim:
        printf("%d\n", res);
    }
    
}