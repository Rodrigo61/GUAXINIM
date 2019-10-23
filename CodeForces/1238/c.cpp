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

int h, n;
int vals[MAXN];

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &h, &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vals[i]);
        }
        vals[n] = 0;
        
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (vals[i] <= 2) break;
            vals[i] = vals[i + 1] + 1;
            if (vals[i + 2] + 2 == vals[i])
            {
                i++;
            }
            else
            {
                vals[i + 1] = vals[i] - 2;
                ++res;
            }
            
        }
        
        printf("%d\n", res);
    }
    
}