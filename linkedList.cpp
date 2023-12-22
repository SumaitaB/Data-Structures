#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void insertAfter(Node* prev_node, int new_data){
    if (prev_node == NULL){
       printf("the given previous node cannot be NULL");
       return;
    }

    Node* new_node =(Node*) malloc(sizeof(Node));

    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteNode(struct Node **head_ref, int position) {
   if (*head_ref == NULL)
      return;

   struct Node* temp = *head_ref;

    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    if (temp == NULL || temp->next == NULL)
         return;

    struct Node *next = temp->next->next;

    free(temp->next);
    temp->next = next;
}

void printList(Node *n){
   while (n != NULL){
        printf(" %d ", n->data);
        n = n->next;
   }
}

void menu(void){

	while (1){
		int ch, item;

        system("cls");

		printf("\n");
		puts("1. Insert node:");
		puts("2. Delete node:");
		puts("3. Display list:");
		puts("4. Exit");

		printf("\nChoice (1,2,3,4) :: ");
		scanf("%d", &ch);

		switch (ch){
			case 1:
			    printf("\n Item = ");
                scanf("%d", &item);
                start = insfirst(start, item);
                break;
			case 2:
			    printf("\nItem = ");
                scanf("%d", &item);
                start = deleteNode(start, item);
                break;
			case 3:
			    printList(start);
                break;
			case 4:
			    exit(0);
		}
	}
}

int main(){
	menu();
	return(0);
}
