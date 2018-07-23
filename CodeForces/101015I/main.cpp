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

#define INF 99999999999999999

int N, K;
vi values;
vector<vll> cost;
vector<vll> dp;

void precalc_costs()
{
	ll acu_sum[N];
	cost.resize(N, vll(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			
			cost[i][j] = INF;
			
			ll cost_left = 0;
			ll cost_right = 0;
			
			memset(acu_sum, 0, sizeof(acu_sum));
			acu_sum[i] = values[i];
			
			for (int k = i + 1; k <= j; k++)
			{
				acu_sum[k] = acu_sum[k - 1] + values[k];
			}
			
			for (int k = i; k < j ; k++)
			{
				cost_left += acu_sum[k];
			}
			
			ll acu_right = 0;
			for (int k = j; k > i; k--)
			{
				cost[i][j] = min(cost[i][j], cost_left + cost_right);
				
				acu_right += values[k];
				cost_right += acu_right;
				
				cost_left -= acu_sum[k - 1];
			}
			cost[i][j] = min(cost[i][j], cost_left + cost_right);
			
		}
	}
}

ll get_cost(int i, int j) 
{
	if (i >= j) 
		return 0;
		
	return cost[i][j];
}

void fill(int g, int l1, int l2, int p1, int p2)
{
	int lm, k;
	
	if (l1 > l2)
		return;
	
	lm = (l1+l2)/2;
	
	int min_k = -1;
	dp[g][lm] = INF;
	
	for (k = p1; k <= p2; k++)
	{
		ll new_cost = dp[g-1][k] + get_cost(k+1, lm);
		if (dp[g][lm] > new_cost)
		{
			dp[g][lm] = new_cost;
			min_k = k;
		}
	}
	
	fill(g, l1, lm-1, p1, min_k);
	fill(g, lm+1, l2, min_k, p2);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


	scanf("%d%d", &N, &K);
	
	values.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &values[i]);
	}
	
	precalc_costs();
	
	dp.resize(K + 1, vll(N, INF));
	
	for (int i = 0; i < N; i++)
	{
		dp[1][i] = cost[0][i];
	}
	
	for (int k = 2; k < K + 1; k++)
	{
		fill(k, 0, N - 1, 0, N - 1); // otimizacao desnecessária, só pra estudo
	}
	
	// DP sem otimizacao, mas recebe AC
	//~ for (int k = 2; k < K + 1; k++)
	//~ {
		//~ for (int i = 1; i < N; i++)
		//~ {
			//~ for (int l = 0; l <= i; l++) 
			//~ {
				//~ if (l == 0) 
				//~ {
					//~ dp[k][i] = min(dp[k][i], cost[0][i]);
				//~ }
				//~ else
				//~ {
					//~ dp[k][i] = min(dp[k][i], cost[l][i] + dp[k - 1][l - 1]);
				//~ }
			//~ }
		//~ }
	//~ }
	
	
	printf("%lld\n", dp[K][N - 1]);
	

    return 0;
}
