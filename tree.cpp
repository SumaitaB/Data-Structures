#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data ;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data){
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
};

void insert_node(struct node *root, int n1, int n2, char lr){
    if (root == NULL) return;

    if (root->data == n1){
        switch (lr){
            case 'l':
                root -> left = newnode(n2);
                break;
            case 'r':
                root -> right = newnode(n2);
                break;
        }
    }

    else{
        insert_node(root->left, n1, n2, lr);
        insert_node(root->right, n1, n2, lr);
    }
}

void inorder(struct node *root){
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(struct node *root){
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    struct node *root = NULL;
    int n;

    cout << "\nEnter the number of edges : ";
    cin >> n;
    cout << "\nInput the nodes of the binary tree in order\n";
    cout << "Parent - Node - l if Left / r if Right\n\n";

    while(n--){
        char lr;
        int n1, n2;
        cin >> n1 >> n2 >> lr;

        if (root == NULL){
            root = newnode(n1);

            switch(lr){
                case 'l':
                    root -> left = newnode(n2);
                    break;
                case 'r':
                    root -> right = newnode(n2);
                    break;
                }
        }
        else insert_node(root, n1, n2, lr);
    }

    cout << "\nINORDER TRAVERSAL : ";
    inorder(root);
    cout << "\n\nPREORDER TRAVERSAL : ";
    preorder(root);
    cout << "\n\nPOSTORDER TRAVERSAL : ";
    postorder(root);
    cout << endl;

    return 0;
}

