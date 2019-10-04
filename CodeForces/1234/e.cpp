#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x)// cerr << #x << " = " << x << endl;
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

vi adj[MAXN];
ll curr_val[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ll res = 0;
    ll last = 0;
    vi in;

    for (int i = 0; i <= n; i++)
    {
        curr_val[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int v;
        scanf("%d", &v);
        in.pb(v);
        adj[v].pb(i);

        if (i > 0)
            res += abs(curr_val[last] - curr_val[v]);
        last = v;
    }
    
    printf("%lld ", res);
    int pivot = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j : adj[pivot])
        {
            if (j - 1 >= 0)
            {
                res -= abs(curr_val[in[j - 1]] - curr_val[in[j]]);
            }
            if (j + 1 < m)
            {
                res -= abs(curr_val[in[j]] - curr_val[in[j + 1]]);  
            }
                
        }

        for (int j : adj[pivot + 1])
        {
            if (j - 1 >= 0)
                res -= abs(curr_val[in[j - 1]] - curr_val[in[j]]);
            if (j + 1 < m)
                res -= abs(curr_val[in[j]] - curr_val[in[j + 1]]);
        }

        curr_val[pivot] = pivot + 1;
        curr_val[pivot + 1] = 1;

        for (int j : adj[pivot])
        {
            if (j - 1 >= 0)
                res += abs(curr_val[in[j - 1]] - curr_val[in[j]]);
            if (j + 1 < m)
                res += abs(curr_val[in[j]] - curr_val[in[j + 1]]);
        }

        for (int j : adj[pivot + 1])
        {
            if (j - 1 >= 0)
                res += abs(curr_val[in[j - 1]] - curr_val[in[j]]);
            if (j + 1 < m)
                res += abs(curr_val[in[j]] - curr_val[in[j + 1]]);
        }

        printf("%lld ", res);
        pivot++;
    }
    
}