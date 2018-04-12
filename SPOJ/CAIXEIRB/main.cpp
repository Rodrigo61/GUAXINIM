using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


//</editor-fold>

typedef struct Coord {
    int i, j;

    Coord(int i, int j) {
        this->i = i;
        this->j = j;
    }

    bool is_valid(int R, int C){

        if(i >= 0 && i < R && j >= 0 && j < C) {
            return true;
        }

        return false;
    }
} Coord;

class Solution {
public:
    Coord RIGHT(0,1);
    Coord LEFT(0,-1);
    Coord DOWN(1,0);
    Coord UP(-1,0);

    vector<Coord> vet_direction = {RIGHT, DOWN, LEFT, UP}

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int N = matrix.size();
        int M = matrix[0].size();

        int direction_idx = 0;
        Coord curr_coord(0,-1);
        int visited_count = 0;
        int elem_count = matrix.size() * matrix[0].size();

        vector<int> ans;

        while(visited_count != elem_count) {

            ans.push_back(matrix[curr_coord.i][curr_coord.j]);
            matrix[curr_coord.i][curr_coord.j] = INF;
            ++visited_count;

            Coord next_coord;
            next_coord.i = curr_coord.i + vet_direction[direction_idx].i;
            next_coord.j = curr_coord.j + vet_direction[direction_idx].j;

            if(!next_coord.is_valid(N, M) || matrix[next_coord.i][next_coord.j] == INF) {
                direction_idx = (direction_idx + 1) % 4;
                curr_coord.i = curr_coord.i + vet_direction[direction_idx].i;
                curr_coord.j = curr_coord.j + vet_direction[direction_idx].j;
            }else{
                curr_coord = next_coord;
            }
        }

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cases_count = 0;

    while(cin >> C >> V, C + V != 0){

        vet_adj.clear();
        vet_adj.resize(C);

        int u, v;
        for (size_t i = 0; i < C-1; i++) {
            cin >> u >> v;
            --u, --v;


            vet_adj[u].push_back(v);
            vet_adj[v].push_back(u);
        }

        wanted_vertices.clear();
        wanted_vertices.resize(C);
        fill(all(wanted_vertices), 0);

        for (size_t i = 0; i < V; i++) {
            cin >> u;
            wanted_vertices[u-1] = 1;
        }

        C_count = C;
        visited.clear();
        visited.resize(C);
        fill(all(visited), 0);
        dfs(0);

        cout << "Teste " << ++cases_count << endl;
        cout << (C_count - 1)*2 << endl << endl;
    }

    return 0;
}
