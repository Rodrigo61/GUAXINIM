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

#define MOD 1000000007

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n; i++)
    {
        int r;
        scanf("%d", &r);
        for (int j = 0; j < r; ++j)
            if (grid[i][j] != 0)
                grid[i][j] = 1;
            else
                return !printf("0\n");

        if (grid[i][r] != 1)
            grid[i][r] = 0;
        else
            return !printf("0\n");
    }

    for (int i = 0; i < m; i++)
    {
        int r;
        scanf("%d", &r);
        for (int j = 0; j < r; ++j)
            if (grid[j][i] != 0)
                grid[j][i] = 1;
            else
                return !printf("0\n");
        
        if (grid[r][i] != 1)
            grid[r][i] = 0;
        else
            return !printf("0\n");
    }

    ll total = 1;
    db(n);
    db(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {    
            if (grid[i][j] == -1)
            {
                total = (total * 2) % MOD;
            }
        }       
    }
    printf("%lld\n", total);

}



