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

struct Car{

    vi vet_checks;
    int last_checked;
    int car_id;

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K, N, M;

    cin >> K >> N >> M;


    vector<Car> vet_cars(N);

    for (int i = 0; i < N; ++i) {
        vet_cars[i].car_id = i;
        vet_cars[i].last_checked = 0;
        vet_cars[i].vet_checks.clear();
    }


    for (int i = 1; i <= M; ++i) {

        int car_id, check;
        cin >> car_id >> check;

        --car_id, --check;



        Car &curr_car = vet_cars[car_id];

        deb("car_id = ", car_id);
        deb("check = ", check);

        deb("curr_car.last_checked = ", curr_car.last_checked);
        if (curr_car.last_checked == 0 && check == 0) {

            deb("first");
            deb("curr_car.vet_checks.size() = ", curr_car.vet_checks.size());
            curr_car.last_checked = i;
            curr_car.vet_checks.pb(0);



        } else if (curr_car.last_checked != 0 && check == (curr_car.vet_checks.back() + 1) % K) {

            curr_car.last_checked = i;
            curr_car.vet_checks.pb(check);

        }

    }


    sort(all(vet_cars), [](const Car &c1, const Car &c2) {

        if (c1.vet_checks.size() < c2.vet_checks.size()) {

            return true;

        } else if (c1.vet_checks.size() == c2.vet_checks.size()){

            return c1.last_checked > c2.last_checked;

        }

        return false;
    });


    reverse(all(vet_cars));

    for (int i = 0; i < N; ++i) {

        printf("%d", vet_cars[i].car_id + 1);

        if (i != N - 1) {
            printf(" ");
        }

    }
    printf("\n");

    return 0;
}
