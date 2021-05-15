#define _CRT_SECURE_NO_WARNINGS_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "singlyLinkedList.h"

//creating an empty singly linked list
ListT* createEmptySLL() {
	ListT* listPtr = (ListT*)malloc(sizeof(ListT));
	if (listPtr) {
		listPtr->count = 0;
		listPtr->first = listPtr->last = NULL;
	}
	return listPtr;
}

//creating a node and filling it with data
NodeT* createSLLNode(int key) {
	NodeT* p = (NodeT*)malloc(sizeof(NodeT));
	if (p) {
		p->key = key;
		p->next = NULL;
	}
	return p;
}

//checking whether a list is empty or not
bool isEmpty(ListT* listPtr) {
	if (listPtr->count == 0 && listPtr->first == listPtr->last && listPtr->first == NULL)
		return false;
	return true;
}

//inserting a node at the front of the singly linked list
int insertAtFront(ListT* listPtr, NodeT* p) {
	if (listPtr) {
		p->next = listPtr->first;
		if (isEmpty(listPtr)) {
			listPtr->last = p;
		}
		listPtr->first = p;
		listPtr->count++;
		return 1;
	}
	return 0;
}

//inserting a node at the rear of the singly linked list
int insertAtRear(ListT* listPtr, NodeT* p) {
	if (listPtr) {
		if (isEmpty(listPtr)) {
			listPtr->first = p;
		}
		else {
			listPtr->last->next = p;
		}
		listPtr->last = p;
		listPtr->count++;
		return 1;
	}
	return 0;
}

//insertion before a node given by its key
NodeT* insertBeforeNodeGivenByKey(ListT* listPtr, NodeT* p, int givenKey) {
	NodeT* q, * q1;
	q1 = NULL;
	q = listPtr->first;

	while (q != NULL) {
		if (q->key == givenKey)
			break;
		q1 = q;
		q = q->next;
	}

	if (q != NULL) {
		if (q == listPtr->first) {
			p->next = listPtr->first;
			listPtr->first = p;
		}
		else {
			q1->next = p;
			p->next = q;
		}
		listPtr->count++;
	}

	return q;
}

//insertion after a node given by its key
void insertAfterNodeGivenBy(ListT* listPtr, NodeT* p, int givenKey) {
	NodeT* q, * q1;
	q1 = NULL;
	q = listPtr->first;

	while (q != NULL) {
		if (q->key == givenKey)
			break;
		q1 = q;
		q = q->next;
	}

	if (q != NULL) {
		p->next = q->next;
		q->next = p;
		if (q == listPtr->last)
			listPtr->last = p;
		listPtr->count++;
	}
}

//finding a node of a singly-linked list
NodeT* find(ListT* listPtr, int givenKey) {
	NodeT* p;
	p = listPtr->first;

	while (p != NULL)
		if (p->key == givenKey) {
			return p;
		}
		else
			p = p->next;

	return NULL;
}

//removing the first node of a singly-linked list
NodeT* deleteFirst(ListT* listPtr) {
	NodeT* p;
	if (listPtr->first != NULL) {
		p = listPtr->first = listPtr->first->next;
		listPtr->count--;

		if (listPtr->first == NULL) {
			listPtr->last = NULL;
		}
		return p;
	}
	return NULL;
}

//removing the last node of a singly-linked list
NodeT* deleteLast(ListT* listPtr) {
	NodeT* q, * q1;
	q1 = NULL;
	q = listPtr->first;

	if (q != NULL) {
		while (q != listPtr->last) {
			q1 = q;
			q = q->next;
		}

		if (q == listPtr->first) {
			listPtr->first = listPtr->last = NULL;
		}
		else {
			q1->next = NULL;
			listPtr->last = q1;
		}
	}

	return q;
}

//removing a node given by a key
int deleteByKey(ListT* listPtr, int givenKey) {
	NodeT* q, * q1;
	q1 = NULL;
	q = listPtr->first;

	while (q != NULL) {
		if (q->key == givenKey)
			break;
		q1 = q;
		q = q->next;
	}
	if (q != NULL) {
		if (q == listPtr->first) {
			listPtr->first = listPtr->first->next;
			free(q);
		}
		return 1;
	}
	return 0;
}

//purging a singly-linked list 
void purge(ListT* listPtr) {
	NodeT* p;
	while (listPtr->first != NULL) {
		p = listPtr->first;
		listPtr->first = listPtr->first->next;
		free(p);
	}
	listPtr->last = NULL;
	listPtr->count = 0;
}

//printing a singly-linked list
void printList(ListT* listPtr) {
	NodeT* p;
	p = listPtr->first;

	if (listPtr) {
		while (p != NULL) {
			printf("%d ", p->key);
			p = p->next;
		}
	}
}