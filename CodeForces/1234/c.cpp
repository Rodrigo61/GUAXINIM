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

#define MAXN 212345

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int n;
int grid[2][MAXN];
int vis[2][MAXN];
int t = 0;

bool possible(int dir, int i, int j)
{
    if (i == 1 && j == n) return true;
    
    if (i > 1 || j >= n || i < 0 || j < 0)
        return false;

    db("------------");
    db(dir);
    db(i);
    db(j);
    db(grid[i][j]);

    if (vis[i][j] == t)
        return false;
    vis[i][j] = t;

    if (grid[i][j] <= 2)
    {
        if (dir == UP)
            return false;
        if (dir == DOWN)
            return false;
        if (dir == LEFT)
            return possible(LEFT, i, j + 1);
        if (dir == RIGHT)
            return possible(RIGHT, i, j - 1);
    }
    else
    {
        if (dir == UP || dir == DOWN)
            return possible(LEFT, i, j + 1) || possible(RIGHT, i, j - 1);
        else
        {
            if (i == 0)
                return possible(UP, i + 1, j);
            else
                return possible(DOWN, i - 1, j);
        }
    }
    
    return true;
}

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d\n", &n);
        ++t;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c;
                scanf("%c", &c);
                grid[i][j] = c - '0';
            }
            scanf("\n");
        }

        if (possible(LEFT, 0, 0))
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    
}