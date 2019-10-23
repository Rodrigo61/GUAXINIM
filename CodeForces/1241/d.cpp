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

#define MAXN 312345

int vis[MAXN];
int t;

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        ++t;
        int n;
        scanf("%d", &n);
        set<int> used;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int v;
            scanf("%d", &v);
            if (vis[v] != t && used.upper_bound(v) != used.end())
            {
                ++ans;
                vis[v] = t;
            }
            used.insert(v);
        }
        
        printf("%d\n", ans);
    }
    
}