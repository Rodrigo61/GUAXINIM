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

struct rect
{
    int x1, y1, x2, y2;
};

int main()
{
    rect w, b1, b2;
    scanf("%d%d%d%d", &w.x1, &w.y1, &w.x2, &w.y2);
    scanf("%d%d%d%d", &b1.x1, &b1.y1, &b1.x2, &b1.y2);
    scanf("%d%d%d%d", &b2.x1, &b2.y1, &b2.x2, &b2.y2);

    if (b1.y2 > b2.y2) swap(b1, b2);

    for (int i = w.x1; i <= w.x2; i++)
    {
        if ((i < b1.x1 || i > b1.x2) && (i < b2.x1 || i > b2.x2))
        {
            return !printf("YES\n");
        }

        if ((i < b1.x1 || i > b1.x2))
        {
            if (!(w.y1 >= b2.y1 && w.y2 <= b2.y2))
                return !printf("YES\n");
            continue;
        }

        if ((i < b2.x1 || i > b2.x2))
        {
            if (!(w.y1 >= b1.y1 && w.y2 <= b1.y2))
                return !printf("YES\n");
            continue;
        }

        if (b1.y2 < b2.y1)
        {
            if (!((w.y1 >= b1.y1 && w.y2 <= b1.y2) || (w.y1 >= b2.y1 && w.y2 <= b2.y2)))
                return !printf("YES\n");
        }
        else
        {
            if (!(w.y1 >= min(b1.y1, b2.y1) && w.y2 <= max(b1.y2, b2.y2)))
            {
                return !printf("YES\n");
            }
        }
    }

    if (b1.x2 > b2.x2) swap(b1, b2);

    for (int i = w.y1; i <= w.y2; i++)
    {
        if ((i < b1.y1 || i > b1.y2) && (i < b2.y1 || i > b2.y2))
        {
            db(i);
            return !printf("YES\n");
        }

        if ((i < b1.y1 || i > b1.y2))
        {
            if (!(w.x1 >= b2.x1 && w.x2 <= b2.x2))
                return !printf("YES\n");
            continue;
        }

        if ((i < b2.y1 || i > b2.y2))
        {
            if (!(w.x1 >= b1.x1 && w.x2 <= b1.x2))
                return !printf("YES\n");
            continue;
        }

        if (b1.x2 < b2.x1)
        {
            if (!((w.x1 >= b1.x1 && w.x2 <= b1.x2) || (w.x1 >= b2.x1 && w.x2 <= b2.x2)))
                return !printf("YES\n");
        }
        else
        {
            if (!(w.x1 >= min(b1.x1, b2.x1) && w.x2 <= max(b1.x2, b2.x2)))
            {
                return !printf("YES\n");
            }
        }
    }
    
    printf("NO\n");
}