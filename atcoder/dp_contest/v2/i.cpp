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

const int MAXN = 3000;

int n;
double p[MAXN];
int vis[MAXN][MAXN];
double dp[MAXN][MAXN];

double solve(int idx, int heads)
{
    if (idx == n)
    { 
        int tails = idx - heads;
        return heads > tails;
    }

    if (vis[idx][heads])
        return dp[idx][heads];
    vis[idx][heads] = 1;

    return dp[idx][heads] = p[idx] * solve(idx + 1, heads + 1) + (1.0 - p[idx]) * solve(idx + 1, heads);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &p[i]);
    }

    printf("%.10lf\n", solve(0, 0));
    
}