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

#define MAXN 512

int n;
int grid[MAXN][MAXN];
int res[MAXN][MAXN];
int line[MAXN];
char c;

int main()
{
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", &c);
            grid[i][j] = c - '0';
        }
        scanf("\n");
    }


    for (int i = n - 1; i >= 1; --i)
    {
        memcpy(line, grid[i], sizeof(grid[i]));
        for (int j = i + 1; j <= n; j++)
        {
            if (line[j] == 1)
            {
                res[i][j] = 1;
                for (int k = j + 1; k <= n; ++k)
                {
                    line[k] = (line[k] - grid[j][k] + 10) % 10;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d", res[i][j]);
        }
        printf("\n");
    }
    
    

}