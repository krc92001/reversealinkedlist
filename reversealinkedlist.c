//README uncomment out line 34 to run the reverse function, list prints backwards by default.

#include <stdio.h>
#include<stdlib.h>
//defining the linked list structure
typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}node;

typedef struct header{
	struct node* first;
	int count;
	struct node* last;
}header;
header reverselist(header head); //reverses the linked list
node* createnode(int num); // creates and mallocs new nodes
header insertnode(header head, node* newptr); // inserts new nodes into list
int main(void)
{
	header head;
	head.first = NULL;
	head.count = 0;
	node* newptr, * curptr;
	int num=1;
	newptr = NULL;
	curptr = NULL;
	for (int i = 0; i < 4; i++) {
		newptr = createnode(num);
		head = insertnode(head, newptr);
		num++;
	}
	//head = reverselist(head);
	curptr = head.last;
	printf("data in list: ");
	while (curptr != NULL) {
		printf("%d ", curptr->data);
		curptr = curptr->prev;
	}
}

node* createnode(int num) {
	node* newptr;
	newptr = (node*)malloc(sizeof(node));
	if (newptr != NULL) {
		newptr->data=num; 
		newptr->next = NULL;
		return newptr;
	}
	else {
		printf("MEM ERROR");
		return NULL;
	}
}

header insertnode(header head, node* newptr)
{
	node* curptr;
	if (head.first == NULL) {
		head.first=newptr;
		head.first->prev = NULL;
		head.count++;
		printf("Node inserted there are now %d node(s)", head.count);
		return head;
	}
	else {
		curptr = head.first;
		while (curptr->next != NULL)
		{
			curptr = curptr->next;
		}
		newptr->prev = curptr;
		curptr->next = newptr;
		head.last = newptr;
		head.count++;
		printf("\nNode inserted there are now %d node(s)", head.count);
	}
	return head;
}


header reverselist(header head)
{
	int count = head.count - 1;
	node* curptr, *temp;
	node* newhead, *newtail;
	newhead = head.last; 
	newtail = head.first; 
	head.first = newhead;//sets new head
	head.last = newtail;//sets head as tail
	curptr = newtail; // starts at original head
	temp = curptr->next;// init temp with the second node
	while (temp != NULL) {
		temp = curptr->next; //sets temp as next node
		curptr->next = curptr->prev; //sets next node as the previous
		curptr->prev = temp; // sets prev to the old next aka "temp"
		curptr = temp; // starts at the next node

	}
	//loop breaks when it reaches the old tail "newhead "
	return head;
}
