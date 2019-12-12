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
        cout<<"新建怪物"<<this->num<<endl;
    }
    ~Monster(){
        cout<<"杀死怪物"<<num<<endl;
    };
    void doSomething(){
        cout<<"怪物"<<num<<"去做事情\n";
    }
    void setFather(std::shared_ptr<Monster>& father){
        m_father=father;
        cout<<"怪物"<<num<<"的爸爸:怪物"<<m_father->num<<endl;
    }
    void doFather(){
        if(m_father){
            cout<<"怪物"<<num<<"让爸爸";
            m_father->doSomething();
        }else{
            cout<<"怪物"<<num<<"没有爸爸\n";
        }
    }
    void setSon(std::shared_ptr<Monster>& son){
        m_son=son;
        cout<<"怪物"<<num<<"的儿子:怪物"<<m_son->num<<endl;
    }
    void doSon(){
        if(m_son){
            cout<<"怪物"<<num<<"让儿子";
            m_son->doSomething();
        }else{
            cout<<"怪物"<<num<<"没有儿子\n";
        }
    }
    void setFather1(std::shared_ptr<Monster>& father){
        m_father1=father;
        //尽管父子可以互相访问，但是彼此都是独立的个体，无论是谁都不应该拥有另一个人的所有权。
//        cout<<"怪物"<<num<<"的爸爸:怪物"<<m_father1->num<<endl;
        cout<<"怪物"<<num<<"的爸爸:怪物"<<father->num<<endl;
    }

    void setSon1(std::shared_ptr<Monster>& son){
        m_son1=son;
        cout<<"怪物"<<num<<"的儿子:怪物"<<son->num<<endl;
    }

private:
    int num;
    shared_ptr<Monster> m_father;
    shared_ptr<Monster> m_son;

    //尽管父子可以互相访问，但是彼此都是独立的个体，无论是谁都不应该拥有另一个人的所有权。
    weak_ptr<Monster> m_father1;
    weak_ptr<Monster> m_son1;
};
//auto_ptr（不要使用的指针）
/*
auto_ptr 是C++标准库提供的类模板，
auto_ptr对象通过初始化指向由new创建的动态内存，它是这块内存的拥有者，一块内存不能同时被分给两个拥有者。
当auto_ptr对象生命周期结束时，其析构函数会将auto_ptr对象拥有的动态内存自动释放。
即使发生异常，通过异常的栈展开过程也能将动态内存释放。auto_ptr不支持new 数组。
虽然它是c++11以前的最原始的智能指针，但是在c++11中已经被弃用（使用的话会被警告）了。
它的替代品，也就是c++11新智能指针unique_ptr,shared_ptr,weak_ptr将在下文出现
 */
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

    cout<<"怪物6-肉身夺舍-怪物5\n";
    monster6 = monster5;//转移指针
    monster6->doSomething();//怪物5做某种事
//    monster5->doSomething();//Oops!monster5智能指针指向了nullptr，运行期崩溃。
}
void runGame6(){
    cout<<"\n智能指针操作怪物-涅槃\n";
    std::auto_ptr<Monster> monster5(new Monster(5));//monster1 指向 一个怪物
    monster5->doSomething();//怪物做某种事
    cout<<"怪物5-涅槃-怪物6\n";
    monster5.reset(new Monster(6));//monster1 指向 一个怪物
    monster5->doSomething();//怪物做某种事
}

void runGame_auto_ptr(){
    runGame1();
    runGame2();
    runGame3();
    runGame4();
    runGame5();
    runGame6();
}
//unique_ptr（一种强引用指针）
/*
(都是独占资源的指针,内部实现也基本差不多).
但是unique_ptr的名字能更好的体现它的语义，而且在语法上比auto_ptr更安全（尝试复制unique_ptr时会编译期出错，而auto_ptr能通过编译期从而在运行期埋下出错的隐患）
假如你真的需要转移所有权（独占权），那么你就需要用std::move(std::unique_ptr对象)语法，尽管转移所有权后 还是有可能出现原有指针调用（调用就崩溃）的情况。
但是这个语法能强调你是在转移所有权，让你清晰的知道自己在做什么，从而不乱调用原有指针。
*/
void runGame7(){
    cout<<"\n智能指针操作怪物-多人控制\n";
    shared_ptr<Monster> monster1(new Monster(1));//计数加到1
    cout<<"怪物2-控制-怪物1\n";
    do{shared_ptr<Monster> monster2 = monster1;//计数加到2
        }while(0);
    //该栈退出后，计数减为1，monster1指向的堆对象仍存在
    cout<<"怪物3-控制-怪物1\n";
    shared_ptr<Monster> monster3 = monster1;//计数加到2
    monster1->doSomething();//怪物做某种事
    monster3->doSomething();//怪物做某种事

}
void runGame8(){
    cout<<"\n智能指针操作怪物-循环依赖\n";
    shared_ptr<Monster> father(new Monster(1));
    shared_ptr<Monster> son (new Monster(2));

    father->setSon(son);
    son->setFather(father);
    father->doSon();
    father->doFather();
    son->doSon();
    son->doFather();
    //不能执行析构函数
    //开始:
    //father,son指向的堆对象 shared计数都是为2
    //
    //son智能指针退出栈：
    //son指向的堆对象 计数减为1，father指向的堆对象 计数仍为2。
    //
    //father智能指针退出栈:
    //father指向的堆对象 计数减为1 , son指向的堆对象 计数仍为1。
    //
    //函数结束：所有计数都没有变0，也就是说中途没有释放任何堆对象。
    //
    //为了解决这一缺陷的存在，弱引用指针weak_ptr的出现很有必要。
}
void runGame_unique_ptr(){
    runGame7();
    runGame8();
}

