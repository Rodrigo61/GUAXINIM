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

#define MAXN 112345

int vals[MAXN];
int freq[MAXN];
int used[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
        freq[vals[i]] = 1;
    }

    int last_v = vals[0];
    int c = 0;
    vi res(n);
    for (int i = 0; i < n; i++)
    {
        
        if (vals[i] != last_v) {
            res[i] = last_v;
        } else {
            while (freq[c]) c++;
            res[i] = c;
            c++;
        }

        last_v = vals[i];
    }
    
    for(int i : res)
        printf("%d ", i);
    
}