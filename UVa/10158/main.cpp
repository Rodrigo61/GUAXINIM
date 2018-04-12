#include <iostream>

using namespace std;
bool debug = false;

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

using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)

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

/*
 * A ideia desse problema é que é possivel manter uma estrutura UnionFind para as amizades.
 * Ao inves de manter uma UF para os inimigos também, nós utilizamos a UF de amizades e o seu representante
 * como a UF de inimigos.
 * */

class Node{
public:
    int parent;
    int rank;
};

class UnionFind{

    vector<Node> love_nodes;
    vector<int> enim_rep;

public:

    UnionFind(int n_people){
        love_nodes.resize(n_people);
        enim_rep.resize(n_people);

        for (int i = 0; i < n_people; ++i) {
            love_nodes[i].parent = i;
            love_nodes[i].rank = 0;
            enim_rep[i] = -1;
        }
    }

    int areEnimies(int p1, int p2){

        int rep1 = find_set_love(p1);
        int rep2 = find_set_love(p2);

        if(enim_rep[rep1] == -1 || enim_rep[rep2] == -1){
            return false;
        }else if(areFriends(enim_rep[rep1], rep2) || areFriends(enim_rep[rep2], rep1)){
            return true;
        }else{
            return false;
        }

    }

    int areFriends(int p1, int p2){

        int rep1 = find_set_love(p1);
        int rep2 = find_set_love(p2);

        if(rep1 == rep2){
            return true;
        }

        if(enim_rep[rep1] != -1 && enim_rep[rep1] == enim_rep[rep2]){
            /* Path compression */
            setFriends(enim_rep[rep1], enim_rep[rep2]);
            enim_rep[rep1] = find_set_love(enim_rep[rep1]);
            enim_rep[rep2] = find_set_love(enim_rep[rep2]);
            return true;
        }

        return false;
    }

    void setFriends(int p1, int p2){

        if(areEnimies(p1, p2)){
            cout << "-1" << endl;
            return;
        }

        int rep1 = find_set_love(p1);
        int rep2 = find_set_love(p2);

        if(rep1 != rep2){
            union_by_rank_love(rep1, rep2);
        }

        if(enim_rep[rep1] != -1 && enim_rep[rep2] != -1){
            if(enim_rep[rep1] != enim_rep[rep2]){
                setFriends(enim_rep[rep1], enim_rep[rep2]);
                enim_rep[rep1] = find_set_love(enim_rep[rep1]);
                enim_rep[rep2] = find_set_love(enim_rep[rep2]);
            }
        }else if(enim_rep[rep1] != -1 || enim_rep[rep2] != -1){
            if(enim_rep[rep1] == -1){
                enim_rep[rep1] = find_set_love(enim_rep[rep2]);
            }else{
                enim_rep[rep2] = find_set_love(enim_rep[rep1]);
            }
        }

    }


    void setEnimies(int p1, int p2){

        if(!areFriends(p1, p2)){
            int rep1 = find_set_love(p1);
            int rep2 = find_set_love(p2);

            if(enim_rep[rep1] != -1){
                setFriends(enim_rep[rep1], rep2);
                enim_rep[rep1] = find_set_love(enim_rep[rep1]);
            }else{
                enim_rep[rep1] = find_set_love(rep2);
            }

            if(enim_rep[rep2] != -1){
                setFriends(enim_rep[rep2], rep1);
                enim_rep[rep2] = find_set_love(enim_rep[rep2]);
            }else{
                enim_rep[rep2] = find_set_love(rep1);
            }

        }else{
            cout << "-1" << endl;
        }
    }


    int find_set_love(int p){

        Node &curr_node = love_nodes[p];

        if(curr_node.parent == p){
            /* É o representante */
            return p;
        }

        curr_node.parent = find_set_love(curr_node.parent); // path compress
        return curr_node.parent;
    }


    void union_by_rank_love(int rep1, int rep2){

        Node &node1 = love_nodes[rep1];
        Node &node2 = love_nodes[rep2];

        if(node1.rank > node2.rank){
            node2.parent = rep1;
        }else if(node2.rank > node1.rank){
            node1.parent = rep2;
        }else{
            node2.parent = rep1;
            node1.rank++;
        }
    }


};


int main(){
    ios_base::sync_with_stdio(false);

    int n_people;
    int cmd;
    int p1, p2;


    cin >> n_people;

    UnionFind uf(n_people);

    cin >> cmd >> p1 >> p2;
    while(cmd != 0){

        switch(cmd){
            case 1:{
                uf.setFriends(p1,p2);
                break;
            }
            case 2:{
                uf.setEnimies(p1,p2);
                break;
            }
            case 3:{
                cout << uf.areFriends(p1,p2) << endl;
                break;
            }
            case 4:{
                cout << uf.areEnimies(p1,p2) << endl;
                break;
            }
        }

        cin >> cmd >> p1 >> p2;
    }


    return 0;

}