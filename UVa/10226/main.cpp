#include <iostream>
#include <map>

using namespace std;

int main() {
    int n_cases;
    string tree_name;

    cin >> n_cases;

    getline(cin, tree_name);
    getline(cin, tree_name);

    for(int w = 0; w < n_cases; ++w){
        map<string, int> map_tree;
        int total_trees = 0;

        getline(cin, tree_name);
        while(tree_name != ""){
            ++map_tree[tree_name];
            if(!getline(cin, tree_name)){
                break;
            }
            ++total_trees;
        }

        for(auto it : map_tree){
            printf("%s %.4lf\n", it.first.c_str(), ((double)it.second/total_trees)*100);
        }

        if(w!= n_cases-1)
            printf("\n");


    }
    return 0;
}