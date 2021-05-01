//
// Created by User on 28.04.2021.
//

#ifndef LAB2_4_BINARYSEARCHTREE_H
#define LAB2_4_BINARYSEARCHTREE_H

#include "data.h"
#include <iostream>
struct Node{
    Data data;
    Node* left ;
    Node* right;

    Node(const Data &aData);
};

struct Pair{
    Node* leftRoot;
    Node* rightRoot;

    Pair(Node* l, Node* r);
};

struct BinarySearchTree{
    Node* root;

    int realSize = 0;

    BinarySearchTree();
    ~BinarySearchTree();

    void deleteTree(Node* curNode);

    void insert(Data data);  //  public
    Node* insert(Node* curNode, Data data);  //  private

    bool find(Data data);
    Node* find(Node* curRoot, Data aData);

    Node* minimum(Node* curRoot);

    void erase(Data data);
    Node* erase(Node* curRoot, Data aData);

    int size();
    int size(Node* curNode);

    void print();
    void print(Node* curNode);

    int findInRange(Data minObject, Data maxObject);
    void findInRange(Data minObject, Data maxObject, Node* curNode, int& count);

    int height();
    int height(Node* curNode);

    Pair split(Node* curNode, Data object);

    Node* merge(Node* leftRoot, Node* rightRoot);

    void eraseInRange(Data minObject, Data maxObject);
    Node* eraseInRange(Data minObject, Data maxObject, Node* curNode);
};

#endif //LAB2_4_BINARYSEARCHTREE_H
