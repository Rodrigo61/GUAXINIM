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

int n, k;
int grid[10][10];

int solve(int idx_i, int idx_j)
{
    if (idx_i == n - 1 && idx_j == n)
    {
        bool poss = true;
        for (int i = 0; i < n; ++i)
        {
            bool poss2 = false;
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0) poss2 = true;
            poss &= poss2;
        }
        for (int i = 0; i < n; ++i)
        {
            bool poss2 = false;
            for (int j = 0; j < n; ++j)
                if (grid[j][i] == 0) poss2 = true;
            poss &= poss2;
        }

        return poss;
    }

    if (idx_j == n)
    {
        idx_i++;
        idx_j = 0;
    }

    int res = 0;
    grid[idx_i][idx_j] = 1;
    res += solve(idx_i, idx_j + 1) * (k - 1);
    grid[idx_i][idx_j] = 0;
    res += solve(idx_i, idx_j + 1);

    return res;
}

int main()
{
    scanf("%d%d", &n, &k);
    
    printf("%d\n", solve(0, 0));
}