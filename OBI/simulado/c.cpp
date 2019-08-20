#include <bits/stdc++.h>
 
using namespace std;

#define printvar(x) cerr << #x << " = " << x << endl;
 
#define LEFTY(x)  2 * x + 1
#define RIGHTY(x) 2 * x + 2
#define ll long long

ll n, m, q;
 
vector<vector<ll>> matriz;
 
vector<vector<ll>> segtree;
 
void build(int atual, int l, int r, int atualSeg)
{
    if(l == r)
    {
        //printvar(matriz[atualSeg][l])
        segtree[atualSeg][atual] = matriz[atualSeg][l];
        return;
    }
 
    int metade = (l + r) / 2;
    build(LEFTY(atual),  l, metade, atualSeg);
    build(RIGHTY(atual), metade + 1, r, atualSeg);
 
    segtree[atualSeg][atual] = segtree[atualSeg][LEFTY(atual)] + segtree[atualSeg][RIGHTY(atual)];
}
 
ll query(int atualSeg, int atual, int l, int r, int t_l, int t_r)
{
    if(l >= t_l && r <= t_r)
    {
        return segtree[atualSeg][atual];
    }
 
    if(l > t_r || r < t_l)
        return 0;
 
    int metade = (l + r) / 2;
 
    return query(atualSeg, LEFTY(atual), l, metade, t_l, t_r) + query(atualSeg, RIGHTY(atual), metade + 1, r, t_l, t_r);
}
 
signed main()
{
    scanf("%lld %lld", &n, &m);
 
    matriz  = vector<vector<ll>>(n + 1, vector<ll>(m + 1));
    segtree = vector<vector<ll>>(n + 1, vector<ll>(4 * m + 1));
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            scanf("%lld", &matriz[i][j]);
    }
 
    for(int i = 0; i < n; i++)
        build(0, 0, m - 1, i);
 
    scanf("%lld", &q);
 
    for(int i = 0; i < q; i++)
    {
        int i1, j1, i2, j2;
 
        scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
 
        i1--;
        i2--;
        j1--;
        j2--;
 
        ll resp = 0;
 
        //printvar(resp);
 
        for(int j = i1; j <= i2; j++)
        {
            //printvar(j);
            resp += query(j, 0, 0, m - 1, j1, j2);
            //printvar(resp)
        }
        printf("%lld\n", resp);
    }
}
