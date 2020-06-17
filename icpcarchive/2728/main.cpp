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

#define MAXN 55
#define MAXT 212

#define FRONT 1
#define BACK 0



struct train
{
    int next_station;
    int dir;
    int cooldown;
    int departure;
};

int N, T;
int dists[MAXN];
bool has_train[MAXN][MAXT][2];
vector<train> vet_trains;
int vis[MAXN][MAXT];
int dp[MAXN][MAXT];
int dp_t;

void simulate()
{
    for (int i = 0; i <= T; i++)
    {
        for (auto &train : vet_trains)
        {

            if (i < train.departure) continue;
            train.cooldown--;
            
            if(train.cooldown == 0)
            {
                int station = train.next_station;

                if (train.dir == FRONT)
                {
                    train.next_station++;
                    if (train.next_station == N)
                    {
                        continue;
                    }
                    else
                    {
                        train.cooldown = dists[station];
                    }
                }
                else
                {
                    train.next_station--;
                    if (train.next_station == - 1)
                    {
                        continue;
                    }
                    else
                    {
                        train.cooldown = dists[station - 1];
                    }
                    
                }

                has_train[station][i][train.dir] = 1;

            }
        }
    }
}

int solve(int s, int t)
{
    if (t > T)
        return INF;
    if (t == T)
    {
        if (s == N - 1)
        {
            return 0;
        }
        else
        {
            return INF;
        }
    }

    if (vis[s][t] == dp_t)
        return dp[s][t];
    vis[s][t] = dp_t;

    int res = solve(s, t + 1) + 1;

    if (has_train[s][t][FRONT])
    {
        res = min(res, solve(s + 1, t + dists[s]));
    }
    if (has_train[s][t][BACK])
    {
        res = min(res, solve(s - 1, t + dists[s - 1]));
    }

    return dp[s][t] = res;
}

void restart()
{
    memset(has_train, 0, sizeof(has_train));
    vet_trains.clear();
}

signed main()
{
    while (scanf("%d", &N), N != 0)
    {
        restart();
        scanf("%d", &T);
        for (int i = 0; i < N - 1; i++)
        {
            scanf("%d", &dists[i]);
        }
        
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int d;
            scanf("%d", &d);
            vet_trains.pb({0, FRONT, 1, d});
        }

        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int d;
            scanf("%d", &d);
            vet_trains.pb({N - 1, BACK, 1, d});
        }
        
        simulate();

        // for (int i = 0; i <= T; i++)
        // {
        //     printf("T = %d\n", i);
        //     for (int s = 0; s < N; s++)
        //     {
        //         printf("\tS = %d: ", s);
        //         printf("%d %d\n", has_train[s][i][FRONT], has_train[s][i][BACK]);
        //     }
        // }
        

        dp_t++;
        int res = solve(0, 0);
        printf("Case Number %d: ", dp_t);
        if (res >= INF)
            printf("impossible\n");
        else
            printf("%d\n", res);

    }

}