//weak_ptr（一种弱引用指针）
/*
“它是我们(weak_ptr)的，也是你们(shared_ptr)的，但实质还是你们的”——鲁迅
weak_ptr是为了辅助shared_ptr的存在，它只提供了对管理对象的一个访问手段，同时也可以实时动态地知道指向的对象是否存活。
（只有某个对象的访问权，而没有它的生命控制权 即是 弱引用，所以weak_ptr是一种弱引用型指针）
内部大概实现:
计数区域(SharedPtrControlBlock)结构体引进新的int变量weak_count，来作为弱引用计数。
每个weak_ptr都占指针的两倍空间，一个装着原始指针，一个装着计数区域的指针（和shared_ptr一样的成员）。
weak_ptr可以由一个shared_ptr或者另一个weak_ptr构造。
weak_ptr的构造和析构不会引起shared_count的增加或减少，只会引起weak_count的增加或减少。
被管理资源的释放只取决于shared计数，当shared计数为0，才会释放被管理资源，
也就是说weak_ptr不控制资源的生命周期。
但是计数区域的释放却取决于shared计数和weak计数，当两者均为0时，才会释放计数区域。

 weak_ptr没有重载 * 和 -> ，所以并不能直接使用资源。但可以使用lock()获得一个可用的shared_ptr对象，
如果对象已经死了，lock()会失败，返回一个空的shared_ptr。
 */
void runGame9(){
    cout<<"\n智能指针操作怪物-循环依赖\n";
    shared_ptr<Monster> father(new Monster(1));
    shared_ptr<Monster> son(new Monster(2));
    father->setSon1(son);
    son->setFather1(father);
}
void runGame10(){
    cout<<"\n智能指针操作怪物-1\n";
    shared_ptr<Monster> monster1(new Monster(1));
    weak_ptr<Monster> r_monster1 = monster1;
//    r_monster1->doSomething();//Error! 编译器出错！weak_ptr没有重载* 和 -> ，无法直接当指针用
    shared_ptr<Monster> s_monster1 = r_monster1.lock();//OK!可以通过weak_ptr的lock方法获得shared_ptr。
    s_monster1->doSomething();
//    monster1= nullptr;//指针为空，执行析构函数
    monster1->doSomething();
}
void runGame_weak_ptr(){
    runGame9();
    runGame10();
}
//总结（语义）
//1、不要使用std::auto_ptr
//2、当你需要一个独占资源所有权（访问权+生命控制权）的指针，且不允许任何外界访问，请使用std::unique_ptr
//3、当你需要一个共享资源所有权（访问权+生命控制权）的指针，请使用std::shared_ptr
//当你需要一个能访问资源，但不控制其生命周期的指针，请使用std::weak_ptr
//
//推荐用法：
//一个shared_ptr和n个weak_ptr搭配使用 而不是n个shared_ptr
//因为一般模型中，最好总是被一个指针控制生命周期，然后可以被n个指针控制访问。
//逻辑上，大部分模型的生命在直观上总是受某一样东西直接控制而不是多样东西共同控制。
//程序上，能够完全避免生命周期互相控制引发的 循环引用问题。

//unique_ptr
/*
一个unique_ptr 拥有 它所指向的对象。
与sharedptr不同，某个时刻只能有一个uniqueptr指向一个给定对象。
当uniqueptr被销毁时，它所指向的对象也被销毁。
uniqueptr不支持普通的拷贝和赋值操作，但是可以通过release or reset来转移所有权。
用途
管理一些对象：不需要被共享，但也希望能够在超出作用域时，自动释放资源。
 */
void test_uniq_ptr() {
    std::unique_ptr<int> p1(new int(3));
//    std::unique_ptr<int> b;
//    b = a; //不支持赋值操作
//    std::unique_ptr<int> b = a;  //不支持拷贝构造

    //把p1指向的对象转移给p2
    std::unique_ptr<int> p2(p1.release());// release操作会自动给p1赋空
    cout << *p2 << endl;
    if (p1 == nullptr) {
        cout << "p1 is nullptr" << endl;
    }

    std::unique_ptr<int> p3(new int(4));

    //reset 会释放本对象
    //release 会转移所有权
    p2.reset(p3.release()); //p2释放原来的对象，同时指向p3所指向的对象，p3赋空
    cout << *p2 << endl;
    if (p3 == nullptr) {
        cout << "p3 is nullptr" << endl;
    }

    //释放对象，同时赋空
    p2.reset();
    if (p2 == nullptr) {
        cout << "p2 is nullptr" << endl;
    }

    //release操作会放弃当前指针的控制权，但是并不会销毁它。
    //因此通常调用release操作
    // 是为了 赋值  给另一个智能指针，
    // 而不是 为了销毁对象
    std::unique_ptr<int> p(new int(3));
    auto px = p.release(); //让出指针所有权，但是并没有销毁
    delete px; //这里需要手动delete px
}