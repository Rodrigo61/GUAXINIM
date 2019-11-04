#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
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
 
int szs[55];
int n;
int dp[2][2501];
 
int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        int zero_count = 0;
 
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            szs[i] = (int)str.size();
            for (char c : str)
                if (c == '0')
                    ++zero_count;
        }

        if(n == 1)
        {
            if (szs[0] & 1 || zero_count % 2 == 0)
                printf("1\n");
            else
                printf("0\n");
            continue;
        }

        for (int i = 0; i <= zero_count; i++)
        {
            dp[1][i] = -INF;
        }
        dp[1][0] = 0;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int zeros = 0; zeros <= zero_count; zeros++)
            {
                int maxi = 0;
                
                for (int k = max(0, zeros - szs[idx]); k <= zeros; k++)
                {
                    if (szs[idx] & 1)
                        maxi = max(maxi, dp[1][k] + 1);
                    else
                        maxi = max(maxi, dp[1][k] + ((zeros - k) % 2 == 0));
                }
                
                dp[0][zeros] = maxi;
            }
            for (int i = 0; i <= zero_count; i++)
            {
              //  printf("%d ", dp[0][i]);
                dp[1][i] = dp[0][i];
            }
            //printf("\n");
        }
 
        printf("%d\n", dp[1][zero_count]);
    }
    
}