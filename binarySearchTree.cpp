//
// Created by User on 28.04.2021.
//

#include "binarySearchTree.h"

using namespace std;
Node::Node(const Data &aData) {
    data = aData;
    left = nullptr;
    right = nullptr;
}

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

void BinarySearchTree::deleteTree(Node* curNode) {
    if (curNode != nullptr) {
        deleteTree(curNode->left);
        deleteTree(curNode->right);
        delete curNode;
    }
}

void BinarySearchTree::insert(Data aData) {
    root = insert(root, aData);
}

Node *BinarySearchTree::insert(Node *curNode, Data aData) {
    if (curNode == nullptr) {
//        realSize++;
        return new Node(aData);
    }
    else if (aData < curNode->data) {
        curNode->left = insert(curNode->left, aData);
    }
    else if (curNode->data < aData) {
        curNode->right = insert(curNode->right, aData);
    }
    return curNode;
}

bool BinarySearchTree::find(Data aData) {
    Node* x = find(root, aData);
    if (x == nullptr)
        return false;
    return true;
}

Node *BinarySearchTree::find(Node* curNode, Data aData) {
    if (curNode == nullptr || curNode->data == aData)
        return curNode;
    if (aData < curNode->data)
        return find(curNode->left, aData);
    return find(curNode->right, aData);
}

Node *BinarySearchTree::minimum(Node *curNode) {
    if (curNode->left == nullptr)
        return curNode;
    return minimum(curNode->left);
}

void BinarySearchTree::erase(Data aData) {
    root = erase(root, aData);
}

Node *BinarySearchTree::erase(Node *curNode, Data aData) {
    if (curNode == nullptr)
        return curNode;
    if (aData < curNode->data)
        curNode->left = erase(curNode->left, aData);
    else if (curNode->data < aData)
        curNode->right = erase(curNode->right, aData);
    else if (curNode->left != nullptr && curNode->right != nullptr) {
        curNode->data = minimum(curNode->right)->data;
        curNode->right = erase(curNode->right, curNode->data);
    } else {
        if (curNode->left != nullptr) {
            Node* temp = curNode->left;
            delete curNode;
            curNode = temp;
        }
        else if (curNode->right != nullptr) {
            Node* temp = curNode->right;
            delete curNode;
            curNode = temp;
        }
        else {
            delete curNode;
            curNode = nullptr;
        }
//        realSize--;
    }
    return curNode;
}

int BinarySearchTree::size() {
//    return realSize;
    return size(root);
}

int BinarySearchTree::size(Node* curNode) {
    if (curNode == nullptr)
        return 0;
    return (size(curNode->left) + 1 + size(curNode->right));
}

void BinarySearchTree::print() {
    print(root);
}

void BinarySearchTree::print(Node *curNode) {
    if (root == nullptr)
        cout << "BST is empty" << endl;
    if (curNode != nullptr) {
        print(curNode->left);
        cout << curNode->data.nickname << " " << curNode->data.experience 
        << " " << curNode->data.rank << " " << curNode->data.donation << endl;
        print(curNode->right);
    }
}

void inorderTraversal(Node* curNode, int &counter) {
    if (curNode != nullptr) {
        inorderTraversal(curNode->left, counter);
        counter++;
        inorderTraversal(curNode->right, counter);
    }
}

int BinarySearchTree::findInRange(Data minObject, Data maxObject) {
    int counter = 0;
    findInRange(minObject, maxObject, root, counter);
    return counter;
}

void BinarySearchTree::findInRange(Data minObject, Data maxObject, Node* curNode, int &counter) {
    if (curNode == nullptr)
        return;

    Pair pairMin = split(curNode, minObject);
    Pair pairMax = split(pairMin.rightRoot, maxObject);

    if (pairMax.rightRoot != nullptr && minimum(pairMax.rightRoot)->data == maxObject){
            counter = size(pairMax.leftRoot) + 1;
        }
    else { counter = size(pairMax.leftRoot); }

    pairMin.rightRoot = merge(pairMax.leftRoot, pairMax.rightRoot);
    root = merge(pairMin.leftRoot, pairMin.rightRoot);
}

int BinarySearchTree::height() {
    return height(root);
}

int BinarySearchTree::height(Node *curNode) {
    if (curNode == nullptr)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = height(curNode->left);
        int rDepth = height(curNode->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

Pair::Pair(Node *l, Node* r) {
    leftRoot = l;
    rightRoot = r;
}

Pair BinarySearchTree::split(Node *curNode, Data object) {
    if (curNode == nullptr)
        return Pair(nullptr, nullptr);
    else if (curNode->data < object) {
        Pair pair = split(curNode->right, object);
        curNode->right = pair.leftRoot;
        return Pair(curNode, pair.rightRoot);
    }
    else {
        Pair pair = split(curNode->left, object);
        curNode->left = pair.rightRoot;
        return Pair(pair.leftRoot, curNode);
    }
}

Node *BinarySearchTree::merge(Node* leftRoot, Node* rightRoot) {
    if (rightRoot == nullptr)
        return leftRoot;
    if (leftRoot == nullptr)
        return rightRoot;

    Node* newRoot = nullptr;
    newRoot = insert(newRoot, minimum(rightRoot)->data);
    newRoot->left = leftRoot;
    newRoot->right = rightRoot;
    newRoot->right = erase(rightRoot, minimum(rightRoot)->data);

    return newRoot;
}

void BinarySearchTree::eraseInRange(Data minObject, Data maxObject) {
    root = eraseInRange(minObject, maxObject, root);
}

Node *BinarySearchTree::eraseInRange(Data minObject, Data maxObject, Node *curNode) {
    if (curNode == nullptr)
        return curNode;
    Pair pairMin = split(curNode, minObject);
    Pair pairMax = split(pairMin.rightRoot, maxObject);
    if (pairMax.rightRoot != nullptr && minimum(pairMax.rightRoot)->data == maxObject){
        pairMax.rightRoot = erase(pairMax.rightRoot, minimum(pairMax.rightRoot)->data);
    }
    deleteTree(pairMax.leftRoot);
    return merge(pairMin.leftRoot, pairMax.rightRoot);
}



