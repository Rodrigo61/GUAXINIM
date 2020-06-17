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

#define HORIZONTAL 1
#define VERTICAL 0

struct car {
    int sz, orientation;
    pii start;
};

int grid[10][10];
pii NULL_PAIR = {-1, -1};
int res = INF;

vector<car> vet_car(11);

void print_grid() {

    // for (int i = 0; i < 6; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         printf("%d ", grid[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    
}

void find_car(int target) {
    pii first = NULL_PAIR;
    for (int i = 0; i < 6 && first == NULL_PAIR; i++)
    {
        for (int j = 0; j < 6 && first == NULL_PAIR; j++)
        {
            if (grid[i][j] == target) {
                first = {i, j};
            }
        }
    }

    if (first != NULL_PAIR) {
        vet_car[target].start = first;
        if (grid[first.fi][first.se + 1] == target)
        {
            vet_car[target].orientation = HORIZONTAL;
            vet_car[target].sz = 1;
            for (int j = first.se + 1; grid[first.fi][j] == target; j++)
                ++vet_car[target].sz;
        }
        else
        {
            vet_car[target].orientation = VERTICAL;
            vet_car[target].sz = 1;
            for (int i = first.fi + 1; grid[i][first.se] == target; i++)
                ++vet_car[target].sz;
        }
    }
}

bool move_a(int target) {
    if (vet_car[target].sz) {
        pii start = vet_car[target].start;
        int sz = vet_car[target].sz;
        
        if (vet_car[target].orientation == HORIZONTAL) {
            int new_end = start.se + sz;
            
            if (new_end < 6 && new_end >= 0 && grid[start.fi][new_end] == 0) {
                grid[start.fi][start.se] = 0;
                grid[start.fi][new_end] = target;
                vet_car[target].start = {start.fi, start.se + 1};
                return true;
            }
        }
        else
        {
            int new_end = start.fi + sz;
            if (new_end < 6 && grid[new_end][start.se] == 0) {
                grid[start.fi][start.se] = 0;
                grid[new_end][start.se] = target;
                vet_car[target].start = {start.fi + 1, start.se};
                return true;
            }
        }
    }

    return false;
}

bool move_b(int target) {
    
    if (vet_car[target].sz) {
        pii start = vet_car[target].start;
        int sz = vet_car[target].sz;
        
        if (vet_car[target].orientation == HORIZONTAL) {
            int new_start = start.se - 1;
            
            if (new_start >= 0 && grid[start.fi][new_start] == 0) {
                grid[start.fi][start.se + sz - 1] = 0;
                grid[start.fi][new_start] = target;
                vet_car[target].start = {start.fi, new_start};
                return true;
            }
        }
        else
        {
            int new_start = start.fi - 1;
            if (new_start >= 0 && grid[new_start][start.se] == 0) {
                grid[start.fi + sz - 1][start.se] = 0;
                grid[new_start][start.se] = target;
                vet_car[target].start = {new_start, start.se};
                return true;
            }
        }
    }

    return false;
}


void solve(int steps) {

    bool free_pass = true;
    for (int j = vet_car[1].start.second + vet_car[1].sz; j < 6; j++)
    {
        if (grid[vet_car[1].start.fi][j] != 0)
        {
            free_pass = false;
            break;
        }
    }

    if (free_pass) {
        res = min(res, steps + (6 - vet_car[1].start.se));
        return;
    }

    if (steps >= 7) {
        return;
    }

    for (int i = 1; i <= 10; i++)
    {
        if (move_a(i)) {
            solve(steps + 1);
            move_b(i);
        }

        if (move_b(i)) {
            solve(steps + 1);
            move_a(i);
        }
    }
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    for (int i = 1; i <= 10; ++i)
        find_car(i);
        

    solve(0);

    if (res <= 10) {
        printf("%d\n", res);
    }
    else
    {
        printf("-1\n");
    }
    
}