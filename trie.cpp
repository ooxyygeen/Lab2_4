//
// Created by User on 30.04.2021.
//

#include "trie.h"

TrieNode::TrieNode() {
    endFlag = false;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word) {
    insert(root, word);
}

void Trie::insert(TrieNode *curNode, string word) {
    if (word.length() == 0)
        return;
    if (curNode == nullptr)
        curNode = new TrieNode();
    for (int i = 0; i < word.length(); i++) {
        if (curNode->map.find(word[i]) == curNode->map.end())
            curNode->map[word[i]] = new TrieNode(); // создаем, если отсутсвует
        curNode = curNode->map[word[i]]; // перемещаемся дальше
    }
    curNode->endFlag = true; // конце слова
}

void Trie::findByPrefix(string prefix) {
    if (prefix == "")
        return;
    findByPrefix(root, prefix);
}

void Trie::findSuffix(TrieNode* curNode, string prefix) {
    if (curNode->endFlag)   // добавляет слово в список
        output.push_back(prefix);

    unordered_map<char, TrieNode *>::iterator it = curNode->map.begin();

    while (it != curNode->map.end()) {
        prefix.push_back(it->first);    // записываем букву ячейки
        findSuffix(it->second, prefix); //  спускаемся ниже и повторяем действия
        prefix.erase(prefix.length() - 1);  //  убираем букву ячейки с 1 пункта
        it++;   // двигаемся "вправо" по ХТ
    }
}

void Trie::findByPrefix(TrieNode *curNode, string prefix) {
    if (root == nullptr) {
        output.emplace_back("No words in dictionary");
        return;
    }
    //  проходим префикс
    for (int i = 0; i < prefix.length(); ++i) {
        if (curNode->map[prefix[i]] == nullptr) // prefix absent
            return;
        curNode = curNode->map[prefix[i]];
    }
    //  ищем все продолжения
    findSuffix(curNode, prefix);

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << " ";
    }
}
