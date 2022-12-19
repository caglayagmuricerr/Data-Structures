#include<stdio.h>
#include<stdlib.h>

// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

// Head of the linked list
struct Node* head = NULL;

// Function to add a new node at the beginning
void pushFront(int new_data)
{
	// Allocate memory for a new node and store data
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;

	// Link the new node to the head
	new_node->next = head;
	head = new_node;
}

// Function to add a new node at the end
void pushBack(int new_data)
{
	// Allocate memory for a new node and store data
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;

	// Link the new node to the end
	new_node->next = NULL;

	// If the list is empty, make new_node as the head
	if(head == NULL)
	{
		head = new_node;
		return;
	}

	// Else traverse to the last node
	struct Node* last = head;
	while(last->next != NULL)
		last = last->next;

	// Change the next of the last node
	last->next = new_node;
	return;
}

// Function to add a new node after a certain node
void insertAfter(struct Node* prev_node, int new_data)
{
	// Check if the given node is NULL
	if (prev_node == NULL)
	{
		printf("The given node cannot be NULL");
		return;
	}

	// Allocate memory for a new node and store data
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;

	// Link the new node to the next of the prev_node
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// Function to print the linked list
void printList()
{
	struct Node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

// Driver code
int main()
{
	// Start with an empty list
	head = NULL;

	printf("Insert 6 So linked list becomes 6->NULL\n");
	pushBack(6);
    printList();
    printf("\n");

	printf("Insert 7 at the beginning. So linked list becomes 7->6->NULL\n");
	pushFront(7);
    printList();
    printf("\n");

	printf("Insert 1 at the beginning. So linked list becomes 1->7->6->NULL\n");
	pushFront(1);
    printList();
    printf("\n");

	printf("Insert 4 at the end. So linked list becomes 1->7->6->4->NULL\n");
	pushBack(4);
    printList();
    printf("\n");

	printf("Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL\n");
	insertAfter(head->next, 8);
    printList();
    printf("\n");

	printf("Created Linked List: ");
	printList();

	return 0;
}
