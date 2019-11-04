#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
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

int szs[55];
int n;

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        int change = 0;
        int odd = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            vi cnt(2);
            for (char c : str)
                cnt[c-'0']++;

            if (str.size() & 1)
            {
                ++ans;
                ++odd;
            }
            else 
            {
                if (cnt[0] & 1)
                {
                    ++change;
                }
                else
                {
                    ++ans;
                }
            }
        }

        if (odd)
            ans += change;
        else
            ans += (change/2) * 2;

        printf("%d\n", ans);
    }
    
}