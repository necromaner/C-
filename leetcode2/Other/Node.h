//
// Created by necromaner on 2020/9/28.
//

#ifndef LEETCODE2_NODE_H
#define LEETCODE2_NODE_H

#include <string>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

Node *SetNode(string tree);//设置一个二叉树
string GetNode(Node *tree);//二叉树->string

#endif //LEETCODE2_NODE_H
