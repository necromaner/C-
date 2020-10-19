#include "TreeNode.h"
#include <stack>
#include <queue>
// 逆序右边界
TreeNode* reverseEdge(TreeNode *head) {
    TreeNode *pre = nullptr;
    TreeNode *next = nullptr;

    while (head != nullptr) {
        next = head->right;
        head->right = pre;
        pre = head;
        head = next;
    }
    return pre;
}
// 逆序打印左子树右边界
void printEdge(TreeNode *head) {
    TreeNode *lastNode = reverseEdge(head);
    TreeNode *cur = lastNode;

    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->right;
    }
    reverseEdge(lastNode);
}
void TreeNode_DLR(TreeNode* root) {//先序遍历-递归
    if (root == nullptr)
        return;
    printf("%d ", root->val);//在前面
    TreeNode_DLR(root->left);
    TreeNode_DLR(root->right);
}
void TreeNode_DLR1(TreeNode* root) {//先序遍历-迭代
    if (root == nullptr)
        return;
    stack<TreeNode *> st;
    TreeNode *tmp = root;
    while (!st.empty() || tmp) {
        while (tmp) {
            printf("%d ", tmp->val);//在前面
            st.push(tmp);
            tmp = tmp->left;
        }
        tmp = st.top()->right;
        st.pop();
    }
}
void TreeNode_DLR2(TreeNode* root) {//先序遍历-迭代
    if (root == nullptr)
        return;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode *top = s.top();
        s.pop();
        printf("%d ", top->val);//在前面
        if (top->right) s.push(top->right);
        if (top->left) s.push(top->left);
    }
}
void TreeNode_DLR_Morris(TreeNode *head) {//先序遍历-Morris
    if (head == nullptr) {
        return;
    }
    TreeNode *p1 = head;
    TreeNode *p2 = nullptr;
    while (p1 != nullptr) {
        p2 = p1->left;
        if (p2 != nullptr) {
            while (p2->right != nullptr && p2->right != p1) {
                p2 = p2->right;
            }
            if (p2->right == nullptr) {
                p2->right = p1;        // 空闲指针
                cout << p1->val << " ";    // 打印结点值的顺序稍微调整
                p1 = p1->left;
                continue;
            } else {
                p2->right = nullptr;
            }
        } else {
            cout << p1->val << " ";
        }
        p1 = p1->right;
    }
}
void TreeNode_LDR(TreeNode* root) {//中序遍历-递归
    if (root == nullptr)
        return;
    TreeNode_LDR(root->left);
    printf("%d ", root->val);//在中间
    TreeNode_LDR(root->right);
}
void TreeNode_LDR1(TreeNode* root) {//中序遍历-迭代
        if (root == nullptr)
            return;
        stack<TreeNode *> st;
        TreeNode *tmp = root;
        while (!st.empty() || tmp) {
            while (tmp) {
                st.push(tmp);
                tmp = tmp->left;
            }
            TreeNode *t = st.top();
            st.pop();
            printf("%d ", t->val);//在中间
            tmp = t->right;
        }
}
void TreeNode_LDR_Morris(TreeNode *head) {//中序遍历-Morris
    if (head == nullptr) {
        return;
    }
    TreeNode *p1 = head;
    TreeNode *p2 = nullptr;
    while (p1 != nullptr) {
        p2 = p1->left;
        if (p2 != nullptr) {
            while (p2->right != nullptr && p2->right != p1) {
                p2 = p2->right;
            }
            if (p2->right == nullptr) {
                p2->right = p1;        // 空闲指针
                p1 = p1->left;
                continue;
            } else {
                p2->right = nullptr;
            }
        }
        cout << p1->val << " ";
        p1 = p1->right;
    }
}
void TreeNode_LRD(TreeNode* root) {//后序遍历-递归
    if (root == nullptr)
        return;
    TreeNode_LRD(root->left);
    TreeNode_LRD(root->right);
    printf("%d ", root->val);//在后面
}
void TreeNode_LRD1(TreeNode* root) {//后序遍历-迭代
    if (root == nullptr)
        return;
    stack<TreeNode *> st;
    TreeNode *tmp = root;
    while (!st.empty() || tmp) {
        while (tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
        TreeNode *t = st.top();
        st.pop();
        if(t->left)
            printf("%d ", t->left->val);//在中间
        if(t->right)
            printf("%d ", t->right->val);//在中间
        tmp = t->right;
    }
}
void TreeNode_LRD_Morris(TreeNode *head) {
    if (head == nullptr) {
        return;
    }

    TreeNode *p1 = head;
    TreeNode *p2 = nullptr;

    while (p1 != nullptr) {
        p2 = p1->left;
        if (p2 != nullptr) {
            while (p2->right != nullptr && p2->right != p1) {
                p2 = p2->right;
            }
            if (p2->right == nullptr) {
                p2->right = p1;        // 空闲指针
                p1 = p1->left;
                continue;
            } else {
                p2->right = nullptr;
                printEdge(p1->left);
            }
        }
        p1 = p1->right;
    }
    printEdge(head);
}

void TreeNode_DFS(TreeNode* root) {
    stack<TreeNode *> nodeStack;  //使用C++的STL标准模板库
    nodeStack.push(root);
    TreeNode *node;
    while (!nodeStack.empty()) {
        node = nodeStack.top();
        printf("%d ", node->val);//在后面
        nodeStack.pop();
        if (node->right) {
            nodeStack.push(node->right);  //先将右子树压栈
        }
        if (node->left) {
            nodeStack.push(node->left);  //再将左子树压栈
        }
    }
}
void TreeNode_BFS(TreeNode* root) {
    if (root == nullptr)
        return;
    queue<TreeNode *> nodeQueue;  //使用C++的STL标准模板库
    nodeQueue.push(root);
    TreeNode *node;
    while (!nodeQueue.empty()) {
        node = nodeQueue.front();
        nodeQueue.pop();
        printf("%d ", node->val);//在后面
        if (node->left != nullptr) {
            nodeQueue.push(node->left);  //先将左子树入队
        }
        if (node->right != nullptr) {
            nodeQueue.push(node->right);  //再将右子树入队
        }
    }
}

vector<string> split(const string& str, const string& pattern) {
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
void GetTreeNode1(int high,TreeNode *treeNode,vector<vector<string>> &treeHigh) {
    if (!treeNode)
        return;
    if (treeHigh.size() < high + 1) {
        vector<string> treeSize;
        treeSize.push_back(to_string(treeNode->val));
        treeHigh.push_back(treeSize);
    } else {
        treeHigh[high].push_back(to_string(treeNode->val));
    }
    if (treeNode->left)
        GetTreeNode1(high + 1, treeNode->left, treeHigh);
    else {
        if (treeHigh.size() < high + 2) {
            vector<string> treeSize;
            treeSize.push_back("null");
            treeHigh.push_back(treeSize);
        } else {
            treeHigh[high + 1].push_back("null");
        }
    }
    if (treeNode->right)
        GetTreeNode1(high + 1, treeNode->right, treeHigh);
    else {
        if (treeHigh.size() < high + 2) {
            vector<string> treeSize;
            treeSize.push_back("null");
            treeHigh.push_back(treeSize);
        } else {
            treeHigh[high + 1].push_back("null");
        }
    }
}

TreeNode *SetTreeNode(string tree) {
    if (tree.at(0) == '[')
        tree.erase(0, 1);
    if (tree.at(tree.size() - 1) == ']')
        tree.pop_back();
    vector<string> aa;
    aa = split(tree, ",");

    vector<vector<TreeNode *>> treeVector;
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
                vector<TreeNode *> bb;
                if (aa[i] != "null") {
                    TreeNode *tree = new TreeNode(atof(aa[i].c_str()));
                    bb.push_back(tree);
                } else
                    bb.push_back(nullptr);
                treeVector.push_back(bb);
            } else {
                if (aa[i] != "null") {
                    TreeNode *tree = new TreeNode(atof(aa[i].c_str()));
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
string GetTreeNode(TreeNode *tree) {
    string answer;
    vector<vector<string>> answer1;
    GetTreeNode1(0, tree, answer1);
    int size = answer1.size();
    for (int i = size - 1; i >= 0; --i) {
        int size1 = answer1[i].size();
        for (int j = size1 - 1; j >= 0; --j) {
            if (!(answer.size() == 0 && answer1[i][j] == "null"))
                answer = answer1[i][j] + "," + answer;
        }
    }
    answer.pop_back();
    answer = "[" + answer + "]";
    return answer;
}




void buildBinTree(TreeNode **head) {
    int _val;
    cin >> _val;

    if (_val == -1) {
        *head = nullptr;
    } else {
        *head = (TreeNode *) malloc(sizeof(TreeNode));
        (*head)->val = _val;
        buildBinTree(&(*head)->left);
        buildBinTree(&(*head)->right);
    }
}