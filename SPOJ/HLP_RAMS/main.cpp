//https://www.spoj.com/problems/HLP_RAMS/

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
        ll n;
        scanf("%lld", &n);
        ll cnt_1 = __builtin_popcountll(n);
        ll odd = (1 << cnt_1);
        ll even = n + 1 - odd;
        printf("%lld %lld\n", even, odd);
    }
    
}