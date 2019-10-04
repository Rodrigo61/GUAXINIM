#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << setprecision(32) << #x << " = " << x << endl;
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

const double EPS = 1e-9;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<ld> vals(n);
    for (int i = 0; i < n; i++)
    {   
        scanf("%LF", &vals[i]);
    }

    ld up = 1000;
    ld lo = 0;
    ld best;

    while (lo <= up && fabs(lo - up) > EPS)
    {
        ld mid = lo + (up - lo)/2;
        ld f = 0;
        ld b = 0;
        db(mid);
        for (ld d : vals)
        {
            if (fabs(d - mid) < EPS) continue;
            if (d < mid)
                f += mid - d;
            else
                b += (d - mid) * (100-k)/(ld)100;
        }

        if (b >= f)
        {
            best = mid;
            lo = mid + 0.0000000001;
        }
        else
        {
            up = mid - 0.0000000001;
        } 
    }
    
    cout << setprecision(32) << best << endl;
}