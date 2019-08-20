
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

            tree[node] += seg_sz*value;

            if(curr_seg.first != curr_seg.second){
                /* Propagate, not a leaf */
                lazy_tree[LEFT_NODE(node)] += value;
                lazy_tree[RIGHT_NODE(node)] += value;
            }

            lazy_tree[node] = 0;
        }
    }


    void update_aux(pii curr_seg, pii target_seg, long long int value, int node){

        lazy_update(curr_seg, node); // Não mova de lugar

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
            return tree[node];
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

