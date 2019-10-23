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

#define MAXN 212345

int n;
int h[MAXN];
ll a[MAXN];
ll dp[MAXN];
ll tree[4 * MAXN];

void update(int node, int l, int r, int pos, ll val)
{
    if (l == r)
    {
        tree[node] = val;
        return;
    }

    int mid = (l + r)/2;

    if (pos <= mid)
        update(node * 2 + 1, l, mid, pos, val);
    else
        update(node * 2 + 2, mid + 1, r, pos, val);

    tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
}

ll query(int node, int l, int r, int tl, int tr)
{
    if (r < tl || l > tr)
        return 0;
    
    if (tl <= l && r <= tr)
        return tree[node];

    int mid = (l + r)/2;
    return max(query(node * 2 + 1, l, mid, tl, tr),
               query(node * 2 + 2, mid + 1, r, tl, tr));
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        ll v = query(0, 0, n - 1, 0, h[i]);
        update(0, 0, n - 1, h[i], v + a[i]);
    }

    printf("%lld\n", query(0, 0, n - 1, 0, n - 1));
    
}