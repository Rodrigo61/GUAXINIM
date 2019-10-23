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
 
#define MAXN 2123456
 
int reacheable[10][10];
char aux[MAXN];
 
int main()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            reacheable[i][j] = -1;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            int curr = (i * j) % 10;
            if (reacheable[i][curr] == -1)
                reacheable[i][curr] = j;
        }
    }

    scanf("%s", aux);
    string str = aux;
 
    int ans[10][10];
 
    for (int n = 0; n < 10; n++)
    {
        for (int m = n; m < 10; m++)
        {
            int total = 0;
            for (int i = 0; i < (int)str.size() - 1; i++)
            {
                int target;
                int a = str[i] - '0';
                int b = str[i + 1] - '0';
                if (a <= b)
                    target = b - a;
                else
                    target = 10 + b - a;
                
                if (n == 0 && m == 1)
                db(target);
 
                int best = INF;
    
                if (reacheable[n][target] != -1)
                    best = min(best, reacheable[n][target] - 1);
        
                if (reacheable[m][target] != -1)
                    best = min(best, reacheable[m][target] - 1);

                for (int j = 0; j < 10; j++)
                {
                    int target2;
                    if (target >= j)
                        target2 = target - j;
                    else
                        target2 = 10 + target - j;

                    if (reacheable[n][j] != -1 &&
                        reacheable[m][target2] != -1)
                        {
                            best = min(best, reacheable[n][j] + reacheable[m][target2] - 1);
                            if (n == 0 && m == 1)
                            {
                                db(j);
                                db(target2);
                                db(best);
                            }
                            
                        }
                }
 
                if (best < INF)
                {
                    total += best;
                }
                else
                {
                    total = -1;
                    break;
                }
                
            }
 
            ans[n][m] = ans[m][n] = total;
        }
    }
 
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
   
}