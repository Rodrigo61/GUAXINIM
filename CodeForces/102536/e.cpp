#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
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

#define MAXN 5123
#define MAXK 55

int tc;
int r, c, k;
pii A, B;
char grid[MAXN][MAXN];

pii opt[] = {{-1, 0}, {1, 0}, {0, -1}, {0, +1}};

struct vertex {
    int i, j, k;

    bool operator<(const vertex &o) const{
        return false;
    }
};


int main()
{
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d%d%d\n", &r, &c, &k);

        vector<vector<vector<int>>> dist(r, vector<vector<int>>(c, vector<int>(k + 1, INF)));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%c", &grid[i][j]);
                if (grid[i][j] == 'A') {
                    A = {i, j};
                }
                if (grid[i][j] == 'B') {
                    B = {i, j};
                }
            }
            scanf("\n");
        }

        dist[A.first][A.second][0] = 0;
        priority_queue<pair<int, vertex>> pq;
        pq.push({0, {A.first, A.second, 0}});

        while(!pq.empty()) {
            vertex u = pq.top().second;
            int du = -pq.top().first;
            pq.pop();

            if (dist[u.i][u.j][u.k] < du) {
                continue;
            }

            if (u.k - 1 >= 0 && du + 1 < dist[u.i][u.j][u.k - 1]) {
                if (grid[u.i][u.j] != 'D' || u.k >= 2) {
                    dist[u.i][u.j][u.k - 1] = du + 1;
                    pq.push({-dist[u.i][u.j][u.k - 1], {u.i, u.j, u.k - 1}});
                }
            }

            for (auto o : opt) {

                pii adj = {u.i + o.fi, u.j + o.se};
                if (adj.fi >= 0 && adj.fi < r && adj.se >= 0 && adj.se < c) {
                    if (grid[adj.first][adj.second] == '.' || grid[adj.first][adj.second] == 'B' || grid[adj.first][adj.second] == 'A') {
                        if (du + 1 < dist[adj.first][adj.second][u.k]) {
                            dist[adj.first][adj.second][u.k] = du + 1;
                            pq.push({-dist[adj.first][adj.second][u.k], {adj.first, adj.second, u.k}});
                        }
                    }
                    if (u.k + 1 <= k && grid[adj.first][adj.second] == 'D') {
                        if (du + 2 < dist[adj.first][adj.second][u.k + 1]) {
                            dist[adj.first][adj.second][u.k + 1] = du + 2;
                            pq.push({-dist[adj.first][adj.second][u.k + 1], {adj.first, adj.second, u.k + 1}});
                        }
                    }
                }
            }
        }

        int res = INF;
        for (int i = 0; i <= k; i++)
        {
            res = min(res, dist[B.first][B.second][i]);
        }

        if (res >= INF) {
            printf("HAHAHUHU");
        } else {
            printf("%d", res);
        }
        if (tc != 0)
            printf("\n");
    }
    
}