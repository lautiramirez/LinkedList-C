
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

/* Constructors */

list empty(void){
    list l;
    l = NULL;
    return l;
}

list addl(list l, type_elem e){
    
    list l_temp = malloc(sizeof(struct _Node));
    l_temp -> elem = e;
    l_temp -> next = l;
    l = l_temp;

    //free(l_temp);

    return l;
}

void destroy_list(list l) {
    while(l) {
        list toDelete = l;
        l = l->next;
        free(toDelete);
        toDelete = NULL;
    }
}
/* Operations */

bool is_empty(list l){
    bool res = false;
    if (l == NULL){
        res = true;
    }

 return res;
}

type_elem head(list l){
    assert(!is_empty(l));
    list aux = l;
    return aux->elem;
}

list tail(list l){
    assert(!is_empty(l));
    
    l = l->next;
       
    return l;    
}

list addr(list l, type_elem e){
    list new = (list)malloc(sizeof(struct _Node));
    list aux = l;
    new->elem = e;
    new->next = NULL;

  if (l==NULL){
     l = new;
    }  
    
  else{
        
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new;

    }
     
    return l;
}

int len(list l){
    list aux = l;
    int length = 0;
    while (aux != NULL){
       length++;
       aux = aux->next;
    }
    
    return length; 
}

type_elem index(list l, int i){
    assert(i<len(l));
    list aux = l;
    type_elem index = -1;
    int j = 0;
    while ((j<=i) && (aux->next != NULL))
    {
        index = head(aux);
        aux = aux->next;
        j++;
    }
    return index;
}

//Take uses delnode as extra function to avoid reading troubles for the user
list delnode(list l){
    list temp = l;
    list prev;

    while (temp->next){
        prev = temp;
        temp = temp->next;
    }
 
   if (temp == l){
      l = NULL;
    }
    else{
        prev->next = NULL;
    }
    free(temp);

 return l;
}

list take(list l, int n){
    assert(n >= 0);
     
    if(n >= len(l)){
        return l;
    }
    int length =len(l);
    list aux = l;
    for (int i = 0; n+i < length; i++)
    {
        aux = delnode(aux);
    }
    
    
    return l;
}

list drop(list l, int n){
    
    for (int i = 0; i < n; i++){
       l = tail(l);
        
    }
  return l;
}
list concat(list l1, list l2){  
   /*DON'T USE concat(l,l), IT CREATES INFINITE LOOP */
   
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }

   else{ 
        list p = l2;
        while (p != NULL)
        {
            type_elem pelem = p->elem;
            l1 = addr(l1,pelem);
            p = p->next;
            
        }
        
    }
    return l1;
}

list copy(list l){
    list l_copy = empty(), l_temp = l;
    while (l_temp)
    {
        l_copy = addr(l_copy,l_temp->elem);
        l_temp = l_temp->next;
    }
    return l_copy;
}