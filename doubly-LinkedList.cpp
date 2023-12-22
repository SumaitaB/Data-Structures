#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

void push_back(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void insertBefore(Node** head_ref, Node* next_node, int new_data){
    if (next_node == NULL) {
        printf("The next node cannot be NULL");
        return;
    }

    Node* new_node = (struct Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    new_node->next = next_node;

    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else (*head_ref) = new_node;

}

void insertAfter(Node* prev_node, int new_data){
    if (prev_node == NULL) {
        printf("The previous node cannot be NULL");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));

    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;

    return;
}

void deleteNode(Node** head_ref, Node* del) {  
    if (*head_ref == NULL || del == NULL)  
        return;  
  
    if (*head_ref == del)  
        *head_ref = del->next;  
  
    if (del->next != NULL)  
        del->next->prev = del->prev;  
  
    if (del->prev != NULL)  
        del->prev->next = del->next;  
  
    free(del);  
    return;  
}  

void display(Node* node){
    Node* last;
    printf("\nTraversal in forward direction:\n");

    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
}

int main(){
    Node* head = NULL;

    append(&head, 6);
    push_back(&head, 7);
    push_back(&head, 1);
    append(&head, 4);
    insertBefore(&head, head->next, 8);
    insertAfter(head->next, 8);

    printf("Created doubly linked list is:\n");
    display(head);

    getchar();
    return 0;
}
