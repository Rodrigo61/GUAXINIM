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
        string b;
        cin >> b;

        for (int i = 0; i < b.size(); i++)
        {
            if (i % 2 == 0 || i == b.size() - 1) {
                printf("%c", b[i]);
            }
        }
        printf("\n");
    }
    
} 