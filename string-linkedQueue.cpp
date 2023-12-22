#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct node {
    string data;
    node* next;
};

node *head = NULL;
void push(string item);
void pop();
string getTop();
void printAll();

int main(){
    while (1){
		int cmd; string item;

		cout << "1. Insert node" << endl;
		cout << "2. Delete node" << endl;
		cout << "3. Display list" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> cmd;

		switch (cmd){
			case 1:
			    cout << "Item: ";
                cin >> item;
                push(item);
                break;
			case 2:
                pop();
                break;
			case 3:
			    printAll();
                break;
			case 4:
			    exit(0);
		}
	}

    return 0;
}

void push(string item) {
    node* newnode = (node*) malloc(sizeof(node));

    newnode->data = item;
	newnode->next = NULL;

	if (head != NULL){
        cout << 11 << endl;
        head->next = newnode; return;
	}

	node *p;
	p = head;
	cout << 12 << endl;
	head = newnode;
}

void pop() {
    //
}

void printAll(){
    node *p;
	p = head;

	if (p == NULL) cout << "List is empty!" << endl;

	while (p != NULL){
	   cout << p->data << ' ';
	   p = p->next;
	} cout << endl;
}
