//
// Created by necromaner on 2020/9/14.
//

#ifndef LEETCODE2_MYSTACK_H
#define LEETCODE2_MYSTACK_H

#include <queue>
using namespace std;
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 /*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7 MB, 在所有 C++ 提交中击败了43.77% 的用户
  */
class MyStack {//2)	栈（先进后出）
public:
    MyStack();
    void push(int x);
    int pop();
    int top();
    bool empty();
private:
    queue<int> queue1;//1)	堆（先进先出）
};
/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了79.44% 的用户
 */
class MyStack1 {//单队列
public:
    MyStack1(){}
    void push(int x){queue1.push(x);}//顺序压入
    int pop();
    int top();
    bool empty(){return queue1.empty();}
private:
    queue<int> queue1;//1)	堆（先进先出）
};

#endif //LEETCODE2_MYSTACK_H
