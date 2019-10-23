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

int main()
{
    int n;
    scanf("%d", &n);
    vi vals(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
    }
    int total = 0;
    for (int i : vals)
        total += i/2;
    
    if (total > 0)
    {
        int it = 0;
        while (total > 0)
        {
            if (vals[it] < 0 && vals[it] & 1)
            {
                total--;
                vals[it]--;
            }
            ++it;
        }
    }
    else if (total < 0)
    {
        int it = 0;
        while (total < 0)
        {
            if (vals[it] > 0 && vals[it] & 1)
            {
                total++;
                vals[it]++;
            }
            ++it;
        }
    }

    for (int i : vals)
        printf("%d\n", i/2);
}