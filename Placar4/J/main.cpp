using namespace std;
bool debug = false;
#include<fstream>

//<editor-fold desc="GUAXINIM TEMPLATE">
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
#include <unordered_map>

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

//</editor-fold>




int curr_id = 1;
const int ALPHABET_SIZE = 128;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int id = -1;
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string &key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i];
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->id = curr_id++;
    deb("curr_id = ", curr_id);
}

// Returns true if key presents in trie, else
// false
int search(struct TrieNode *root, string &key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i];
        if (!pCrawl->children[index])
            return -1;

        pCrawl = pCrawl->children[index];
    }

    if(pCrawl != NULL && pCrawl->isEndOfWord){
        return pCrawl->id;
    }else{
        return -1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    ifstream rf;
    rf.open("input.txt");

    ofstream wf;
    wf.open("output.txt");

    int N;
    rf >> N;

    struct TrieNode *root = getNode();
    map<int, vector<int> > map_set;
    string results = "";

    for (size_t i = 0; i < N; i++) {
        int K;
        rf >> K;
        vector<string> key_values;

        for (size_t j = 0; j < K; j++) {
            rf >> key_values[j];
            // int id = search(root, str);
            // if(search(root, str) == -1){
            //     insert(root, str);
            //     id = curr_id - 1;
            // }
            // map_set[id].push_back(i);
        }
    }

    vi set_vazio = {};
    map_set[0] = set_vazio;

    for(auto &pv : map_set){
        sort(all(pv.second));
    }

    int M;
    rf >> M;
    for (size_t i = 0; i < M; i++) {
        int L;
        rf >> L;

        int result = 0;
        vector< vi* > vet_set(L);

        for (size_t j = 0; j < L; j++) {
            rf >> str;
            int id = search(root, str);
            if(id < 0)id =0;
            vet_set[j] = &map_set[id];
        }

        for(auto &elem : *vet_set[0]){
            bool is_ans = true;
            for(int k = 1; k < L; ++k){
                if(!binary_search(vet_set[k]->begin(),vet_set[k]->end() , elem)){
                    is_ans = false;
                }
            }

            if(is_ans){
                result++;
            }
        }

        results += to_string(result);
        results += "\n";
    }

    results.erase(results.size()-1, 1);
    wf << results << endl;
    wf.close();
    rf.close();
    return 0;
}
