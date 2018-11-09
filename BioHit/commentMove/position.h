#ifndef ANNOTATIONPOSITION_POSITION_H
#define ANNOTATIONPOSITION_POSITION_H

#include <iostream>
#include <string>
using namespace std;

class Position {
private:
    string s;
public:
    Position();
    ~Position();
    Position(string s2);
    const string &getS() const;
    void setS(const string &s);

    string mobile(int x);

};


#endif //ANNOTATIONPOSITION_POSITION_H
