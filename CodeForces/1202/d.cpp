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

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int b = 2;
        while ((b * (b-1))/2 <= n) ++b;
        --b;
        int c = n - (b * (b-1))/2;
        printf("133");
        b -= 2;
        for (int i = 0; i < c; i++)
        {
            printf("7");
        }
        for (int i = 0; i < b; i++)
        {
            printf("3");
        }
        printf("7\n");
    }
}