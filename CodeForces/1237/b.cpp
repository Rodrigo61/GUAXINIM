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

#define MAXN 112345

int BIT[MAXN];

void update(int pos)
{
    while (pos < MAXN)
    {
        BIT[pos] += 1;
        pos += pos & -pos;
    }
}

int prefix(int pos)
{
    int res = 0;
    while (pos > 0)
    {
        res += BIT[pos];
        pos -= pos & -pos;
    }
    return res;
}

/*int prefix(int pos)
{
    return query(MAXN - 1) - query(pos);
}*/

int main()
{
    int n;
    map<int, int> coord;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int v;
        scanf("%d", &v);
        coord[v] = i;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        v = coord[v];
        if (prefix(v) != v - 1)
            res ++;
        update(v);
    }
    
    printf("%d\n", res);
}