#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
	struct node *prev;
};
struct node *head;

struct node* createNode();
void Display();

void InsertAtBegin();
void InsertAtEnd();
void InsertAtPosition();

void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition();

void main(){
	int choice;
	while (1) {
		printf("1)Insert at begin\n2)Insert at end\n3)Insert at position\n4)Delete at begin\n5)Delete at end\n6)Delete at position\n7)Display\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				InsertAtBegin();
				break;
			case 2:
				InsertAtEnd();
				break;
			case 3:
				InsertAtPosition();
				break;
			case 4:
				DeleteAtBegin();
				break;
			case 5:
				DeleteAtEnd();
				break;
			case 6:
				DeleteAtPosition();
				break;
			case 7:
				Display();
				break;
			default:
				exit(1);
				
		}	
	}
}


struct node* CreateNode(int value){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->next=NULL;
	newNode->prev=NULL;
	newNode->value=value;
	return newNode;
}


void InsertAtBegin(){
	int value;
	printf("Enter a number to insert: ");
	scanf("%d", &value);
	struct node* newNode = CreateNode(value);
	
	if(head == NULL)
		head = newNode;
	else{
		newNode->next = head;
		newNode->next->prev = newNode;
		head = newNode;
	}
	printf("\nInserted %d at beginning\n", value);
}

void InsertAtEnd(){
	int value;
	printf("Enter a number to insert: ");
	scanf("%d", &value);
	struct node* newNode = CreateNode(value);
	
	if(head == NULL)
		head = newNode;
	else{
		struct node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		newNode->prev = temp;
		temp->next = newNode;
		printf("\nInserted %d at end", value);
	}
}

void InsertAtPosition(){
	int value, key;
	printf("Enter a number to insert: ");
	scanf("%d", &value);
	struct node* newNode = CreateNode(value);
	printf("Enter the data at position to insert: ");
	scanf("%d", &key);
	
	if(head == NULL)
		head = newNode;
	else{
		struct node* temp = head;
		while (temp->value != key){
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;
	}
	printf("\nInserted %d at position %d\n", value, key);
}

void DeleteAtBegin(){
    if(head == NULL)
        return;

    struct node* temp = head;

    if(head->next == NULL){ 
        head = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
    printf("Deleted node from beginning\n");
}


void DeleteAtEnd(){
	if(head == NULL)
		return;
	
	if(head->next == NULL){
		free(head);
		head=NULL;
	}
	else{
		struct node* temp = head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->prev->next = NULL;
		free(temp);
		temp=NULL;
	}
	printf("Deleted node from end\n");
}

void DeleteAtPosition(){
	if(head == NULL)
		return;
	
	int value;
	printf("Enter a value to delete: ");
	scanf("%d", &value);
	
	struct node* temp = head;
	if(head->value == value){
		if(head->next == NULL){
			free(head);
			head=NULL;
		}else{
			head = temp->next;
			head->prev = NULL;
			free(temp);
			temp=NULL;
		}
	}else{
		while(temp != NULL && temp->value != value){
			temp = temp->next;
		}

		if(temp == NULL){
			printf("Value not found!\n");
			return;
		}
		
		if(temp->next == NULL){
		    temp->prev->next = NULL;
		    free(temp);
		} 
		else{
		    // Case 3: deleting middle node
		    temp->prev->next = temp->next;
		    temp->next->prev = temp->prev;
		    free(temp);
		}
	}
	printf("Deleted node %d\n", value);
}

void Display(){
    struct node* temp = head;
    while(temp != NULL){
        printf("<- %d -> ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}






