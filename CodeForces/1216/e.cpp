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

int digits(int i)
{
    int cnt = 0;
    while (i)
    {
        cnt++;
        i /= 10;
    }
    
    return cnt;
}

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        ll k;
        scanf("%lld", &k);

        int count = 0;
        int total_digits = 0;
        int i;
        for (i = 1; ; i++)
        {
            total_digits += digits(i);
            int new_count = count + total_digits;
            if (new_count < k)
            {
                count = new_count;
            }
            else
            {
                break;
            }
        }
        db(i);
        db(count);

        k -= count;
        for (int j = 1; k; j++)
        {
            if (k - digits(j) > 0)
            {
                k -= digits(j);
            }
            else
            {
                string t = to_string(j);
                printf("%c\n", t[k - 1]);
                break;
            }
        }
        
        
    }
    
}