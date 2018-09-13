#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

struct Point{
	int x, y;
};

struct Retangulo{
	
	int left_x, right_x, upper_y, lower_y;
	int id;
	
	Retangulo(){}
	void set(int x1, int y1, int x2, int y2, int id)
	{
		left_x = min(x1, x2);
		right_x = max(x1, x2);
		upper_y = max(y1, y2);
		lower_y = min(y1, y2);
		this->id = id;
	}
};


#define LEFT_NODE(node) 2*node+1
#define RIGHT_NODE(node) 2*node+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) make_pair(seg.first, MID(seg))
#define RIGHT_SEG(seg) make_pair(MID(seg) + 1, seg.second)

class SegTree{
private:

    vector<long long int> tree;
    vector<long long int> lazy_tree;
    int sz;

    void lazy_update(pii curr_seg, int node){

        if(lazy_tree[node] != 0){

            int seg_sz = curr_seg.second - curr_seg.first + 1;
            long long int value = lazy_tree[node];

            if(curr_seg.first != curr_seg.second){
                /* Propagate, not a leaf */
                tree[node] = seg_sz;
                lazy_tree[LEFT_NODE(node)] += value;
                lazy_tree[RIGHT_NODE(node)] += value;
            }
            else
			{
				tree[node] += value;
			}

            lazy_tree[node] = 0;
        }
    }


    void update_aux(pii curr_seg, pii target_seg, long long int value, int node){

        lazy_update(curr_seg, node);

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            return;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            /* Within */
            lazy_tree[node] = value;
            lazy_update(curr_seg, node);
            return;
        }

        /*Overlap*/
        update_aux(LEFT_SEG(curr_seg), target_seg, value, LEFT_NODE(node));
        update_aux(RIGHT_SEG(curr_seg), target_seg, value, RIGHT_NODE(node));

        tree[node] = tree[LEFT_NODE(node)] + tree[RIGHT_NODE(node)];

    }

    long long int value_aux(pii curr_seg, pii target_seg, int node){

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            return 0;
        }

        lazy_update(curr_seg, node);

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            /* Within */
            return tree[node] != 0;
        }

        return value_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node))
                + value_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));

    }

public:

    SegTree(int size){
        sz = size;
        tree.resize(4*sz, 0);
        lazy_tree.resize(4*sz, 0);
    }

    void update(pii target_seg, long long int value){
        update_aux(make_pair(0, sz-1), target_seg, value, 0);
    }

    long long int value(pii target_seg){
        return value_aux(make_pair(0, sz - 1), target_seg, 0);
    }
};


int main() 
{
	int N;
	vector<Retangulo> vet_ret;
	vii X_vals;

	scanf("%d", &N);
	int x1, y1, x2, y2;
	
	vet_ret.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		vet_ret[i].set(x1, y1, x2, y2, i);
		X_vals.push_back({x1, -i});
		X_vals.push_back({x2, i});
	}
	
	sort(all(X_vals));
	int last_x = X_vals[0].first;
	ll acu_area = 0;
	SegTree st(30000);
	for (int i = 0; i < (int)X_vals.size(); i++)
	{
		
		int x = X_vals[i].first;
		int type = X_vals[i].second;
		int id = abs(X_vals[i].second);
		
		db(x);
		db(last_x);
		int total_y = st.value({0, 30000});
		db(total_y);
		int delta_x = x - last_x;
		acu_area += total_y * delta_x;
		last_x = x;
		db(type);
		
		if (type < 0)
		{
			db(vet_ret[id].lower_y);
			db(vet_ret[id].upper_y);
			st.update({vet_ret[id].lower_y, vet_ret[id].upper_y}, 1);
		} else
		{
			st.update({vet_ret[id].lower_y, vet_ret[id].upper_y}, -1);
		}
	}
	
	printf("%lld\n", acu_area);
	
	return 0;
}
