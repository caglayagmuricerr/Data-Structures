#include <stdio.h>
#include <stdlib.h>

// Linked List Node Structure
struct Node
{
    int data;
    struct Node *next;
};

// Create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the beginning of the list
void pushFront(struct Node **head, int data)
{
    struct Node *node = newNode(data);
    node->next = *head;
    *head = node;
}

// Function to delete a node with given value
void deleteNodeVal(struct Node **head, int value)
{
    struct Node *prev = NULL, *curr = *head;
    while (curr != NULL && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
        return;

    if (prev == NULL)
        *head = curr->next;
    else
        prev->next = curr->next;
    free(curr);
}

// Function to delete a node
// at a given position in a linked list
void deleteNode(struct Node** head_ref, int position)
{
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    struct Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        *head_ref = temp->next; // Change head
        free(temp); // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node* next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    temp->next = next; // Unlink the deleted node from list
}

// Function to add a new node at the beginning
// of a linked list
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // put in the data
    new_node->data = new_data;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print the Linked List
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver program
int main(void)
{
    struct Node *head = NULL;

    printf("Inserting values to the list 5,4,3,2,1 order.\n Because pushFront is used so we add numbers from largest to smallest.\n");
    pushFront(&head, 5);
    pushFront(&head, 4);
    pushFront(&head, 3);
    pushFront(&head, 2);
    pushFront(&head, 1);
    printList(head);

    printf("Deleting a node with value 4\n");
    deleteNodeVal(&head, 4);
    printList(head);

    printf("Deleting a node at index 3\n");
    deleteNode(&head, 3);
    printList(head);

    return 0;
}
