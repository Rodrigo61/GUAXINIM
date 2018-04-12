using namespace std;
bool debug = true;

//{<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

typedef pair<int,int> pii;
typedef vector<int> vi;


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
//</editor-fold desc="GUAXINIM TEMPLATE">
//}

#define LEFT_NODE(i) 2*i+1
#define RIGHT_NODE(i) 2*i+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) mp(seg.first, MID(seg))
#define RIGHT_SEG(seg) mp(MID(seg)+1, seg.second)
#define SEG_SZ(seg) seg.second-seg.first+1


class SegTree{
	
private:
	vi tree;
	vi lazy_tree;
	int sz;
	
	void lazy_update(pii curr_seg, int node){
		
		if(lazy_tree[node] != 0){
			deb("cs.first = ", curr_seg.first);
			deb("cs.second = ", curr_seg.second);
			deb("lazy_tree[node] = ", lazy_tree[node]);
			tree[node] += lazy_tree[node];
			
			if(curr_seg.first != curr_seg.second){
				lazy_tree[LEFT_NODE(node)] = SEG_SZ(LEFT_SEG(curr_seg));
				lazy_tree[RIGHT_NODE(node)] = SEG_SZ(RIGHT_SEG(curr_seg));
			}
			
			lazy_tree[node] = 0;
		}
		
	}
	
	void update_aux(pii curr_seg, pii target_seg, int node){
		deb("UPDATE: cs.first = ", curr_seg.first);
		deb("UPDATE: cs.second = ", curr_seg.second);
		lazy_update(curr_seg, node);
		
		if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
			return;
		}
		
		if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
		
			lazy_tree[node] = SEG_SZ(curr_seg);
			lazy_update(curr_seg, node);
			return;
		}
		
		update_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node));
		update_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));
		
		tree[node] = tree[LEFT_NODE(node)] +  tree[RIGHT_NODE(node)];
	}
	
	int value_aux(pii curr_seg, pii target_seg, int node){
		
		deb("VALUE cs.first = ", curr_seg.first);
		deb("VALUE cs.second = ", curr_seg.second);
		lazy_update(curr_seg, node);
		
		if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
			return 0;
		}
		
		if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
			deb("value T = ", tree[node]);
			return tree[node];
		}
		
		int b = value_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node))
			+  value_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));
			
		deb("value = ", b);
		return b;
	}
public:
	
	SegTree(int size){
		sz = size;
		tree.resize(4*sz, 0);
		lazy_tree.resize(4*sz, 0);
		deb("Novo");
	}
	
	void update(pii target_seg){
		deb("NEW UPDT");
		deb("sz = ", sz);
		update_aux(mp(0, sz-1), target_seg, 0);
		print_vector_debug(tree);
	}
	
	int value(pii target_seg){
		deb("t.first = ", target_seg.first);
		deb("t.second = ", target_seg.second);
		print_vector_debug(tree);
		return value_aux(mp(0, sz-1), target_seg, 0);
	}
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  
	int N, M;
	int n_query;
	int query_type;
	char range_type;
	int x,y;
	int size;
	
	cin >> N >> M >> n_query;
	
	
	vector<SegTree> rows_seg(N, SegTree(M));
	vector<SegTree> cols_seg(M, SegTree(N));
	
	for(int i = 0; i < n_query; ++i){
		
		
		
		cin >> query_type >> range_type >> x >> y >> size;
		--x,--y;
		
		deb("\n\n");
		deb("query_type = ", query_type, "rang = ", range_type);
		deb("x = ", x , "y = ", y);
		deb("size = ", size);
		
		if(query_type == 1){
			
			if(range_type == 'L'){
				if(rows_seg[x].value(mp(y, size-1)) == 0){
					rows_seg[x].update(mp(y, size-1));
					for(int j = 0; j < size; ++j){
						deb("unit upd");
						deb("y+j-1 = ", y+j);
						cols_seg[y+j].update(mp(x, x));
					}
				}else{
					cout << -1 << endl;
				}
			}else{
				
				if(cols_seg[y].value(mp(x, size-1)) == 0){
					cols_seg[y].update(mp(x, size-1));
					for(int j = 0; j < size; ++j){
						deb("unit upd");
						deb("size = ", size);
						deb("j = ", j);
						deb("x+j = ", x+j);
						rows_seg[x+j].update(mp(y, y));
					}
				}else{
					cout << -1 << endl;
				}
			}
			
		}else{
			
			if(range_type == 'L'){
				cout << rows_seg[x].value(mp(y, size-1)) << endl;
			}else{
				cout << cols_seg[y].value(mp(x, size-1)) << endl;
			}
		}
		
	
	}
   
    return 0;
}