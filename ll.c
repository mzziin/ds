#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int data;
};

struct node *temp, *new, *head;

void create();
void add_begin();
void add_end();
void add_position();
void remove_begin();
void remove_position();
void remove_end();
void display();

void main(){
	int choice;
	while (1){
		printf("Enter choice: \n1)add at begin\n2)add at position\n3)add at end\n4)remove at begin\n5)remove at position\n6)remove at end\n7)create\n8)display\n");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				add_begin();
				break;
			case 2:
				add_position();
				break;
			case 3:
				add_end();
				break;
			case 4:
				remove_begin();
				break;
			case 5:
				remove_position();
				break;
			case 6:
				remove_end();
				break;
			case 7:
				create();
				break;
			case 8:
				display();
				break;
			default:
				exit(1);
		}
	}
}

void create(){
	int c;
	temp=head;
	do{
		new = (struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d", &new->data);
		new->next = NULL;
		if(head == NULL){
			head = new;
			temp = head;
		}
		else{
			temp->next = new;
			temp = temp->next;
		}
		printf("want to add new node (1/0)? ");
		scanf("%d", &c);
	}while(c != 0);
}

void add_begin(){
	int dat;
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &dat);
	new->data = dat;
	new->next = head;  // always update
	head = new;
}


void add_end(){
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &new->data);
	new->next = NULL;

	if(head == NULL){
		head = new;
		return;
	}
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;

	temp->next = new;
}


void add_position(){
	int pos;
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &new->data);
	new->next = NULL;
	printf("enter position data: ");
	scanf("%d", &pos);
	
	if(head == NULL)
		head = new;
	else{
		temp = head;
		while(temp->data != pos){
			temp=temp->next;
		}
		
		new->next = temp->next;
		temp->next = new;
	}
}

void remove_begin(){
	if (head == NULL) {
	    printf("List is empty\n");
	    return;
	}
	temp = head;
	head = temp->next;
	free(temp);
	temp = NULL;
}

void remove_end(){
	struct node *prev;
	
	if (head == NULL) {
	    printf("List is empty\n");
	}else if(head->next == NULL){
		free(head);
		head=NULL;
	}else{
		temp = head;
		while(temp->next != NULL){
			prev = temp;
			temp=temp->next;
		}
		prev->next=NULL;
		free(temp);
		temp=NULL;
	}
}

void remove_position(){
	struct node *prev;
	
	int pos;
	printf("Enter position");
	scanf("%d", &pos);
	
	if(head == NULL)
		printf("empty");
	else if(head->data == pos){
		prev = head;
		head = head->next;
		free(prev);
		prev = NULL;
	}else{
		temp = head;
		while (temp->data != pos){
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		free(temp);
		temp=NULL;
	}
}

void display(){
	temp=head;
	while(temp != NULL){
		printf("%d ->", temp->data);
		temp=temp->next;
	}
}











