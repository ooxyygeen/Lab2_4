#include <iostream>
#include <ctime>
#include <fstream>
#include "data.h"
#include "binarySearchTree.h"
#include "test.h"
#include "trie.h"
using namespace std;

int main() {
    srand(time(nullptr));

//    testBinarySearchTree();

    /*Data p = Data('a', 16, 1, 100);
    Data q = Data('a', 8, 1, 100);
    Data k = Data('a', 24, 1, 100);
    Data g = Data('a', 4, 1, 100);
    Data h = Data('a', 12, 1, 100);
    Data l = Data('a', 20, 1, 100);
    Data m = Data('a', 28, 1, 100);

    BinarySearchTree b = BinarySearchTree();
    b.insert(p);
    b.insert(q);
    b.insert(k);
    b.insert(g);
    b.insert(h);
    b.insert(l);
    b.insert(m);
    b.print();
    b.eraseInRange(g, m);
    cout<<endl;
    b.print();*/

   Trie t = Trie();
    ifstream fin ("D:\\Code\\Labs\\ASD\\Lab2_4\\words_alpha.txt");
    if (!fin.is_open()) {
        cout << "Error";
        return -1;
    }
    string str;
    cout << "Enter word:" << endl;
    getline(cin, str);

    string str1;
    while (getline(fin, str1)) {
        t.insert(str1);
    }

    cout << "Output:" << endl;
    t.findByPrefix(str);

    fin.close();

    return 0;
}
