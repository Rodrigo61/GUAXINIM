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
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, bool> in_list;
    list<int> lst;
    for (int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);

        if (!in_list[v])
        {
            lst.push_front(v);
            in_list[v] = true;
            if ((int)lst.size() > k)
            {
                in_list[lst.back()] = false;
                lst.pop_back();
            }
        }
    }

    printf("%d\n", (int)lst.size());
    for (auto i : lst)
        printf("%d ", i);
    
}