#define LEFT_NODE(i) i+i+1
#define RIGHT_NODE(i) i+i+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) mp(seg.first, MID(seg))
#define RIGHT_SEG(seg) mp(MID(seg) + 1, seg.second)

class SegTree{

private:

    vi max_tree;
    int sz;

    void build(int *vet, pii curr_seg, int node){

        if(curr_seg.first == curr_seg.second){
            max_tree[node] = vet[curr_seg.first];
            return;
        }

        build(vet, LEFT_SEG(curr_seg), LEFT_NODE(node));
        build(vet, RIGHT_SEG(curr_seg), RIGHT_NODE(node));

        max_tree[node] = max(max_tree[LEFT_NODE(node)], max_tree[RIGHT_NODE(node)]);
    }

    void update_aux(pii curr_seg, int index, int value, int node){

        if (curr_seg.first == curr_seg.second) {
            max_tree[node] = value;
            return;
        }

        if (index <= MID(curr_seg)) {
            update_aux(LEFT_SEG(curr_seg), index, value, LEFT_NODE(node));
        } else {
            update_aux(RIGHT_SEG(curr_seg), index, value, RIGHT_NODE(node));
        }

        max_tree[node] = max(max_tree[LEFT_NODE(node)], max_tree[RIGHT_NODE(node)]);
    }

    int query_aux(pii curr_seg, pii target_seg, int node){

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            return 0;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            return max_tree[node];
        }

        return max(query_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node))
               , query_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node)));
    }

public:

    SegTree(int *vet, int size){
        sz = size;
        max_tree.resize(4 * sz);
        build(vet, mp(0, sz - 1), 0);
    }

    int query(pii target_seg){
        return query_aux(mp(0, sz - 1), target_seg, 0);
    }

    void update(int index, int value) {
        update_aux(mp(0, sz - 1), index, value, 0);
    }
};
