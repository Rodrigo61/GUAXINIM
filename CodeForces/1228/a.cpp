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

bool check (int i)
{
    vi freq(10);
    while (i > 0)
    {
        freq[i%10]++;
        if (freq[i%10] > 1)
            return false;
        i /= 10;
    }
    return true;
}

int main()
{
    int l, r;
    scanf("%d%d", &l, &r);

    for (int i = l; i <= r; i++)
    {
        if (check(i))
            return !printf("%d\n", i);
    }

    printf("-1\n");
    
}