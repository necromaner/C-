#include "Chapter6.h"

string change(string &word){
    for(auto &c:word){
        c=tolower(c);
    }
    return word;
}
