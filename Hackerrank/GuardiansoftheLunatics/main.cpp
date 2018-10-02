bool debug = true;

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

#define INF 111111111111111111

int L, G;
vll acu_sum;
vector<vll> dp;

ll cost(int i, int j) 
{
	if (i > j) return 0;
	return (acu_sum[j] - acu_sum[i - 1]) * (j - i + 1);
}

void fill(int g, int i, int j, int p1, int p2) 
{
	
	if (i > j) return;
	
	//~ printf("i = %d  j = %d\n", i, j);
	
	int mid = (i + j) / 2;

	dp[g][mid] = INF;
	int min_k = p1;
	
	for (int k = p1; k <= p2 ; k++)
	{
		ll curr_cost = dp[g - 1][k] + cost(k + 1, mid);
		
		if (curr_cost < dp[g][mid])
		{
			dp[g][mid] = curr_cost;
			min_k = k;
		}
	}
	
	fill(g, i, mid - 1, p1, min_k);
	fill(g, mid + 1, j, min_k, p2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	scanf("%d %d", &L, &G);
	
	dp.resize(G + 1, vll(L + 1, 0));
	acu_sum.resize(L + 1, 0);
	
	int val;
	scanf("%d", &val);
	acu_sum[1] = val;
	for (int i = 2; i < L + 1; i++)
	{
		scanf("%d", &val);
		acu_sum[i] = acu_sum[i - 1] + val;
	}
	
	
	for (int i = 1; i < L + 1; i++)
	{
		dp[1][i] = cost(1, i);
	}

	for (int i = 2; i < G + 1; i++)
	{
		fill(i, 1, L, 1, L);
	}

	
	printf("%lld\n", dp[G][L]);
	

    return 0;
}
