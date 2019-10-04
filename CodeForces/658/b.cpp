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

int main()
{
    int n, c;
    scanf("%d%d", &n, &c);
    vi p(n);
    vi t(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    int tot1 = 0;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time += t[i];
        tot1 += max(0, p[i] - c * time);
        
    }

    int tot2 = 0;
    time = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        time += t[i];
        tot2 += max(0, p[i] - c * time);
    }

    if (tot1 > tot2)
        printf("Limak\n");
    else if (tot1 < tot2)
        printf("Radewoosh\n");
    else
        printf("Tie\n");
    
}
