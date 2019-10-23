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

int n;
int freq[4];
double dp[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];

double solve(int a, int b, int c)
{
    if (a == 0 && b == 0 && c == 0)
        return 0;

    if (vis[a][b][c])
        return dp[a][b][c];
    vis[a][b][c] = 1;

    // Waste
    double p_waste = (n - (a + b + c))/double(n);
    dp[a][b][c] = p_waste / (1 - p_waste);
 
    // I will use at least 1 movement in this current state
    dp[a][b][c] += 1;

    if (a)
    {
        double p = a/double(a+b+c);
        dp[a][b][c] += p * solve(a - 1, b, c);
    }
    if (b)
    {
        double p = b/double(a+b+c);
        dp[a][b][c] += p * solve(a + 1, b - 1, c);
    }
    if (c)
    {
        double p = c/double(a+b+c);
        dp[a][b][c] += p * solve(a, b + 1, c - 1);
    }

    return dp[a][b][c];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        freq[v]++;
    }
    solve(freq[1], freq[2], freq[3]);
    printf("%.10lf\n", dp[freq[1]][freq[2]][freq[3]]);
    
}