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

int V;
int V_left, V_right;
vector<vi> vet_adj;
vi match;
vi visited;

struct Person{
    int height;
    char sex;
    string music, sport;
};

bool aug(int u) {

    if (visited[u])
		return false;
    visited[u] = 1;

	for (auto &v : vet_adj[u]) {

        if (match[v] == -1 || aug(match[v])) {
            match[v] = u;
            return true;
        }
    }

	return false;
}

bool couple(Person &p1, Person &p2) {

    return abs(p1.height - p2.height) <= 40 && p1.sex != p2.sex && p1.music == p2.music && p1.sport != p2.sport;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n_cases;
    cin >> n_cases;

    for (size_t q = 0; q < n_cases; q++) {

        cin >> V;

        vector<Person> male;
        vector<Person> female;


        for (size_t i = 0; i < V; i++) {
            Person new_person;
            cin >> new_person.height >> new_person.sex >> new_person.music >> new_person.sport;

            if (new_person.sex == 'M') {
                male.pb(new_person);
            } else {
                female.pb(new_person);
            }
        }

        V_left = male.size();
        V_right = female.size();

        vet_adj.clear();
        vet_adj.resize(V_left);
        for (int i = 0; i < V_left; ++i) {
            for (size_t j = 0; j < V_right; j++) {
                if (couple(male[i], female[j])) {
                    vet_adj[i].pb(V_left + j);
                }
            }
        }

        int MCBM = 0;
        match.assign(V, -1);
    	for (int l = 0; l < V_left; l++) {
            visited.assign(V_left, 0);
    	    MCBM += aug(l);
    	}

        deb("V_left = ", V_left);
        deb("V_right = ", V_right);
        deb("MCBM = ", MCBM);

        printf("%d\n", V - MCBM);

    }

    return 0;
}
