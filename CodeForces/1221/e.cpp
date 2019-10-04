#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long0
#define vll vector<ll>
#define ull unsigned long long
typedef long double ld;

#define MAXN 312345

char aux[MAXN];

int main()
{
    int q;
    scanf("%d", &q);

    while (q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%s", aux);
        string str = aux;
        int curr_len = 0;
        vi types(5);
        int type_4_len = 0;

        for (int i = 0; i < (int)str.size(); ++i)
        {
            char c = str[i];
            if (c == 'X')
            {
                if (curr_len >= b && curr_len < a)
                    types[2]++;
                else if (curr_len >= 2*b)
                {
                    types[4]++;
                    type_4_len = curr_len;
                }
                else if (curr_len >= a)
                    types[3]++;
                curr_len = 0;
            }
            else
                curr_len++;
        }
        if (curr_len >= b && curr_len < a)
            types[2]++;
        else if (curr_len >= 2*b)
        {
            types[4]++;
            type_4_len = curr_len;
        }
        else if (curr_len >= a)
            types[3]++;

        db(types[2]);
        db(types[3]);
        db(types[4]);

        if (types[2] || types[4] >= 2)
        {
            printf("NO\n");
        }
        else
        {
            bool win = false;
            if (types[4])
            {
                db(type_4_len);
                for (int r = 0; r + a <= type_4_len; r++)
                {
                    int l = type_4_len - r - a;
                    int count_3 = types[3];

                    if (l < a && l >= b) continue;
                    if (r < a && r >= b) continue;
                    if (l >= 2*b || r >= 2*b) continue;

                    if (l >= a && l < 2 * b)
                        count_3++;
                    if (r >= a && r < 2 * b)
                        count_3++;
                    db(count_3);
                    if (count_3 % 2 == 0)
                        win  = true;
                }
            }
            else
                win = types[3] % 2;

            printf(win ? "YES\n":"NO\n");
        }

    }
    
}