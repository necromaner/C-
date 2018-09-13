//
// Created by 温亚奇 on 2018/9/9.
//

#include <iostream>
#include <sstream>
#include <vector>

#define _TEST

using namespace std;

typedef int TEST_TYPE;

template <typename T>
struct test_node {
    vector<T> original;
    vector<T> sorted;
};

template <typename T>
ostream& operator<< (ostream& strm, const vector<T> &v) {
    typename vector<T>::const_iterator it;
    for(it = v.begin(); it != v.end(); ++it) strm << *it << ' ';
    strm << endl;
    return strm;
}

template<typename BI>
void quick_sort(BI head, BI tail) {
    BI start, end;
    typedef typename iterator_traits<BI>::value_type value_type;
    value_type tmp;
    
    if(head!=tail)
    {
        start=head;
        end=tail-1;
        tmp=*start;
        while(start!=end){
            while(start!=end && tmp <= *end) {--end;}
            *start=*end;
            while(start!=end && *start <= tmp) {++start;}
            *end=*start;
        }
        *start=tmp;
        quick_sort(head,start);
        quick_sort(start+1,tail);
    }
}

void load_node(vector<test_node<TEST_TYPE> > &test_vector, const string &original, const string &sorted) {
    test_node<TEST_TYPE> tn;
    test_vector.push_back(tn);
    
    typedef vector<test_node<TEST_TYPE> >::iterator _itervtn;
    _itervtn it = test_vector.end()-1;
    
    typedef vector<TEST_TYPE>::value_type value_type;
    value_type n;
    
    istringstream ins;
    ins.str(original);
    while(ins >> n) {(*it).original.push_back(n);}
    
    ins.clear();
    ins.str(sorted);
    while(ins >> n) {(*it).sorted.push_back(n);}
}

template <typename T>
void load_node(vector<test_node<T> > &test_vector, const T & original, const T & sorted) {
    test_node<T> tn;
    test_vector.push_back(tn);
    
    typedef typename vector<test_node<T> >::iterator _itervtn;
    _itervtn it = test_vector.end()-1;
    
    (*it).original.push_back(original);
    (*it).sorted.push_back(sorted);
}

void test_quick_sort() {
    vector<test_node<TEST_TYPE> > test_vector;
    load_node(test_vector, "3 7 2 0 9 -5 4",    "-5 0 2 3 4 7 9");
    //delibrately alter 5 to 4
    load_node(test_vector, "1 2 3 4 5 6 7 8 9", "1 2 3 4 4 6 7 8 9");
    load_node(test_vector, "9 8 7 6 5 4 3 2 1", "1 2 3 4 5 6 7 8 9");
    load_node(test_vector, "4 1",               "1 4");
    load_node(test_vector, "3",                 "3");
    
    int passed=0;
    typedef vector<test_node<TEST_TYPE> >::iterator _itervtn;
    
    for(_itervtn it=test_vector.begin(); it != test_vector.end(); ++it)
    {
        quick_sort<vector<TEST_TYPE>::iterator>((*it).original.begin(),
                                                (*it).original.end());
        if((*it).original == (*it).sorted)
            ++passed;
        else {
            cout << "* No." << distance(test_vector.begin(),it)
                 << " did not pass test.\n";
            cout << "  ---Result: \t" << (*it).original
                 << "  ---Expected: \t" << (*it).sorted;
        }
    }
    cout << endl << "* Passed " << passed << '/' << test_vector.size() << endl;
}

int main()
{
#ifdef _TEST
    test_quick_sort();
#else
    int a[]={4,1};
        vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
      
        cout << "Original: /t" << v;
        quick_sort(v.begin(), v.end());
        cout << "Sorted: /t" << v;
#endif
    return 0;
}