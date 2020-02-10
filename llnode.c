#include "llnode.h"
#define NULL 0
#include<stdlib.h>
#include<stdio.h>
struct llnode {
	int payload;
	struct llnode * next;
};

/* Add code for methods here */

node newNode(int value){
	node n = (node) malloc(sizeof(struct llnode));	//node
	n->payload = value;
	n->next=NULL;
	return n;
}
node addToHead(node head,int value){
	node n = newNode(value);
	n->next=head;
	return n;
}
void printList(node head){
	printf("Head@%p ",head);
	while(head!=NULL) {
   		printf(" -> %d",head->payload);
		head = head->next;
	}
	printf("\n");

}
int listSize(node head){
  		if (head==NULL) return 0;
			return 1+listSize(head->next);
}
void freeList(node head){
	if (head==NULL) return;
		freeList(head->next);
		free(head);


}
node addToTail(node head,int value){
	node n = newNode(value);
	if(head == NULL){return n;}
	node temp = head;
	while(temp->next != NULL){temp=temp->next;}
	temp->next = n;
	return head;


}
node addIncreasing(node head,int value){

	node n = newNode(value);
	node temp = head;

	if(head == NULL){return n;}
	if(temp->payload > value){
		n->next=head;
		return n;
	}
	if(temp->payload < value){
		temp=temp->next;
	}
	n->next=temp->next;
	temp->next = n;
	return head;

}
