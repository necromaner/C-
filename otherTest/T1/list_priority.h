#ifndef T1_LIST_PRIORITY_H
#define T1_LIST_PRIORITY_H
struct priority_list{
    int _priority;
    struct priority_list *prev,*next;
};
#define list_for_each(pos,head) for(pos=(head)->next;pos!=(head);pos=pos->next)//遍历链表
static inline void INIT_LIST_HEAD(struct priority_list* list){//初始化链表
    list->next=list;
    list->prev=list;
}

static inline void _list_add(struct priority_list* list_new, struct priority_list* prev, struct priority_list* next) {//在prev后next前插入
    prev->next = list_new;
    list_new->prev = prev;
    list_new->next = next;
    next->prev = list_new;
}
static inline void list_add_first(struct priority_list *list_new, struct priority_list *list) {//list前插入
    _list_add(list_new, list, list->next);
}
static inline void list_add_last(struct priority_list *list_new, struct priority_list *list) {//list后插入{
    _list_add(list_new, list->prev, list);
}
static inline void list_add(struct priority_list* list_new, struct priority_list* head) {
    struct priority_list *list = head->next;
    while (list != head) {
        if (list_new->_priority > list->_priority) {
            list_add_last(list_new, list);
            return;
        }
        list = list->next;
    }
    list_add_last(list_new, head);
}

#endif //T1_LIST_PRIORITY_H
