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
#define sz(x) int(x.size())
typedef long double ld;

#define MAXN 55

char aux[MAXN];
char res[MAXN];
string str;
vii vet_pos;
char dpr[MAXN][MAXN];

bool solve(int pos, int s) {
    if (pos == sz(vet_pos)) {
        db(true);
        return true;
    }

    if (s == sz(str))
        return false;
    

    int next_s;
    for (next_s = s + 1; next_s < sz(str) && str[s] == str[next_s]; next_s++);

    db(pos);
    db(next_s);
    int it_pos = pos;
    bool res = false;
    for (int j = s; j < next_s; j++)    {
        int tot = 0;
        for (int i = 0; i < pos; i++)
            tot += abs(vet_pos[i].second - vet_pos[it_pos].second);
        if (tot == vet_pos[it_pos].first) {
            
            if (solve(it_pos + 1, next_s)) {
                res = true;
                dpr[pos][s] = str[s];
            }
        } 
        else
        {
            break;
        }
        ++it_pos;
    }

    res |= solve(pos, next_s);
    return res;
}


int main()
{
    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        scanf("%s", aux);
        str = aux;
        sort(all(str));
        reverse(all(str));
        db(str);

        int m;
        vet_pos.clear();
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int v;
            scanf("%d", &v);
            vet_pos.pb({v, i});
        }
        sort(all(vet_pos));
        
        db(sz(vet_pos));
        db(solve(0, 0));
    }
    
}