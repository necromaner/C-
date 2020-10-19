//
// Created by necromaner on 2020/9/14.
//
/* queue可以使用：
 * front()	            返回 queue 中第一个元素的引用。
 * back()	            返回 queue 中最后一个元素的引用。
 * push(const T& obj)	在 queue 的尾部添加一个元素的副本。
 * pop()	            删除 queue中的第一个元素。
 * size()	            返回 queue中元素的个数。
 * empty()	            如果 queue中没有元素的话，返回 true。

 *
 */
#include "MyStack.h"
/** 在这里初始化你的数据结构。Initialize your data structure here. */
MyStack::MyStack(){
}

/** 将元素x压入堆栈。Push element x onto stack. */
void MyStack::push(int x) {
    queue<int> queue2;
    queue2.push(x);
    while (!queue1.empty()){
        queue2.push(queue1.front());
        queue1.pop();
    }
    queue1=queue2;
}

/** 删除堆栈顶部的元素并返回该元素。Removes the element on top of the stack and returns that element. */
int MyStack::pop() {
    if (queue1.empty())
        return 0;
    int pop=queue1.front();
    queue1.pop();
    return pop;
}

/** 获取顶部元素。Get the top element. */
int MyStack::top() {
    if (queue1.empty())
        return 0;
    return queue1.front();
}

/** 返回堆栈是否为空。Returns whether the stack is empty. */
bool MyStack::empty() {
    return queue1.empty();
}

//把除了顶部以外的重新压入一遍
int MyStack1::pop() {
    int size=queue1.size()-1;
    if(size<0){
        return 0;
    }
    while (size--){
        queue1.push(queue1.front());
        queue1.pop();
    }
    int pop=queue1.front();
    queue1.pop();
    return pop;
}

/** 获取顶部元素。Get the top element. */
int MyStack1::top() {
    if (queue1.empty())
        return 0;
    return queue1.back();
}

