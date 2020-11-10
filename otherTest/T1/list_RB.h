#ifndef T1_LIST_RB_H
#define T1_LIST_RB_H
//#linux 3.0.8
//#include <linux/types.h>
//#include <linux/stddef.h>
//#include <linux/const.h>
/*
 * These are non-NULL pointers that will result in page faults
 * under normal circumstances, used to verify that nobody uses
 * non-initialized list entries.
 */

#define LIST_POISON1  nullptr
#define LIST_POISON2  nullptr
#include <cstdlib>
#include <printf.h>

/*
 * Insert a list_new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
struct list_head_RB{//next：下一个链表的地址 prev：上一个链表的地址
//    int
    struct list_head_RB *left,*right,*prev;
};
/*
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */

#define list_head_RB_INIT(name) { &(name), &(name) }

#define list_head_RB(name) \
	struct list_head_RB name = list_head_RB_INIT(name)

static inline void INIT_list_head_RB(struct list_head_RB *list)
{//初始化
    list->left = list;
    list->right = list;
    list->prev = list;
}



#ifndef CONFIG_DEBUG_LIST
static inline void __list_add(struct list_head_RB *list_new,struct list_head_RB *prev,struct list_head_RB *next){//添加节点
    next->prev = list_new;
    list_new->left = next;
    list_new->prev = prev;
    prev->left = list_new;
}
static inline void __list_add_left(struct list_head_RB *list_new,struct list_head_RB *prev,struct list_head_RB *next){//添加左节点
    next->prev = list_new;
    list_new->left = next;
    list_new->prev = prev;
    prev->left = list_new;
}
static inline void __list_add_right(struct list_head_RB *list_new,struct list_head_RB *prev,struct list_head_RB *next){//添加右节点
    next->prev = list_new;
    list_new->right = next;
    list_new->prev = prev;
    prev->right = list_new;
}
#else
extern void __list_add(struct list_head_RB *list_new,
			      struct list_head_RB *prev,
			      struct list_head_RB *next);
#endif

