#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

ListNode *listNode_create(data_t data) {
    ListNode *ln = (ListNode*)malloc(sizeof(ListNode));
    ln->data = data;
    ln->next = ln->prev = NULL;
    return ln;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    ListNode *newLast = listNode_create(item_data);
    if (list_count(list)==0)
    {
        list->first=newLast;
    }
    else
    {
        ListNode *formerLast = list->last;
        formerLast->next=newLast;
        newLast->prev=formerLast;
    }
    list->last=newLast;
}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {
    if (list_count(list)==0)
    {
        return -1;
    }
    else
    {
        ListNode *formerLast = list->last;
        data_t data = formerLast->data;
        list->last = formerLast->prev;
        if (formerLast->prev==NULL)
        {
            list->first=NULL;
        }
        else
        {
            (formerLast->prev)->next=NULL;
        }
        free(formerLast);
        return data;
    }
}

void list_print(List *list){
    ListNode *node = list->first;
    while (node!=NULL)
    {
        printf("%i, ", node->data);
        node = node->next;
    }
    printf("\n");
}


int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);
    list_print(l);
    assert(t==40);

    t =  list_rmlast(l);
    list_print(l);
    assert(t==30);

    t =  list_rmlast(l);
    list_print(l);
    assert(t==20);

    t =  list_rmlast(l);
    list_print(l);
    assert(t==10);
    
    t =  list_rmlast(l);
    assert(t==-1);
    list_print(l);

    return 0;
}