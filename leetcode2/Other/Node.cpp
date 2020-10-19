//
// Created by necromaner on 2020/9/28.
//
#include <vector>
#include <iostream>
#include "Node.h"
vector<string> split1(const string& str, const string& pattern) {
    vector<string> ret;
    if (pattern.empty()) return ret;
    size_t start = 0, index = str.find_first_of(pattern, 0);
    while (index != str.npos) {
        if (start != index)
            ret.push_back(str.substr(start, index - start));
        start = index + 1;
        index = str.find_first_of(pattern, start);
    }
    if (!str.substr(start).empty())
        ret.push_back(str.substr(start));
    return ret;
}
void GetNode1(int high, Node *node, vector<Node *> &treeHigh) {
    if (!node)
        return;
    if (treeHigh.size() < high + 1) {//新一行
        treeHigh.push_back(node);
    }
    if (node->left)//存在左节点
        GetNode1(high + 1, node->left, treeHigh);
    if (node->right)//存在右节点
        GetNode1(high + 1, node->right, treeHigh);
}

Node *SetNode(string tree) {
    if (tree.at(0) == '[')
        tree.erase(0, 1);
    if (tree.at(tree.size() - 1) == ']')
        tree.pop_back();
    vector<string> aa;
    aa = split1(tree, ",");

    vector<vector<Node *>> treeVector;
    int treeHigh = 0;//树高
    int sizeHead = 0;//起始位置
    int sizesize = 0;//有效长度
    int sizeEnd = aa.size();
    while (sizeHead < sizeEnd) {
        int size = sizeHead;
        if (sizesize == 0)
            size += 1;
        else
            size += sizesize * 2;
        if (size > sizeEnd)
            size = sizeEnd;
        sizesize = 0;
        for (int i = sizeHead; i < size; ++i) {
            if (treeVector.size() < treeHigh + 1) {
                vector<Node *> bb;
                if (aa[i] != "null") {
                    Node *tree = new Node(atof(aa[i].c_str()));
                    bb.push_back(tree);
                } else
                    bb.push_back(nullptr);
                treeVector.push_back(bb);
            } else {
                if (aa[i] != "null") {
                    Node *tree = new Node(atof(aa[i].c_str()));
                    treeVector[treeHigh].push_back(tree);
                } else
                    treeVector[treeHigh].push_back(nullptr);
            }
            if (aa[i] != "null")
                sizesize++;
        }
        if (sizesize == 0) {
            cout << "error1" << endl;
            break;
        }
        sizeHead = size;
        treeHigh++;
    }
    for (int j = 0; j < treeVector.size() - 1; ++j) {
        int num = 0;
        for (int i = 0; i < treeVector[j].size(); ++i) {
            if (treeVector[j][i] == nullptr)
                continue;
            int nextSize = treeVector[j + 1].size();
            int left = 99;
            int right = 99;
            if (nextSize > num * 2) {
                if (treeVector[j + 1][num * 2] != nullptr) {
                    treeVector[j][i]->left = treeVector[j + 1][num * 2];
                    left = treeVector[j][i]->left->val;
                }
                if (nextSize > num * 2 + 1) {
                    if (treeVector[j + 1][num * 2 + 1] != nullptr) {
                        treeVector[j][i]->right = treeVector[j + 1][num * 2 + 1];

                        right = treeVector[j][i]->right->val;
                    }
                }
            }
            num++;
        }
    }
    return treeVector[0][0];
}
string GetNode(Node *tree) {
    string answer;
    vector<Node *> answer1;
    GetNode1(0, tree, answer1);
    for (int i = 0; i < answer1.size(); ++i) {
        while (answer1[i]!= nullptr){
            answer+=to_string(answer1[i]->val)+",";
            answer1[i]=answer1[i]->next;
        }
        answer+="#,";
    }
    answer.pop_back();
    answer = "[" + answer + "]";
    return answer;
}
