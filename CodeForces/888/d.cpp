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

#define MAXN 1123

int n, k;
ll comb[MAXN][MAXN];

void calc()
{
    for(int i = 0; i < MAXN; i++)
    {
        comb[i][0] = 1;
    }
    for(int i = 1; i < MAXN; i++)
    {
        for(int j = 1; j < 5; j++)
        {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]);
        }
    }
}

int main()
{
    calc();
    scanf("%d%d", &n, &k);
    ll res = 0;
    for (int i = 0; i <= k; i++)
    {
        ll c = comb[n][i];
        vi vals(i);
        for (int j = 0; j < i; ++j) vals[j] = j;
        ll cnt = 0;
        do
        {
            bool poss = true;
            for (int j = 0; j < i; ++j) 
                if (vals[j] == j)
                    poss = false;
            cnt += (int)poss;
        } while (next_permutation(all(vals)));
        res += c * cnt;
    }
    printf("%lld\n", res);
}