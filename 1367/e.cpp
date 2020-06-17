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

#define MAXN 2123

int n, k;
char aux[MAXN]


int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d%d", &n, &k);
        scanf("%s", aux);

        vi freq(255);
        for (int i = 0; i < n; i++)
        {
            freq[aux[i]]++;
        }

        int res = 0;
        for (d : divs(k)) {
            for (int i = n; i > res; i++)
            {
                bool possible = false;
                for (int c : find_cycles(i, d)) {
                    auto it = beads.lower_bound(c);
                    if (it != beads.end()) {
                        
                    }
                }
            }
            
        }
        
    }
    
}