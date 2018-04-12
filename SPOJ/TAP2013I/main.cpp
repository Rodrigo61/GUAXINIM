using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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

#define INF 99999999


int R, C;
vector<vi> mat;


bool is_possible(int M){

    if(M >= mat[0][0]) return false;

    vector<vi> visited(R, vi(C, 0));
    vector<vi> dist(R, vi(C, INF));

    dist[0][0] = M;
    visited[0][0] = 1;

    queue<pii> q;

    q.push(mp(0,0));

    while(!q.empty()){
        pii u = q.front();
        q.pop();


        if(u.first + 1 < R && !visited[u.first + 1][u.second] && dist[u.first][u.second] + 1 < mat[u.first + 1][u.second]){
            visited[u.first + 1][u.second] = 1;
            dist[u.first + 1][u.second] = dist[u.first][u.second] + 1;
            q.push(mp(u.first + 1, u.second));
        }

        if(u.first - 1 >= 0 && !visited[u.first - 1][u.second] && dist[u.first][u.second] + 1 < mat[u.first - 1][u.second]){
            visited[u.first - 1][u.second] = 1;
            dist[u.first - 1][u.second] = dist[u.first][u.second] + 1;
            q.push(mp(u.first-1, u.second));
        }

        if(u.second + 1 < C && !visited[u.first][u.second + 1] && dist[u.first][u.second] + 1 < mat[u.first][u.second + 1]){
            visited[u.first][u.second + 1] = 1;
            dist[u.first][u.second + 1] = dist[u.first][u.second] + 1;
            q.push(mp(u.first, u.second + 1));
        }

        if(u.second - 1 >= 0 && !visited[u.first][u.second - 1] && dist[u.first][u.second] + 1 < mat[u.first][u.second - 1]){
            visited[u.first][u.second - 1] = 1;
            dist[u.first][u.second - 1] = dist[u.first][u.second] + 1;
            q.push(mp(u.first, u.second - 1));
        }

    }


    return dist[R-1][C-1] != INF;
}

int solve(){
    int upper = 10000000;
    int lower = 0;
    int mid = lower + (upper-lower + 1)/2;

    while(lower < upper){
        mid = lower + (upper-lower + 1)/2;

        if(is_possible(mid)){
            lower = mid;
        }else{
            upper = mid-1;
        }
    }

    return lower;

}

int main(){

    scanf("%d%d", &R, &C);

    mat.resize(R, vi(C));
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int maxi_min = solve();

    if(mat[0][0] <= 0 || !is_possible(maxi_min)){
        printf("-1\n");
    }else{
        printf("%d\n", maxi_min);
    }

    return 0;
}
