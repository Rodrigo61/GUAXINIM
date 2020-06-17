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


#define EPS 0.000000001

double vals[4];

int main()
{
    double aux;

    for (int i = 0; i < 4; i++)
    {
        scanf("%lf", &vals[i]);
    }

    double target;
    scanf("%lf", &target);

    sort(vals, vals + 4);

    double rm = (vals[1] + vals[2] + vals[3])/(double)3;

    if (rm < target || (abs(rm - target)) <= EPS)
    {
        return !printf("infinite\n");
    }

    double x = target * 3 - vals[1] - vals[2];

    if (x > vals[0] || (abs(x - vals[0])) <= EPS)
    {
        return !printf("%.2lf\n", x);
    }

    printf("impossible\n");

    return 0;
}