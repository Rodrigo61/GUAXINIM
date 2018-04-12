using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>


using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

typedef pair<int,int> pii;
typedef vector<int> vi;

//</editor-fold>

#define INF 9999999

vi dist;
vi parent;
int V, E;
vector< list<pii> > vet_adj;
int S, T;


void sssp(){

    fill(all(dist), INF);
    fill(all(parent), -1);
    priority_queue< pii, vector<pii>, greater<pii> > pq;

    dist[S] = 0;
    pq.push(mp(0,S));

    while(!pq.empty()){

        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if(d_u != dist[u]) continue;

        for(list<pii>::iterator it = vet_adj[u].begin(); it !=  vet_adj[u].end(); ++it){
            pii pv = *it;
            int v = pv.first;
            int u_v = pv.second;

            if(dist[u] + u_v < dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + u_v;
                pq.push(mp(dist[v], v));
            }
        }
    }
}


void remove_path(int root){

    if(parent[root] == -1) return;


    for(list<pii>::iterator it = vet_adj[parent[root]].begin(); it != vet_adj[parent[root]].end(); ++it){
        if(it->first == root){
            vet_adj[parent[root]].erase(it);
            break;
        }
    }

    remove_path(parent[root]);
}

void remove_best_paths(){

    for (size_t i = 0; i < V; i++) {
        for(list<pii>::iterator it = vet_adj[i].begin(); it != vet_adj[i].end(); ++it){

            pii pv = *it;
            if(pv.first == T){
                if(dist[i] + pv.second == dist[T]){
                    vet_adj[i].erase(it);
                    remove_path(pv.first);
                    break;
                }
            }
        }
    }

}

int quase_menor(){

    sssp();
    remove_best_paths();
    sssp();

    return dist[T];

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> V >> E, E+V != 0){

        cin >> S >> T;

        dist.clear();
        dist.resize(V);
        parent.clear();
        parent.resize(V);

        vet_adj.clear();
        vet_adj.resize(V);

        int u, v, u_v;
        for (size_t i = 0; i < E; i++) {
            cin >> u >> v >> u_v;
            vet_adj[u].push_back(mp(v, u_v));
        }

        int res = quase_menor();

        if(res == INF){
            cout << "-1" << endl;
        }else{
            cout << res << endl;
        }

    }


    return 0;
}
