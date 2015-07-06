/*
Project CStructure
Writen by Lostyear
Version 0.0.1
July 1 2015
*/

#include <stdbool.h>
#include <stdlib.h>

#include "LinkedList.h"

//TODO: All these functions do NOT consider the list is null or not initialized

void LinkedListInitialize(LinkedList *list) {
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}

//O(1)
_Bool LinkedListIsEmpty(LinkedList *list) {
	if (list->head == NULL || list->tail == NULL)
		return true;
	else
		return false;
}

//O(1) Operation
LinkedListNode *LinkedListAddFirst(LinkedList *list, void *value) {
	LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	newNode->front = NULL;
	list->head = newNode;
	newNode->next = list->head;
	newNode->data = value;
	list->length++;
	if (list->tail == NULL) {
		list->tail = newNode;
	}

	return newNode;
}
LinkedListNode *LinkedListAddLast(LinkedList *list, void *value) {
	LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	newNode->next = NULL;
	newNode->front = list->tail;
	list->tail = newNode;
	newNode->data = value;
	list->length++;
	if (list->head == NULL) {
		list->head = newNode;
	}

	return newNode;
}


//TODO: This two add function Does NOT consider the node provided is the head or tail
LinkedListNode *LinkedListAddAfter(LinkedList *list, LinkedListNode *node, void *value) {
	LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	newNode->front = node;
	newNode->next = node->next;
	newNode->next->front = newNode;
	node->next = newNode;

	return newNode;
}
LinkedListNode *LinkedListAddBefore(LinkedList *list, LinkedListNode *node, void *value) {
	LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	newNode->next = node;
	newNode->front = node->front;
	newNode->front->next = newNode;
	node->front = newNode;

	return newNode;
}

//O(n)
void LinkedListClear(LinkedList *list) {
	LinkedListNode *p = list->head;
	LinkedListNode *q = NULL;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
}

_Bool LinkedListRemove(LinkedList *list, LinkedListNode *node) {
	//TODO: What if this node not in this List?
	node->next->front = node->front;
	node->front->next = node->next;

	return true;
}
//O(1)
void LinkedListRemoveFirst(LinkedList *list) {
	if (list->head == NULL)
		return;

	LinkedListNode *p = list->head;
	list->head = p->next;
	if (list->head == NULL) {
		list->tail = NULL;
	}

	free(p);
}
void LinkedListRemoveLast(LinkedList *list) {
	if (list->tail == NULL)
		return;

	LinkedListNode *p = list->tail;
	list->tail = p->front;
	if (list->tail == NULL) {
		list->head = NULL;
	}

	free(p);
}

//TODO: find a way that can conpare the real value, not just address
//O(n)
_Bool LinkedListContains(LinkedList *list, void *value) {
	LinkedListNode *p = list->head;
	while (p) {
		if (p->data == value) 
			return true;
		
		p = p->next;
	}
	return false;
}
LinkedListNode *LinkedListFind(LinkedList *list, void *value) {
	LinkedListNode *p = list->head;
	while (p) {
		if (p->data == value)
			return p;

		p = p->next;
	}
	return p;
}
LinkedListNode *LinkedListFindLast(LinkedList *list, void *value) {
	LinkedListNode *p = list->tail;
	while (p) {
		if (p->data == value)
			return p;

		p = p->front;
	}

	return p;
}
LinkedListNode *LinkedListCopyTo(LinkedList *list, void *value);
