#include <iostream>
#include <vector>

using namespace std;


class disjoint_set{
private:
    disjoint_set *parent;
    int data;
    int rank;

    disjoint_set& find_set_rec(disjoint_set &current_node){
        if(current_node.parent->get_data() == current_node.get_data()){
            return current_node;
        }

        current_node.parent = &find_set_rec(*current_node.parent);
        return *current_node.parent;
    }
public:

    disjoint_set(){
        parent = this;
        rank = 0;
    }

    void set_data(int data){
        this->data = data;
    }

    void merge_set(disjoint_set &other_set){
        if(data == other_set.data)
            return;

        disjoint_set &root = find_set();
        disjoint_set &other_root = other_set.find_set();

        if(other_root.rank > root.rank){
            root.parent = &other_root;
        }else{
            other_root.parent = &root;

            if(root.rank == other_root.rank){
                ++root.rank;
            }
        }
    }

    disjoint_set& find_set(){
        if(this->parent->data != this->data){
            this->parent = &find_set_rec(*this->parent);
            return *(this->parent);
        }else{
            return *(this);
        }

    }

    int get_data(){
        return data;
    }
};

int main() {
    int n_tests;
    ios::sync_with_stdio(false);

    cin >> n_tests;
    string s;
    getline(cin, s);
    getline(cin, s);



    for (int w = 0; w < n_tests; ++w) {
        int n_success = 0;
        int n_fail = 0;

        int n_computers;
        cin >> n_computers;

        vector<disjoint_set> vet_disjoint_nodes(n_computers);
        for (int i = 0; i < n_computers; ++i) {
            vet_disjoint_nodes[i].set_data(i+1);
        }

        char cmd;
        int computer_1, computer_2;
        bool is_on_test = true;

        while(is_on_test){
            cin >> cmd >> computer_1 >> computer_2;
            computer_1--;
            computer_2--;

            auto &node_1 = vet_disjoint_nodes[computer_1];
            auto &node_2 = vet_disjoint_nodes[computer_2];

            node_1.set_data(node_1.get_data());
            node_2.set_data(node_2.get_data());

            if(cmd == 'c'){
                node_1.merge_set(node_2);
            }else{
                auto root_1 = node_1.find_set();
                auto root_2 = node_2.find_set();

                if(root_1.get_data() == root_2.get_data()){
                    n_success++;
                }else{
                    n_fail++;
                }
            }

            char c1, c2;
            c1 = cin.get();
            if(cin.peek() == EOF){
                is_on_test = false;
            }
            c2 = cin.peek();

            if(c2 == '\n'){
                c2 = cin.get();
                is_on_test = false;
            }
        }

        cout << n_success << "," << n_fail << endl;
        if(w != n_tests-1)
            cout << endl;
    }
    return 0;
}