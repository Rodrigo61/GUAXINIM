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
    int n;
    scanf("%d", &n);
    vll vals(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &vals[i]);
        sum += vals[i];
    }

    ll maxi = *max_element(all(vals));
    ll A = n * maxi;
    ll T = A - sum;
    ll z = 0;

    for (int i = 0; i < n; i++)
    {
        z = __gcd(z, maxi - vals[i]);
    }
        
    printf("%lld %lld\n", T / z, z);
    
}