/**
 * list_add - add a list_new entry
 * @list_new: list_new entry to be added
 * @head: list head to add it after
 *
 * Insert a list_new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(struct list_head_RB *list_new, struct list_head_RB *head){//head后添加
    __list_add(list_new, head, head->left);
}


/**
 * list_add_tail - add a list_new entry
 * @list_new: list_new entry to be added
 * @head: list head to add it before
 *
 * Insert a list_new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void list_add_tail(struct list_head_RB *list_new, struct list_head_RB *head){//head前添加
    __list_add(list_new, head->prev, head);
}

///*
// * Delete a list entry by making the prev/next entries
// * point to each other.
// *
// * This is only for internal list manipulation where we know
// * the prev/next entries already!
// */
//static inline void __list_del(struct list_head_RB * prev, struct list_head_RB * next)
//{//删除链表
//    next->prev = prev;
//    prev->next = next;
//}
//
///**
// * list_del - deletes entry from list.
// * @entry: the element to delete from the list.
// * Note: list_empty() on entry does not return true after this, the entry is
// * in an undefined state.
// */
//#ifndef CONFIG_DEBUG_LIST
//static inline void __list_del_entry(struct list_head_RB *entry)
//{//删除链表前
//    __list_del(entry->prev, entry->next);
//}
//
//static inline void list_del(struct list_head_RB *entry)
//{//删除链表后
//    __list_del(entry->prev, entry->next);
//    entry->next = LIST_POISON1;
//    entry->prev = LIST_POISON2;
//}
//#else
//extern void __list_del_entry(struct list_head_RB *entry);
//extern void list_del(struct list_head_RB *entry);
//#endif
//
///**
// * list_replace - replace old entry by list_new one
// * @old : the element to be replaced
// * @list_new : the list_new element to insert
// *
// * If @old was empty, it will be overwritten.
// */
//static inline void list_replace(struct list_head_RB *old,
//                                struct list_head_RB *list_new)
//{
//    list_new->next = old->next;
//    list_new->next->prev = list_new;
//    list_new->prev = old->prev;
//    list_new->prev->next = list_new;
//}
//
//static inline void list_replace_init(struct list_head_RB *old,
//                                     struct list_head_RB *list_new)
//{
//    list_replace(old, list_new);
//    INIT_list_head_RB(old);
//}
//
///**
// * list_del_init - deletes entry from list and reinitialize it.
// * @entry: the element to delete from the list.
// */
//static inline void list_del_init(struct list_head_RB *entry)
//{
//    __list_del_entry(entry);
//    INIT_list_head_RB(entry);
//}
//
///**
// * list_move - delete from one list and add as another's head
// * @list: the entry to move
// * @head: the head that will precede our entry
// */
//static inline void list_move(struct list_head_RB *list, struct list_head_RB *head)
//{
//    __list_del_entry(list);
//    list_add(list, head);
//}
//
///**
// * list_move_tail - delete from one list and add as another's tail
// * @list: the entry to move
// * @head: the head that will follow our entry
// */
//static inline void list_move_tail(struct list_head_RB *list,
//                                  struct list_head_RB *head)
//{
//    __list_del_entry(list);
//    list_add_tail(list, head);
//}
//
///**
// * list_is_last - tests whether @list is the last entry in list @head
// * @list: the entry to test
// * @head: the head of the list
// */
//static inline int list_is_last(const struct list_head_RB *list,
//                               const struct list_head_RB *head)
//{
//    return list->next == head;
//}
//
///**
// * list_empty - tests whether a list is empty
// * @head: the list to test.
// */
//static inline int list_empty(const struct list_head_RB *head)
//{//判断链表是否为空
//    return head->next == head;
//}
//
///**
// * list_empty_careful - tests whether a list is empty and not being modified
// * @head: the list to test
// *
// * Description:
// * tests whether a list is empty _and_ checks that no other CPU might be
// * in the process of modifying either member (next or prev)
// *
// * NOTE: using list_empty_careful() without synchronization
// * can only be safe if the only activity that can happen
// * to the list entry is list_del_init(). Eg. it cannot be used
// * if another CPU could re-list_add() it.
// */
//static inline int list_empty_careful(const struct list_head_RB *head)
//{
//    struct list_head_RB *next = head->next;
//    return (next == head) && (next == head->prev);
//}
//
///**
// * list_rotate_left - rotate the list to the left
// * @head: the head of the list
// */
//static inline void list_rotate_left(struct list_head_RB *head)
//{
//    struct list_head_RB *first;
//
//    if (!list_empty(head)) {
//        first = head->next;
//        list_move_tail(first, head);
//    }
//}
//
///**
// * list_is_singular - tests whether a list has just one entry.
// * @head: the list to test.
// */
//static inline int list_is_singular(const struct list_head_RB *head)
//{
//    return !list_empty(head) && (head->next == head->prev);
//}
//
//static inline void __list_cut_position(struct list_head_RB *list,
//                                       struct list_head_RB *head, struct list_head_RB *entry)
//{
//    struct list_head_RB *list_new_first = entry->next;
//    list->next = head->next;
//    list->next->prev = list;
//    list->prev = entry;
//    entry->next = list;
//    head->next = list_new_first;
//    list_new_first->prev = head;
//}
//
///**
// * list_cut_position - cut a list into two
// * @list: a list_new list to add all removed entries
// * @head: a list with entries
// * @entry: an entry within head, could be the head itself
// *	and if so we won't cut the list
// *
// * This helper moves the initial part of @head, up to and
// * including @entry, from @head to @list. You should
// * pass on @entry an element you know is on @head. @list
// * should be an empty list or a list you do not care about
// * losing its data.
// *
// */
//static inline void list_cut_position(struct list_head_RB *list,
//                                     struct list_head_RB *head, struct list_head_RB *entry)
//{
//    if (list_empty(head))
//        return;
//    if (list_is_singular(head) &&
//        (head->next != entry && head != entry))
//        return;
//    if (entry == head)
//        INIT_list_head_RB(list);
//    else
//        __list_cut_position(list, head, entry);
//}
//
//static inline void __list_splice(const struct list_head_RB *list,
//                                 struct list_head_RB *prev,
//                                 struct list_head_RB *next)
//{
//    struct list_head_RB *first = list->next;
//    struct list_head_RB *last = list->prev;
//
//    first->prev = prev;
//    prev->next = first;
//
//    last->next = next;
//    next->prev = last;
//}
//
///**
// * list_splice - join two lists, this is designed for stacks
// * @list: the list_new list to add.
// * @head: the place to add it in the first list.
// */
//static inline void list_splice(const struct list_head_RB *list,
//                               struct list_head_RB *head)
//{
//    if (!list_empty(list))
//        __list_splice(list, head, head->next);
//}
//
///**
// * list_splice_tail - join two lists, each list being a queue
// * @list: the list_new list to add.
// * @head: the place to add it in the first list.
// */
//static inline void list_splice_tail(struct list_head_RB *list,
//                                    struct list_head_RB *head)
//{
//    if (!list_empty(list))
//        __list_splice(list, head->prev, head);
//}
//
///**
// * list_splice_init - join two lists and reinitialise the emptied list.
// * @list: the list_new list to add.
// * @head: the place to add it in the first list.
// *
// * The list at @list is reinitialised
// */
//static inline void list_splice_init(struct list_head_RB *list,
//                                    struct list_head_RB *head)
//{
//    if (!list_empty(list)) {
//        __list_splice(list, head, head->next);
//        INIT_list_head_RB(list);
//    }
//}
//
///**
// * list_splice_tail_init - join two lists and reinitialise the emptied list
// * @list: the list_new list to add.
// * @head: the place to add it in the first list.
// *
// * Each of the lists is a queue.
// * The list at @list is reinitialised
// */
//static inline void list_splice_tail_init(struct list_head_RB *list,
//                                         struct list_head_RB *head)
//{
//    if (!list_empty(list)) {
//        __list_splice(list, head->prev, head);
//        INIT_list_head_RB(list);
//    }
//}
//
///**
// * list_entry - get the struct for this entry
// * @ptr:	the &struct list_head_RB pointer.
// * @type:	the type of the struct this is embedded in.
// * @member:	the name of the list_struct within the struct.
// */
//#define list_entry(ptr, type, member) \
//	container_of(ptr, type, member)
//
///**
// * list_first_entry - get the first element from a list
// * @ptr:	the list head to take the element from.
// * @type:	the type of the struct this is embedded in.
// * @member:	the name of the list_struct within the struct.
// *
// * Note, that list is expected to be not empty.
// */
//#define list_first_entry(ptr, type, member) \
//	list_entry((ptr)->next, type, member)
//
///**
// * list_for_each	-	iterate over a list
// * @pos:	the &struct list_head_RB to use as a loop cursor.
// * @head:	the head for your list.
// */
//#define list_for_each(pos, head) \
//	for (pos = (head)->next; pos != (head); pos = pos->next)
//
///**
// * __list_for_each	-	iterate over a list
// * @pos:	the &struct list_head_RB to use as a loop cursor.
// * @head:	the head for your list.
// *
// * This variant doesn't differ from list_for_each() any more.
// * We don't do prefetching in either case.
// */
//#define __list_for_each(pos, head) \
//	for (pos = (head)->next; pos != (head); pos = pos->next)
//
///**
// * list_for_each_prev	-	iterate over a list backwards
// * @pos:	the &struct list_head_RB to use as a loop cursor.
// * @head:	the head for your list.
// */
//#define list_for_each_prev(pos, head) \
//	for (pos = (head)->prev; pos != (head); pos = pos->prev)
//
///**
// * list_for_each_safe - iterate over a list safe against removal of list entry
// * @pos:	the &struct list_head_RB to use as a loop cursor.
// * @n:		another &struct list_head_RB to use as temporary storage
// * @head:	the head for your list.
// */
//#define list_for_each_safe(pos, n, head) \
//	for (pos = (head)->next, n = pos->next; pos != (head); \
//		pos = n, n = pos->next)
//
///**
// * list_for_each_prev_safe - iterate over a list backwards safe against removal of list entry
// * @pos:	the &struct list_head_RB to use as a loop cursor.
// * @n:		another &struct list_head_RB to use as temporary storage
// * @head:	the head for your list.
// */
//#define list_for_each_prev_safe(pos, n, head) \
//	for (pos = (head)->prev, n = pos->prev; \
//	     pos != (head); \
//	     pos = n, n = pos->prev)
//
///**
// * list_for_each_entry	-	iterate over list of given type
// * @pos:	the type * to use as a loop cursor.
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// */
//#define list_for_each_entry(pos, head, member)				\
//	for (pos = list_entry((head)->next, typeof(*pos), member);	\
//	     &pos->member != (head); 	\
//	     pos = list_entry(pos->member.next, typeof(*pos), member))
//
///**
// * list_for_each_entry_reverse - iterate backwards over list of given type.
// * @pos:	the type * to use as a loop cursor.
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// */
//#define list_for_each_entry_reverse(pos, head, member)			\
//	for (pos = list_entry((head)->prev, typeof(*pos), member);	\
//	     &pos->member != (head); 	\
//	     pos = list_entry(pos->member.prev, typeof(*pos), member))
//
///**
// * list_prepare_entry - prepare a pos entry for use in list_for_each_entry_continue()
// * @pos:	the type * to use as a start point
// * @head:	the head of the list
// * @member:	the name of the list_struct within the struct.
// *
// * Prepares a pos entry for use as a start point in list_for_each_entry_continue().
// */
//#define list_prepare_entry(pos, head, member) \
//	((pos) ? : list_entry(head, typeof(*pos), member))
//
///**
// * list_for_each_entry_continue - continue iteration over list of given type
// * @pos:	the type * to use as a loop cursor.
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// *
// * Continue to iterate over list of given type, continuing after
// * the current position.
// */
//#define list_for_each_entry_continue(pos, head, member) 		\
//	for (pos = list_entry(pos->member.next, typeof(*pos), member);	\
//	     &pos->member != (head);	\
//	     pos = list_entry(pos->member.next, typeof(*pos), member))
//
///**
// * list_for_each_entry_continue_reverse - iterate backwards from the given point
// * @pos:	the type * to use as a loop cursor.
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// *
// * Start to iterate over list of given type backwards, continuing after
// * the current position.
// */
//#define list_for_each_entry_continue_reverse(pos, head, member)		\
//	for (pos = list_entry(pos->member.prev, typeof(*pos), member);	\
//	     &pos->member != (head);	\
//	     pos = list_entry(pos->member.prev, typeof(*pos), member))
//
///**
// * list_for_each_entry_from - iterate over list of given type from the current point
// * @pos:	the type * to use as a loop cursor.
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// *
// * Iterate over list of given type, continuing from current position.
// */
//#define list_for_each_entry_from(pos, head, member) 			\
//	for (; &pos->member != (head);	\
//	     pos = list_entry(pos->member.next, typeof(*pos), member))
//
///**
// * list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
// * @pos:	the type * to use as a loop cursor.
// * @n:		another type * to use as temporary storage
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// */
//#define list_for_each_entry_safe(pos, n, head, member)			\
//	for (pos = list_entry((head)->next, typeof(*pos), member),	\
//		n = list_entry(pos->member.next, typeof(*pos), member);	\
//	     &pos->member != (head); 					\
//	     pos = n, n = list_entry(n->member.next, typeof(*n), member))
//
///**
// * list_for_each_entry_safe_continue - continue list iteration safe against removal
// * @pos:	the type * to use as a loop cursor.
// * @n:		another type * to use as temporary storage
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// *
// * Iterate over list of given type, continuing after current point,
// * safe against removal of list entry.
// */
//#define list_for_each_entry_safe_continue(pos, n, head, member) 		\
//	for (pos = list_entry(pos->member.next, typeof(*pos), member), 		\
//		n = list_entry(pos->member.next, typeof(*pos), member);		\
//	     &pos->member != (head);						\
//	     pos = n, n = list_entry(n->member.next, typeof(*n), member))
//
///**
// * list_for_each_entry_safe_from - iterate over list from current point safe against removal
// * @pos:	the type * to use as a loop cursor.
// * @n:		another type * to use as temporary storage
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// *
// * Iterate over list of given type from current point, safe against
// * removal of list entry.
// */
//#define list_for_each_entry_safe_from(pos, n, head, member) 			\
//	for (n = list_entry(pos->member.next, typeof(*pos), member);		\
//	     &pos->member != (head);						\
//	     pos = n, n = list_entry(n->member.next, typeof(*n), member))
//
///**
// * list_for_each_entry_safe_reverse - iterate backwards over list safe against removal
// * @pos:	the type * to use as a loop cursor.
// * @n:		another type * to use as temporary storage
// * @head:	the head for your list.
// * @member:	the name of the list_struct within the struct.
// *
// * Iterate backwards over list of given type, safe against removal
// * of list entry.
// */
//#define list_for_each_entry_safe_reverse(pos, n, head, member)		\
//	for (pos = list_entry((head)->prev, typeof(*pos), member),	\
//		n = list_entry(pos->member.prev, typeof(*pos), member);	\
//	     &pos->member != (head); 					\
//	     pos = n, n = list_entry(n->member.prev, typeof(*n), member))
//
///**
// * list_safe_reset_next - reset a stale list_for_each_entry_safe loop
// * @pos:	the loop cursor used in the list_for_each_entry_safe loop
// * @n:		temporary storage used in list_for_each_entry_safe
// * @member:	the name of the list_struct within the struct.
// *
// * list_safe_reset_next is not safe to use in general if the list may be
// * modified concurrently (eg. the lock is dropped in the loop body). An
// * exception to this is if the cursor element (pos) is pinned in the list,
// * and list_safe_reset_next is called after re-taking the lock and before
// * completing the current iteration of the loop body.
// */
//#define list_safe_reset_next(pos, n, member)				\
//	n = list_entry(pos->member.next, typeof(*pos), member)
//
///*
// * Double linked lists with a single pointer list head.
// * Mostly useful for hash tables where the two pointer list head is
// * too wasteful.
// * You lose the ability to access the tail in O(1).
// */
//

#endif //T1_LIST_RB_H
