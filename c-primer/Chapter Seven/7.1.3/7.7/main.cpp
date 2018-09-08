//7.7：使用这些新函数重写7.1.2节（第233页）练习中的交易处理程序。

#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total;
    if(read(cin,total))
    {
        Sales_data trans;
        while(read(cin, trans)){
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }else{
        cerr << "No data?!" << endl;
    }
    return 0;
}