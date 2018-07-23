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

#define MAX 400000
using namespace std;

struct st{
	int v[9];

};


st  tree[MAX+1];
int lazy[MAX+1];

void build(int node, int start, int end) 
{

	if (start == end)
	{
		tree[node].v[1] = 1;
		return;
	}
	
	int mid = (start + end) / 2;
	build(2*node, start, mid);
	build(2*node + 1, mid + 1, end);
	for (int i = 0; i < 9; i++)
	{
		tree[node].v[i] = tree[node*2].v[i] + tree[node*2 + 1].v[i];
	}
}

void lazy_update(int node, int start, int end)
{
	if(lazy[node] != 0)
	{
		st new_vals;
		for (int i = 0; i < 9; i++)
		{
			new_vals.v[(i + lazy[node]) % 9] = tree[node].v[i];
		}
		tree[node] = new_vals;
		
		if(start != end)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
	
	lazy_update(node, start, end);
	
	if(start > end || start > r || end < l)
		return;
		
	if(start >= l && end <= r)
	{
		lazy[node] += val;
		lazy_update(node, start, end);
		return;
	}
	
	int mid = (start + end) / 2;
	updateRange(node*2, start, mid, l, r, val);
	updateRange(node*2 + 1, mid + 1, end, l, r, val);
	
	for (int i = 0; i < 9; i++)
	{
		tree[node].v[i] = tree[node*2].v[i] + tree[node*2 + 1].v[i];
	}
	
}

st queryRange(int node, int start, int end, int l, int r)
{
	
	st res;
	memset(res.v, 0, sizeof(res.v));

	if(start > end || start > r || end < l)
		return res;
	
	lazy_update(node, start, end);
	
	if(start >= l && end <= r)
	{
		return tree[node];
	}
	
	int mid = (start + end) / 2;
	
	st p1 = queryRange(node*2, start, mid, l, r);
	st p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
	
	for (int i = 0; i < 9; i++)
	{
		res.v[i] = p1.v[i] + p2.v[i];
	}
	
	return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int n, q;
	cin >> n >> q;
	
	memset(lazy, 0, sizeof(lazy));
	build(1, 0, n - 1);
	
	for (int i = 0; i < q; i++)
	{
		int beg, end;
		cin >> beg >> end;
		
		st query = queryRange(1, 0, n - 1, beg, end);
		
		int max_note = 0;
		int max_freq = 0;
		for (int i = 0; i < 9; i++)
		{
			if (query.v[i] >= max_freq)
			{
				max_note = i;
				max_freq = query.v[i];
			}
		}
		
		updateRange(1, 0, n-1, beg, end, max_note);	
		
	}
	
	for (int i = 0; i < n; i++)
	{
		st query = queryRange(1, 0, n-1, i, i);
		
		for (int j = 0; j < 9; j++)
		{
			if (query.v[j]) {
				printf("%d\n", j);
				break;
			}
		}
	}
	

    return 0;
}
