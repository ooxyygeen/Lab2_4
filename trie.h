//
// Created by User on 30.04.2021.
//

#ifndef LAB2_4_TRIE_H
#define LAB2_4_TRIE_H
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> map;
    bool endFlag;   //  0 - not end; 1 - end

    TrieNode();
};

struct Trie {
    TrieNode* root = nullptr;
    vector<string> output;
    Trie();

    void insert(string word);
    void insert(TrieNode* curNode, string word);

    void findSuffix(TrieNode* curNode, string pref);
    void findByPrefix(string prefix);
    void findByPrefix(TrieNode* curNode, string prefix);
};

#endif //LAB2_4_TRIE_H
