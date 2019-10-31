//
// Created by necromaner on 2019-10-31.
//
//#include <memory>//智能指针头文件
#include <iostream>
using namespace std;
class Monster{
public:
    Monster(){
        this->num=0;
        cout<<"新建怪物"<<endl;
    }
    Monster(int num){
        this->num=num;
        cout<<"新建怪物"<<num<<endl;
    }
    ~Monster(){
        cout<<"杀死怪物"<<num<<endl;
    };
    void doSomething(){
        cout<<"怪物"<<num<<"去做事情\n";
    }
private:
    int num;
};
//auto_ptr（不要使用的指针）
//auto_ptr 是C++标准库提供的类模板，
//auto_ptr对象通过初始化指向由new创建的动态内存，它是这块内存的拥有者，一块内存不能同时被分给两个拥有者。
//当auto_ptr对象生命周期结束时，其析构函数会将auto_ptr对象拥有的动态内存自动释放。
//即使发生异常，通过异常的栈展开过程也能将动态内存释放。auto_ptr不支持new 数组。
void runGame1(){
    cout<<"\n忘记杀死怪物\n";
    Monster *monster1=new Monster(1);
    monster1->doSomething();//怪物做某种事
}
void runGame2(){
    cout<<"\n正常操作怪物\n";
    Monster *monster1=new Monster(2);
    monster1->doSomething();//怪物做某种事
    delete monster1;
}
void runGame3(){
    cout<<"\n智能指针操作怪物\n";
    auto_ptr<Monster> monster2(new Monster(3));//monster1 指向 一个怪物
    monster2->doSomething();//怪物做某种事
}
void runGame4(){
    cout<<"\n智能指针操作怪物-魂穿\n";
    std::auto_ptr<Monster> monster4(new Monster(4));//monster1 指向 一个怪物
    monster4->doSomething();//怪物做某种事

    cout<<"魂穿\n";
    std::auto_ptr<Monster> monster_new = monster4;//转移指针
    monster_new->doSomething();//怪物做某种事
    //如果函数中不包含其他类中元素不会崩溃 ？？？
//    monster4->doSomething();//Oops!monster1智能指针指向了nullptr，运行期崩溃。
    //因为一块动态内存智能由一个智能指针独享，所以在拷贝构造或赋值时都会发生拥有权转移的过程。
    // 在此拷贝构造过程中，monster1将失去对字符串内存的所有权，而monster2将其获得。对象销毁时，monster2负责内存的自动销毁。
}
void runGame5(){
    cout<<"\n智能指针操作怪物-肉身夺舍\n";
    std::auto_ptr<Monster> monster5(new Monster(5));//monster1 指向 一个怪物
    monster5->doSomething();//怪物做某种事
    std::auto_ptr<Monster> monster6(new Monster(6));//monster1 指向 一个怪物
    monster6->doSomething();//怪物做某种事

    cout<<"怪物6肉身夺舍怪物5\n";
    monster6 = monster5;//转移指针
    monster6->doSomething();//怪物5做某种事
//    monster5->doSomething();//Oops!monster5智能指针指向了nullptr，运行期崩溃。
}
void runGame(){
    runGame1();
    runGame2();
    runGame3();
    runGame4();
    runGame5();
}
