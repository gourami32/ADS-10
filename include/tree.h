// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <algorithm>

class Tree {
 private:
    struct Node {
    std::vector<Tree*> children;
    char child;
    };
    Node* childs;
    explicit Tree(char child) {
        childs = new Node;
        childs->child = child;
    }
    void create(const std::vector<char>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            std::vector<char> temp = vec;
            childs->children.push_back(new Tree(temp[i]));
            temp.erase(temp.begin() + i);
            childs->children[i]->create(temp);
        }
    }

 public:
    explicit Tree(const std::vector<char>& vec) {
        childs = new Node;
        childs->child = '*';
        create(vec);
    }
    int getSize() const {
        return childs->children.size();
    }
    char getCh() const {
        return childs->child;
    }
    Tree& operator[](int n) const {
        return *childs->children[n];
    }
};
#endif  // INCLUDE_TREE_H_
