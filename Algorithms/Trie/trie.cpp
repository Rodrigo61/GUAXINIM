#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bits/stdc++.h"

using namespace std;

#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'a')


struct TrieNode {
    bool end_word;
    TrieNode *children[ALPHABET_SIZE];

    TrieNode() {
        this->end_word = false;

        for(int i = 0; i < ALPHABET_SIZE; i++) {
            this->children[i] = nullptr;
        }
    }

    bool empty() {

        for(int i = 0; i < ALPHABET_SIZE; i++) {
            if (this->children[i]) {
                return false;
            }
        }

        return true;
    }

};


class Trie{
    TrieNode *root;
    int count;

private:

    bool delete_aux(TrieNode *curr_node, const string &key, int level) {

        // Base case
        if (level == key.size()) {

            if (curr_node->end_word) { // Verifica se achou a chave

                curr_node->end_word = false;

                // Se o nó é vazio, podemos/devemos apaga-lo
                if (curr_node->empty()) {
                    return true;
                }

                return false;
            }
        } else {
            int index = INDEX(key[level]);

            if (delete_aux(curr_node->children[index], key, level + 1)) {

                // Se o proximo nó foi marcado para ser apagado, nos apagamos
                delete curr_node->children[index];
                curr_node->children[index] = nullptr;

                // Verificamos se o no atual deve ser apagado e propagamos
                return !curr_node->end_word && curr_node->empty();
            }
        }

    return false;
}

public:
    Trie() {
        this->root = new TrieNode;
        this->count = 0;
    }

    void insert(const string &key) {

        int length = key.size();
        TrieNode *curr_node;

        this->count++;
        curr_node = this->root;

        for(int level = 0; level < length; level++) {
            int index = INDEX(key[level]);

            if (curr_node->children[index]) {
                // Ja existe no para esse prefixo
                curr_node = curr_node->children[index];
            } else {
                // Criamos um no novo para esse prefixo e continuamos nele
                curr_node->children[index] = new TrieNode;
                curr_node = curr_node->children[index];
            }
        }

        // O ultimo no é marcado como fim de palavra
        curr_node->end_word = true;
    }

    bool search(const string &key) {

        int length = key.size();
        TrieNode *curr_node;

        curr_node = this->root;

        for(int level = 0; level < length; level++) {
            int index = INDEX(key[level]);

            if (curr_node->children[index]) {
                curr_node = curr_node->children[index];
            } else {
                return false;
            }
        }

        return curr_node->end_word;
    }

    void delete_key(const string &key) {
        if( key.size() > 0 ) {
            delete_aux(this->root, key, 0);
        }
    }

};


int main()
{

    vector<string> keys = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    Trie trie;

    for (auto &s : keys) {
        trie.insert(s);
    }

    for (auto &s : keys) {
        printf("%s %s\n", s.c_str(), trie.search(s) ? "Present in trie" : "Not present in trie");
    }

    return 0;
}
