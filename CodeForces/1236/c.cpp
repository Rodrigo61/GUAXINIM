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

#define MAXN 312

int grid[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    int id = 1;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            for (int j = n - 1; j >= 0 ; j--)
                grid[i][j] = id++;            
        else
            for (int j = 0; j < n ; j++)
                grid[i][j] = id++;
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
}