bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include "bits/stdc++.h"
using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


/// Debug Start
template<class T1> void deb(T1 e1)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << endl;
    }
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << endl;
    }
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << endl;
    }
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1, T2 e2, T3 e3, T4 e4)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << endl;
    }
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << endl;
    }
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1, T2 e2, T3 e3, T4 e4 ,T5 e5, T6 e6)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << space << e6 << endl;
    }
}


template<typename T>
void print_vector_debug(const T& t) {

    if(debug) {
        cout << "[DEBUG] VECTOR:";
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            if ((i + 1) != t.cend()) {
                cout << *i << " ";
            } else {
                cout << *i << endl;
            }
        }
    }
}

template<typename T>
void print_array_debug(const T arr, int size){

    if(debug) {
        cout << "[DEBUG] VECTOR:";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << space;
        }
        cout << endl;
    }
}

template<typename T>
void print_2Darray_debug(const T arr, int rows, int cols){

    if(debug) {
        cout << "[DEBUG] Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << arr[i][j] << space;
            }
            cout << endl;
        }
        cout << endl;
    }
}

template<typename T>
void print_matrix_debug(const T& t) {
    if(debug) {
        cout << "[DEBUG] MATRIX:" << endl;
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            for(auto j = i->cbegin(); j != i->cend(); ++j){
                cout << *j << " ";
            }
            cout << endl;
        }
    }
}
//</editor-fold>

class UnionFind {
private:
  vi rep, rank, set_sz;
  int n_sets;
public:

	UnionFind(int N) {
		set_sz.assign(N, 1);
		n_sets = N; rank.assign(N, 0);
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

	int sets_count() {
		return n_sets;
	}

};

struct Edge{
	int u, v;
	double weight;

    bool operator < (Edge const& other) const {
        return this->weight < other.weight;
    }
};

double get_dist(pii a, pii b) {

    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (int q = 0; q < n_cases; q++) {

        int V, R;
        cin >> V >> R;

        vii cities(V);
        for (size_t i = 0; i < V; i++) {
            cin >> cities[i].first >> cities[i].second;
        }

        vector<Edge> edge_list;
        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                double dist = get_dist(cities[i], cities[j]);

                Edge new_edge;
                new_edge.u = i;
                new_edge.v = j;
                new_edge.weight = dist;

                edge_list.pb(new_edge);
            }
        }

        sort(all(edge_list));

        if (debug) {
            for (size_t i = 0; i < edge_list.size(); i++) {
                printf(" %lf", edge_list[i].weight);
            }
            printf("\n");
        }

        double mst_cost = 0;
        UnionFind UF(V);
        auto it = edge_list.begin();
        int count_states = 0;
        double mst_intra;

        deb("R = ", R);
        Edge curr_edge;
        while (UF.sets_count() > 1) {
            curr_edge = *(it++);
            if (!UF.is_same_set(curr_edge.u, curr_edge.v)) {

                if (curr_edge.weight > R) {
                    break;
                }

                mst_cost += curr_edge.weight;
                UF.union_by_rank(curr_edge.u, curr_edge.v);
            }
        }

        count_states = UF.sets_count();
        mst_intra = mst_cost;
        mst_cost = 0;

        while (UF.sets_count() > 1) {

            if (!UF.is_same_set(curr_edge.u, curr_edge.v)) {
                mst_cost += curr_edge.weight;
                UF.union_by_rank(curr_edge.u, curr_edge.v);
            }

            curr_edge = *(it++);
        }

        printf("Case #%d: %d %d %d\n", q + 1, count_states, (int)round(mst_intra), (int)round(mst_cost));

    }

    return 0;
}
