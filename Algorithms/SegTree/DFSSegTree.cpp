
vector<vi> vet_adj;

vector<pii> dict_id_to_range;
int dfs_curr_time;
vi tree_on_vector;
vi original_tree;

void dfs(int node) {

    tree_on_vector.push_back(original_tree[node]);
    ++dfs_curr_time;
    dict_id_to_range[node].first = dfs_curr_time;
    for (auto &v : vet_adj[node]) {
        dfs(v);
    }
    dict_id_to_range[node].second = dfs_curr_time;

}

void create_dict_id_to_range() {

    dfs_curr_time = -1;
    dfs(0);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int sz, query_count;
    cin >> sz >> query_count;

    original_tree.clear();
    original_tree.resize(sz);

    vet_adj.clear();
    vet_adj.resize(sz);

    tree_on_vector.clear();

    dict_id_to_range.clear();
    dict_id_to_range.resize(sz);

    /*
        Read/ Create original tree
    */

    create_dict_id_to_range();


    /*
        Create SegTree using tree_on_vector vector
    */

    /*
        Read/process Querys
    */
    // USAGE:
    sgtree.update(dict_id_to_range[id]);
    sgtree.query(dict_id_to_range[id])



    return 0;
}
