#include "bits/stdc++.h"

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

#define MAXN 100001
#define SQRN 317 

int vals[MAXN];
int sqr;
int freq[SQRN][MAXN];
int n;

void build()
{
    sqr = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    for (int i = 0; i < n; i++)
    {
        freq[i/sqr][vals[i]]++;
    }
}

int query(int l, int r, int v)
{
    int c_l = l / sqr;
    int c_r = l / sqr;
    int res = 0;

    if (c_l == c_r)
    {
        for (int i = l; i <= r; i++)
        {
            if (vals[i] == v)
                ++res;
        }
        return res;
    }
    
    for (int i = l, e = (c_l + 1) * sqr; i < e; i++)
    {
        if (vals[i] == v)
            ++res;
    }
    for (int i = c_l + 1; i < c_r; i++)
    {
        res += freq[i][v];
    }
    for (int i = c_r * sqr; i <= r; i++)
    {
        if (vals[i] == v)
            ++res;
    }
    return res;    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int id = 0;
    map<string, int> s2i;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s2i.find(s) == s2i.end())
            s2i[s] = id++;
        vals[i] = s2i[s];
    }

    build();

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        string s;
        cin >> l >> r >> s;
        --l, --r;
        if (s2i.find(s) == s2i.end())
            printf("0\n");
        else
            printf("%d\n", query(l, r, s2i[s]));
    }
}