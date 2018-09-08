#include "Chapter6.h"

int inspect(const string &word){
    for(auto a:word){
        if(isupper(a))
            return true;
        else
            return false;
    }
}
