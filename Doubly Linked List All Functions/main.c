#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node node;
node* head;

// Inserts a node at the head of the doubly linked list
void insertAtHead(int x)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}

void insertAtTail(int x)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    }

	node* temp1 = head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;
	temp->prev = temp1;
}


void deleteNode (int x){
    node* temp = head;
    while (temp != NULL && temp->data != x){
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Data not found in list\n");
        return;
    }
    if (temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    else{
        head = temp->next;
    }
    if (temp->next != NULL){
        temp->next->prev = temp->prev;
    }
        free(temp);
}

void print()
{
    node* temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("%d. eleman %d ", i, temp->data);
        temp = temp->next;
        i++;
        printf("\n");
    }
    printf("\n");
}

int main()
{
    head = NULL; // empty list
    insertAtTail(2);
    insertAtTail(4);
    insertAtTail(6);
    insertAtHead(1);
    print();
}
