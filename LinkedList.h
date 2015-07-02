/*
Project CStructure
Writen by Lostyear
Version 0.0.1
July 1 2015
*/

#ifndef   LINKED_LIST_H_INCLUDED
#define   LINKED_LIST_H_INCLUDED

typedef struct llNode{
  void *data;
  struct llNode *front;
  struct llNode *next;
}LinkedListNode;

typedef struct llist{
  LinkedListNode *head;
  LinkedListNode *tail;
  unsigned long length;
}LinkedList;


//Run this function Before you use the Linked List
void LinkedListInitialize(LinkedList *list);
//O(1)
_Bool LinkedListIsEmpty(LinkedList *list);

//O(1) Operation
LinkedListNode *LinkedListAddFirst  (LinkedList *list, void *value);
LinkedListNode *LinkedListAddLast   (LinkedList *list, void *value);
LinkedListNode *LinkedListAddAfter  (LinkedList *list, LinkedListNode *node, void *value);
LinkedListNode *LinkedListAddBefore (LinkedList *list, LinkedListNode *node, void *value);

//O(n)
void LinkedListClear       (LinkedList *list);
_Bool LinkedListRemove      (LinkedList *list, LinkedListNode *node);
//O(1)
void LinkedListRemoveFirst (LinkedList *list);
void LinkedListRemoveLast  (LinkedList *list);

//O(n)
_Bool LinkedListContains   (LinkedList *list, void *value);
LinkedListNode *LinkedListFind       (LinkedList *list, void *value);
LinkedListNode *LinkedListFindLast   (LinkedList *list, void *value);
//LinkedListNode *LinkedListCopyTo     (LinkedList *list, void *value);

#endif
