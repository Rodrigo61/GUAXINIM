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

#define MAX 400001

ll tree[MAX+1], lazy[MAX+1];

void lazyPropagation(int node, int start, int end)
{
    if(lazy[node] != 0)
    { 
        tree[node] += lazy[node] * (end - start + 1);
        if(start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(int node, int start, int end, int l, int r, int val)
{

    lazyPropagation(node, start, end);

    if(start > end || start > r || end < l)
        return;

    if(start >= l && end <= r)
    {
        lazy[node] += ((ll)val);
        lazyPropagation(node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll queryRange(int node, int start, int end, int l, int r)
{
    if(start > end || start > r || end < l)
        return 0;

    lazyPropagation(node, start, end);

    if(start >= l && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r);

    return (p1 + p2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int T;
	
	scanf("%d", &T);
	
	while (T--) 
	{
		int N, C;
		scanf("%d %d", &N, &C);
		
		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));
		
		//~ printf("N = %d  C = %d\n", N, C);
		int cmd, arg1, arg2, arg3;
		for (int i = 0; i < C; i++)
		{
			scanf("%d", &cmd);
			
			if (cmd == 0)
			{
				scanf("%d%d%d", &arg1, &arg2, &arg3);
				//~ printf("a = %d  b = %d  val = %d\n", arg1, arg2, arg3);
				updateRange(1, 0, N - 1, arg1 - 1, arg2 - 1, arg3);
				
			} else {
				
				scanf("%d%d", &arg1, &arg2);
				//~ printf("a = %d  b = %d\n", arg1, arg2);
				printf("%lld\n", queryRange(1, 0, N - 1, arg1 - 1, arg2 - 1));
			}
		}
		
	}

    return 0;
}
