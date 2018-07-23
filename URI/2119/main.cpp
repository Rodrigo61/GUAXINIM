bool debug = true;

#include "bits/stdc++.h"

using namespace std;

#define all(c) c.begin(), c.end()
#define mp(i,j) make_pair(i, j)
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;

template<class T1> void deb(T1 e1) {

    if (debug) {
        cout << "DEBUG: ";
        cout << e1 << endl;
    }
}

template<class T1> void deb(T1 e1, T1 e2) {

    if (debug) {
        cout << "DEBUG: ";
        cout << e1 << " " << e2 << endl;
    }
}

#define MOD 1000000009

class UnionFind {

private:

    vi rep, rank, set_sz;
    int n_sets;

public:
    UnionFind(int N) {
        set_sz.assign(N, 1);
        n_sets = N;
        rank.assign(N, 0);
        rep.assign(N, 0);

        for (int i = 0; i < N; i++) {
            rep[i] = i;
        }
    }

    int find_set(int i) {

        if (rep[i] == i) {
            return i;
        }

        rep[i] = find_set(rep[i]);

        return rep[i];
    }

    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    void union_by_rank(int i, int j) {
        if (!is_same_set(i, j)) {

            n_sets--;
            int rep_i = find_set(i);
            int rep_j = find_set(j);

            if (rank[rep_i] > rank[rep_j]) {
                rep[rep_j] = rep_i;
                set_sz[rep_i] += set_sz[rep_j];

            } else {
                rep[rep_i] = rep_j;
                set_sz[rep_j] += set_sz[rep_i];

                if (rank[rep_i] == rank[rep_j]) {
                    rank[rep_j]++;
                }
            }
        }
    }

    int set_count() {
        return n_sets;
    }

};

struct Edge {

    int u, v, weight;

    Edge(){}
    Edge(int i, int j, int c): u(i), v(j), weight(c){}

    bool operator < (Edge const& other) const {
        return this->weight < other.weight;
    }



};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, K;

    while(cin >> V >> E >> K){

        if (V == 1) {
            printf("0\n"); return 0;
        }

        set<int> jumps;
        for (size_t i = 0; i < K; i++) {
            int step;
            cin >> step;

            jumps.insert(step);
        }
        jumps.insert(1);

        int dp[10001];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
//      printf("c = %d\n", c);
        for (int i = 1; i < 10001; i++) {
            for (auto &c : jumps) {

                if (i - c >= 0){
                    dp[i] = (dp[i] + dp[i - c]) % MOD;
                }
            }
        }

        // if (debug) {
        //   for (int i = 0; i <= 11; ++i) {
        //     printf("%lld ", dp[i]);
        //   }
        //   printf("\n");
        // }


        vector<Edge> edge_list;
        for (size_t i = 0; i < E; i++) {
            int u, v, u2v;
            cin >> u >> v >> u2v;
            u = min(u, v);
            v = max(u, v);

            //  printf("u = %d  v = %d  u2v = %lld\n", u, v, dp[u2v]);

            edge_list.pb(Edge(u, v, dp[u2v]));
            edge_list.pb(Edge(v, u, dp[u2v]));
        }


//     int graph_dp[V + 1];
//     memset(graph_dp, 0, sizeof(graph_dp));
//     graph_dp[0] = 99999;
//
//     for (int i = 1; i < V; ++i) {
//
//   //    printf("i = %d\n", i);
//       for (auto &pv : vet_adj[i]) {
// //        printf("graph_dp[pv.first] = %d\n", graph_dp[pv.first]);
// //        printf("pv.second = %d\n", pv.second);
//         if (graph_dp[pv.first])
//           graph_dp[i] = max(graph_dp[i], min(pv.second, graph_dp[pv.first]));
//       }
// //      printf("graph_dp[i] = %d\n", graph_dp[i]);
//
//     }

        sort(all(edge_list));
        reverse(all(edge_list));
        UnionFind UF(V);

        vector<vii> vet_adj(V);

        auto it = edge_list.begin();
        while (it != edge_list.end() && !UF.is_same_set(0, V - 1)) {

            Edge edge = *it;

            if(!UF.is_same_set(edge.u, edge.v)) {
                // printf("edge inserted  u = %d   v = %d\n", edge.u, edge.v);
                vet_adj[edge.u].pb(mp(edge.v, edge.weight));
                vet_adj[edge.v].pb(mp(edge.u, edge.weight));
                UF.union_by_rank(edge.u, edge.v);
            }

            ++it;

        }

        vi visited(V, 0);
        vi dist(V, 999999);
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // printf("u = %d    dist = %d\n", u, dist[u]);

            for (auto &pv : vet_adj[u]) {
                if (!visited[pv.first]) {
                    visited[pv.first] = true;
                    dist[pv.first] = min(dist[u], pv.second);
                    q.push(pv.first);
                }
            }
        }



        if (dist[V - 1] != 999999) {
            printf("%d\n", dist[V - 1] % MOD);
        } else {
            printf("0\n");
        }


    }
    return 0;

}
