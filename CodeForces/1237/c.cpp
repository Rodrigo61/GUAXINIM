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
typedef long double ld;
typedef unsigned long long ull;

#define pp pair<point, point>
#define piii pair<pair<int, int>, int>

#define MAXN 51234

struct point{
    ll x, y, z;
    int idx;
};

int used[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    vector<point> points(n);
    multiset<pair<int, int>> xset, yset, zset;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld", &points[i].x, &points[i].y, &points[i].z);
        points[i].idx = i;
        xset.insert({points[i].x, i});
    }

    for (int c = 0; c< n/2; c++)
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;
            for (int j = i; j < n; j++)
            {
                if (used[j]) continue;

                bool poss = true;
                for (auto it = xset.lower_bound({min(points[i].x, points[j].x), 0}), 
                          et = xset.upper_bound({max(points[i].x, points[j].x), 0}); it != et; ++it)
                {
                    int idx = it->se;
                    if (min(points[i].y, points[j].y) <= points[idx].y && points[idx].y <= max(points[i].y, points[j].y)
                    &&  min(points[i].z, points[j].z) <= points[idx].z && points[idx].z <= max(points[i].z, points[j].z))
                        {
                            poss = false;
                            break;
                        }
                }

                if (poss)
                {
                    printf("%d %d\n", i + 1, j + 1);
                    used[i] = used[j] = 1;
                    xset.erase(xset.find({points[i].x, points[i].idx}));
                    xset.erase(xset.find({points[j].x, points[j].idx}));
                }
                
            }
            
        }
        
    }
    
}