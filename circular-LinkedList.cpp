#include <cstdio>
#include <cstdlib>

struct Node{
    int data;
    Node *next;
};

void push(Node **head_ref, int data){
    Node *ptr1 = (Node *)malloc(sizeof(Node));
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL){
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }

    else ptr1->next = ptr1;

    *head_ref = ptr1;
}

void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void printList(Node *head){
    Node *temp = head;
    if (head != NULL){
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}

int main(){
    Node *head = NULL;

    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    printf("Contents of Circular Linked List\n ");
    printList(head);

    return 0;
}
