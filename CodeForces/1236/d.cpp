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

#define MAXN 112345

vector<pii> neighs = {{-1, -1}, {-1, 0}, {1, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}};
int n, m, k;
pii blocks[MAXN];
set<pair<pii, int>> sblocks;
vi adj[MAXN];
int vis[MAXN];

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &blocks[i].fi, &blocks[i].se);
        sblocks.insert({blocks[i], i});
        for (pii a : neighs)
        {
            pii target = {blocks[i].fi + a.fi, blocks[i].se + a.se};
            auto it = sblocks.lower_bound({target, 0});
            if (it != sblocks.end() && it->fi == target)
            {
                adj[i].pb(it->se);
                adj[it->se].pb(i);
            }
        }
    }

    

    
}