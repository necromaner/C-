#include <stdio.h>
#include <stdlib.h>
#include <vector>

//#include "list.h"
#include "list_priority.h"

struct person{
    struct priority_list list;
    int age;
};
int main(int argc,char **argv) {
    struct person *p;
    struct person person1;
    struct priority_list *pos;

    INIT_LIST_HEAD(&person1.list);

    std::vector<int> bbb = {-100, -200, -3, -10, 1, 100, 3, 55, -11, 121, 0, 30};
    for (int i = 0; i < bbb.size(); i++) {
        p = (struct person *) malloc(sizeof(struct person));
        p->age = bbb[i];
        p->list._priority = p->age;
        list_add(&p->list, &person1.list);
    }
    list_for_each(pos, &person1.list) {
        printf("age = %d\n", ((struct person *) pos)->age);
    }
    return 0;
}