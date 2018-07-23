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

#define PI 3.141592653

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct pt {
    ll x, y;

    pt(){}
    pt(ll x, ll y)
    {
        this->x = x;
        this->y = y;
    }
    pt operator+(pt B)
    {
        pt C;
        C.x = this->x + B.x;
        C.y = this->y + B.y;
        return C;
    }
    pt operator-(pt B)
    {
        pt C;
        C.x = this->x - B.x;
        C.y = this->y - B.y;
        return C;
    }
    bool operator==(pt B)
    {
        return this->x == B.x && this->y == B.y;
    }
};
ll dot(pt A, pt B)
{
    return A.x*B.x + A.y*B.y;
}
ll cross(pt O, pt A, pt B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double angle(pt O, pt A, pt B)
{
    double ans = abs(atan2(cross(O, A, B), dot(A-O, B-O)));

//    if (ans < 0) ans += 2 * PI;
//    if (ans > PI) ans = abs(ans - 2*PI);

    return PI - ans;
}

double distance(pt A, pt B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}


int V, E;
double D;

vector<pt> vet_vertex;
vector<vi> vet_adj;
vector<vector<double>> dp;

bool dfs(int va, int vo, double dist, double max_angle, double limit_angle) {

    if (max_angle > limit_angle) {
        return false;
    }

    if (dist > D) {
        return false;
    }

    if (vo == V - 1) {
        return true;
    }

    if (va != -1) {
        if (dp[vo][va] < dist) return false;

        dp[vo][va] = dist;
    }


    if (va == -1) {

        //beggin
        for (auto &vb : vet_adj[vo]) {


                pt o = vet_vertex[vo];
                pt b = vet_vertex[vb];

                if (dfs(vo, vb, distance(o, b) + dist, 0, limit_angle)) {
                    return true;
                }
        }

    } else {

        for (auto vb : vet_adj[vo]) {


                pt a = vet_vertex[va];
                pt o = vet_vertex[vo];
                pt b = vet_vertex[vb];

                if (dfs(vo, vb, distance(o, b) + dist, max(max_angle, angle(o, a, b)), limit_angle)) {
                    return true;
                }
        }
    }

    return false;

}


double solve() {
    double upper = 2*PI;
    double lower = 0.0;
    double mid;


    while ((lower < upper && abs(lower - upper) > 1.0e-9)) {

        mid = lower + (upper - lower) / 2;

        dp.clear();
        dp.resize(V + 1, vector<double>(V + 1, 999999999));

        if (dfs(-1, 0, 0, 0, mid)) {
            upper = mid;
        } else {
            lower = mid;
        }
    }


    if (abs(upper - 2*PI) > 1.0e-8) {

        return RAD_to_DEG(upper);

    } else {

        return -1;

    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E >> D;

    vet_vertex.resize(V);
    for (int i = 0; i < V; ++i) {
        cin >> vet_vertex[i].x >> vet_vertex[i].y;
    }


    vet_adj.resize(V);
    for (int i = 0; i < E; ++i) {
        int u, v;

        cin >> u >> v;

        --u, --v;

        vet_adj[u].pb(v);
    }



    double ans = solve();

    if (ans != -1) {

        printf("%.8lf\n", ans);

    } else {

        printf("Impossible\n");

    }


    return 0;
}
