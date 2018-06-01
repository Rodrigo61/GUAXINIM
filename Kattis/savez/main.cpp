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

#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'A')
#define ALPHA(i) (char)(i + 'A')

void prefix_sufix_leghts(const string &str, int idx, int len, vi &lps) {

    if (idx == 0) {
        lps[0] = 0;
        return;
    }

    if (idx == str.size()) {
        return ;
    }

    if (str[idx] == str[len]) {
        len++;
        lps[idx] = len;
        prefix_sufix_leghts(str, idx + 1, len, lps);
        return;
    }

    if (len != 0) {
        len = lps[len - 1];
        prefix_sufix_leghts(str, idx, len, lps);
        return;
    }

    lps[idx] = 0;
    prefix_sufix_leghts(str, idx + 1, len, lps);

}

struct TrieNode {
    bool end_word;
    int repeated; // Qtas vezes a palavra foi adiciona da Trie. perceba que end_word = 0 <-> repeated = 0
    int dp_value;
    TrieNode *children[ALPHABET_SIZE];

    TrieNode() {
        this->end_word = false;
        this->repeated = 0;
        this->dp_value = 0;

        for(int i = 0; i < ALPHABET_SIZE; i++) {
            this->children[i] = nullptr;
        }
    }

};


class Trie{
    TrieNode *root;
    int max_value;

    void insert_aux(const string &key, TrieNode *curr_node, int level, vi &lps, string &prefix, vi &dp) {

        int length = key.size();
        dp.pb(curr_node->dp_value);
        lps.pb(0);
        prefix.pb(key[level]);

        deb("prefix = ", prefix);
        deb("level = ", level);

        if (level == length - 1) {
            // O ultimo no é marcado como fim de palavra
            curr_node->end_word = true;
            deb("repeated = ", key);
            deb("curr_node->repeated = ", curr_node->repeated);
            ++curr_node->repeated;
            deb("curr_node->repeated after = ", curr_node->repeated);

            if (level != 0) {
                prefix_sufix_leghts(prefix, level, lps[level - 1], lps);

                if (level >= lps.size() || level < 0 || lps[level] < 0 || level >= dp.size()) {
                    deb("DEU RUIIIIIIIIIIIIIM");
                    return;
                }

                if (lps[level] != 0) {
                    dp[level] = dp[lps[level] - 1] + curr_node->repeated;
                } else {
                    dp[level] = curr_node->repeated;
                }

                max_value = max(max_value, dp[level]);
            } else {
                dp[0] = curr_node->repeated;
                max_value = max(max_value, dp[0]);
            }
        }

        deb("DP:");
        print_vector_debug(dp);
        deb("LPS:");
        print_vector_debug(lps);

        if (level < length - 1) {
            int index = INDEX(key[level + 1]);

            if (curr_node->children[index]) {
                // Ja existe no para esse prefixo
                curr_node = curr_node->children[index];
            } else {
                // Criamos um no novo para esse prefixo e continuamos nele
                curr_node->children[index] = new TrieNode;
                curr_node = curr_node->children[index];
            }

            insert_aux(key, curr_node, level + 1, lps, prefix, dp);
        }
    }

public:
    Trie() {
        this->root = new TrieNode;
        max_value = 0;
    }

    void insert(const string &key) {
        vi lps;
        vi dp;
        string prefix;

        TrieNode * curr_node = this->root;
        int index = INDEX(key[0]);

        if (curr_node->children[index]) {
            // Ja existe no para esse prefixo
            curr_node = curr_node->children[index];
        } else {
            // Criamos um no novo para esse prefixo e continuamos nele
            curr_node->children[index] = new TrieNode;
            curr_node = curr_node->children[index];
        }

        insert_aux(key, curr_node, 0, lps, prefix, dp);
    }

    void complete_search(TrieNode *curr_node, int level, vi &lps, string &prefix, vi &dp) {

        dp.pb(0);
        lps.pb(0);


        for (int i= 0; i < ALPHABET_SIZE; ++i) {
            if (curr_node->children[i]) {

                prefix.pb(ALPHA(i));
                deb("prefix = ", prefix);


                deb("level = ", level);

                if (level != 0) {
                    deb("calc lps");
                    prefix_sufix_leghts(prefix, level, lps[level - 1], lps);
                    dp[level] = dp[lps[level] - 1] + curr_node->children[i]->repeated;
                    max_value = max(max_value, dp[level]);
                } else {
                    dp[0] = curr_node->children[i]->repeated;
                    max_value = max(max_value, dp[0]);
                }

                deb("DP:");
                print_vector_debug(dp);
                deb("LPS:");
                print_vector_debug(lps);

                complete_search(curr_node->children[i], level + 1, lps,  prefix, dp);

                prefix.pop_back();
            }
        }

        dp.pop_back();
        lps.pop_back();


    }

    int solve() {
        return max_value;
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //
    // string str1 = "ABA";
    // vi lps1(str1.size(), 0);
    // lps1[0] = 0;
    // prefix_sufix_leghts(str1, 1, 0, lps1);
    // print_vector_debug(lps1);
    //
    // str1 += 'B';
    // lps1.pb(-1);
    // prefix_sufix_leghts(str1, str1.size() - 1, lps1[str1.size() - 2], lps1);
    // print_vector_debug(lps1);

    int n_words;
    cin >> n_words;

    Trie trie;
    for (size_t i = 0; i < n_words; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    printf("%d\n", trie.solve());

    return 0;
}
