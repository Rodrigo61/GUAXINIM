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
    int n, m;
    while(scanf("%d%d", &n, &m), n != 0)
    {
        vector<pii> intervals(n);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d%d", &a, &a);
            scanf("%d%d", &intervals[i].fi, &intervals[i].se);
            intervals[i].se += intervals[i].fi;
        }
        
        for (int i = 0; i < m; i++)
        {
            int s, e;
            scanf("%d%d", &s, &e);
            int cnt = 0;
            e += s;
            db(s);
            db(e);
            for (int j = 0; j < n; j++)
            {
                db(intervals[j].fi);
                db(intervals[j].se);

                if (intervals[j].se < e && intervals[j].se < s)
                {
                    db("d1");
                    continue;
                }

                if (e < intervals[j].se && e < intervals[j].fi)
                {
                    db("d2");
                    continue;
                }

                int l = max(s, intervals[j].fi);
                int r = min(e, intervals[j].se);

                db(l);
                db(r);
                if (l != r)
                {
                    db(j);
                    cnt++;
                }
            }
            printf("%d\n", cnt);
        }
    }

}