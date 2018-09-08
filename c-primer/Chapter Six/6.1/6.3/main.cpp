//6.3：编写你自己的fact函数，上机检查是否正确。

#include <iostream>
using namespace std;

int face() {
    int aa;
    cout<<"Enter:";
    cin>>aa;
    end:
    int cc = aa;
    if (aa > 0) {
        for (int i = aa; i > 1; --i) {
            cc *= i - 1;
        }
    } else if (aa == 0) {
        cc = 1;
    } else {
        cout << "Not less than zero" << endl;
        cout << "again?(Y or N):";
        char dd;
        cin >> dd;
        if (!cin || dd == 'Y'|| dd == 'y') {
            cout << "Enter:";
            cin >> aa;
            goto end;
        } else
            return -1;
    }

}
int main() {
    face();
    return 0;
}