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

#define MAXN 100

string D, H;
int B;
string L;
ll dp[MAXN][2];
int vis[MAXN][2];
int t;

ll solve(int idx, int smaller, string &target)
{
    if (idx == (int)target.size())
    {
        return 1;
    }   

    if (vis[idx][smaller] == t)     
        return dp[idx][smaller];
    vis[idx][smaller] = t;

    ll res = 0;
    if (smaller)
    {
        for (int i = 0; i < B; i++)
        {
            if (L[i] == 'S')
                res += solve(idx + 1, 1, target);
        }
    }
    else
    {
        if (L[target[idx] - '0'] == 'S')
            res += solve(idx + 1, 0, target);
        for (int i = 0; i < target[idx] - '0'; i++)
        {
            if (L[i] == 'S')
                res += solve(idx + 1, 1, target);
        }
    }
    
    return dp[idx][smaller] = res;    
}

string transform(ll num)
{
    string res;
    while (num >= B)
    {
        res += to_string(num%B);
        num /= B;
    }
    res += to_string(num);
    reverse(all(res));
    return res;
}

int main()
{
    ll d, h;
    while (cin >> d >> h >> B >> L, d != -1)
    {
        --d;
        D = transform(d);
        H = transform(h);
        ++t;
        ll fixed_H = solve(0, 0, H);
        ll opts = count(all(L), 'S');
        ll var = 1;
        ll rest = 0;
        if (L[0] == 'N')
        for (int i = 1; i < (int)H.size(); i++)
        {
            var *= opts;
            rest += var;
        }
        ll total_H = fixed_H + rest;

        ++t;
        ll fixed_D = solve(0, 0, D);
        var = 1;
        rest = 0;
        if (L[0] == 'N')
        for (int i = 1; i < (int)D.size(); i++)
        {
            var *= opts;
            rest += var;
        }
        ll total_D = fixed_D + rest;

        printf("%lld\n", total_H - total_D);
    }
    
}