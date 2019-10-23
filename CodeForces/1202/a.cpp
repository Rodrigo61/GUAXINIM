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
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;

        reverse(all(y));
        reverse(all(x));

        int one_y = 0;
        for (int i = 0; i < y.size(); i++)
        {
            if (y[i] == '1')
            {
                one_y = i;
                break;
            }
        }
        
        int one_x = 0;
        for (int i = one_y; i < x.size(); i++)
        {
            if (x[i] == '1')
            {
                one_x = i;
                break;
            }
        }
        
        printf("%d\n", one_x - one_y);
    }
    
}