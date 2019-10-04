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

int BIT[40][MAXN];
char aux[MAXN];
string str;

void update(int w, int p, int v)
{
    ++p;
    while (p < MAXN)
    {
        BIT[w][p] += v;
        p += p & -p;
    }
}

ll sum(int w, int p)
{
    ++p;
    ll res = 0;
    while (p > 0)
    {
        res += BIT[w][p];
        p -= p & -p;
    }
    return res;
}

ll range_query(int w, int l, int r)
{
    return sum(w, r) - sum(w, l - 1);
}

int main()
{
    scanf("%s", aux);
    str = aux;

    for (int i = 0; i < (int)str.size(); i++)
    {
        update(str[i] - 'a', i, 1);
    }

    int q;
    scanf("%d", &q);
    while (q--)
    {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 2)
        {
            int res = 0;
            int l, r;
            scanf("%d%d", &l, &r);
            --l, --r;
            for (char i = 'a'; i <= 'z'; i++)
            {
                res += (bool)(range_query(i - 'a', l, r));
            }
            printf("%d\n", res);
        }
        else
        {
            int p;
            char c;
            scanf("%d %c", &p, &c);
            --p;
            update(c - 'a', p, 1);
            update(str[p] - 'a', p, -1);
            str[p] = c;
        }
        
    }
    
}