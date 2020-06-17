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
#define sz(x) int(x.size())
typedef long double ld;

#define MAXN 112345

int vals[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vals[i]);
        }

        vi res;
        for (int i = 0; i < n;)
        {
            res.pb(i);
            if (i == n - 1) break;
            if (vals[i] < vals[i + 1]) {
                int maxi = vals[i + 1];
                int maxi_i = i + 1;

                for (int j = i + 1; j < n && vals[j] > vals[j - 1]; j++)
                {
                    if (vals[j] > maxi) {
                        maxi = vals[j];
                        maxi_i = j;
                    }
                }
                
                i = maxi_i;
            } else
            {
                int maxi = vals[i + 1];
                int maxi_i = i + 1;

                for (int j = i + 1; j < n && vals[j] < vals[j - 1]; j++)
                {
                    if (vals[j] < maxi) {
                        maxi = vals[j];
                        maxi_i = j;
                    }
                }
                
                i = maxi_i;
            }
        }
        
        printf("%d\n", sz(res));
        for (int i : res) {
            printf("%d ", vals[i]);
        }
        printf("\n");
        
    }
    
}