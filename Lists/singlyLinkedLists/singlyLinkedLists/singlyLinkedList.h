#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int key;
	struct node* next;
}NodeT;

typedef struct {
	int count;
	NodeT* first;
	NodeT* last;
}ListT;


ListT* createEmptySLL();
NodeT* createSLLNode(int key);

bool isEmpty(ListT* listPtr);

int insertAtFront(ListT* listPtr, NodeT* p);
int insertAtRear(ListT* listPtr, NodeT* p);
NodeT* insertBeforeNodeGivenByKey(ListT* listPtr, NodeT* p, int givenKey);
void insertAfterNodeGivenBy(ListT* listPtr, NodeT* p, int givenKey);

NodeT* find(ListT* listPtr, int givenKey);

NodeT* deleteFirst(ListT* listPtr);
NodeT* deleteLast(ListT* listPtr);
int deleteByKey(ListT* listPtr, int givenKey);

void purge(ListT* listPtr);

void printList(ListT* listPtr);