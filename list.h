#define _LIST_H

#include <stdbool.h>

typedef int type_elem;

/* list as a pointer to structs to guarantee encapsulation */

typedef struct _Node{
    type_elem elem;
    struct _Node* next;
}type_list;

typedef type_list *list;
/* Constructors */

list empty(void);
/*
    Create empty list.
*/

list addl(list l, type_elem e);
/*
    Adds elem 'e' at the beginning of list l.
*/

void destroy_list(list l);
/*
   Frees memory for l.
*/

/* Operations */

bool is_empty(list l);
/*
    Returns True if l has no elements.
*/

type_elem head(list l);
/*
    Returns the first element of list l.
*/

list tail(list l);
/*
    Deletes the first element of list l.
*/

list addr(list l, type_elem e);
/*
    Adds element 'e' at the end of list l 
*/

int len(list l);
/*
    Returns the lenght of list l. If l is empty, length = 0.
*/

list concat(list l1, list l2);
/*
    Adds all elements of list 'l2' at the end of list 'l1'.
    For example, if l1 = {1,2,3} and l2 = {3,2,1}, 
    concat(l1,l2) returns l1 = {1,2,3,3,2,1}.
*/

type_elem index(list l, int i);
/*
    Returns the element of list l at position 'i'. For example,
    l = {1,2,3,4}, index(l, 2) = 3. 'i' must be smaller than length(l).
*/

list take(list l, int n);
/*
    Deletes all elements of l from position 'n' to position
    lentgth(l)-1. The result is list l with the elements in 
    position 0 to n-1.
    For example, if l = {1,2,3,4,5}, take(l, 2) returns 
    l = {1,2}. n must be smaller than length(l).
*/

list drop(list l, int n);
/*
    Deletes the first 'n' elements of l. The result is list 
    l with elements in positions n to length(l)-1.
    For example, if l = {1,2,3,4,5}, drop(l1, 2) returns 
    l = {3,4,5}. n must be smaller or equal than length(l).
*/

list copy(list l);
/*
    Makes a copy of list l. Allocates new memory.
*/


















