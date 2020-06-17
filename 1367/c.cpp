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

#define MAXN 212345

int t;
int n, k;
char table[MAXN];

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d%d", &n, &k);
        scanf("%s", table);

        set<int> used;
        for (int i = 0; i < n; i++)
        {
            if (table[i] == '1') {
                used.insert(i);
            }
        }

        int last_used = -INF;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (table[i] == '1') {
                last_used = i;
            } else {
                auto it = used.upper_bound(i);
                int next_used = INF;
                if (it != used.end())
                    next_used = *it;

                if (i - last_used > k && next_used - i > k) {
                    ++res;
                    last_used = i;
                }
            }
        }
        
        printf("%d\n", res);
        
    }
    
}