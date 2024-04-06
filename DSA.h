#ifndef DSA
#include "stdio.h"
#include "stdlib.h"
#define STACK_SIZE 100

struct LL{
    int data;
    struct LL* next;
};

struct LL* createLLNode(int data) {
    struct LL* newNode = (struct LL*)malloc(sizeof(struct LL));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct LL** headRef, int data) {
    struct LL* newNode = createLLNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertAfter(struct LL* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct LL* newNode = createLLNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteNode(struct LL** headRef, int data) {
    struct LL* temp = *headRef, *prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    if (prev == NULL) {
        *headRef = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void printList(struct LL* head) {
    struct LL* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct DLL{
 int data;
 struct DLL* next;
 struct DLL* prev;
};

struct DLL* CreateDLLNode(int NodeData){
 struct DLL* newNode = (struct DLL*)malloc(sizeof(struct DLL));
 newNode->data = NodeData;
 newNode->next = NULL;
 newNode->prev = NULL;
 return newNode;
}

void insertDLLAtBeginning(struct DLL** head, int NodeData){
 struct DLL* newNode = CreateDLLNode(NodeData);
 newNode->next = *head;
 if(*head != NULL){
  (*head)->prev = newNode;
 }
 *head = newNode;
}

void insertDLLAfter(struct DLL* prevNode, int data) {
 if (prevNode == NULL) {
  printf("previous node cannot be null");
  return;
  }

 struct DLL* newNode = CreateDLLNode(data);
  newNode->next = prevNode->next;
  prevNode->next = newNode;
  newNode->prev = prevNode;

 if (newNode->next != NULL){
  newNode->next->prev = newNode;
  }
}

void insertDLLEnd(struct DLL** head, int data) {
 struct DLL* newNode = CreateDLLNode(data);
 struct DLL* temp = *head;
 if (*head == NULL) {
  newNode->prev = NULL;
  *head = newNode;
  return;
  }
 while (temp->next != NULL)
  temp = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
}

void deleteDLLNode(struct DLL** head, struct DLL* del_node) {
    if (*head == NULL || del_node == NULL)
        return;

    if (*head == del_node)
        *head = del_node->next;

    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;

    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;

    free(del_node);
}

void displayDLLForward(struct DLL* node) {
    struct DLL* last;

    while (node != NULL) {
        printf("%d->", node->data);
        last = node;
        node = node->next;
    }
    if (node == NULL)
        printf("NULL\n");
}

void displayDLLBackward(struct DLL* node) {
    if (node == NULL) { 
        printf("NULL\n");
        return;
    }

    while (node->next != NULL) {
        node = node->next;
    }

    while (node != NULL) {
        printf("%d->", node->data);
        node = node->prev;
    }
    printf("NULL\n");
}

struct Stack{
    int items[STACK_SIZE];
    int top;
};

void StackInit(struct Stack* stack){
    stack->top = -1;   
};

int isEmpty(struct Stack *stack){
    return(stack->top==-1);
}

int isFull(struct Stack *stack){
    return (stack->top == STACK_SIZE-1);
}

void push(struct Stack *stack, int value){
    if(isFull(stack)){
        printf("Stack is full!\n");
        exit(1);
    }
    else{
        stack->items[++stack->top]=value;
        printf("Value %d has been added.\n", value);
    }
}

int pop(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty :(\n");
        exit(1);
    }
    else{
        printf("Top item %d has been removed from the stack.\n",stack->items[stack->top]);
        return stack->items[stack->top--];
    }
}

int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is Empty.\n");
        return -1;
    }
    else{
        return stack->items[stack->top];
    }
}

//Stack with Linked Lists

struct StackLL{
    struct LL* top;
};

void StackLLinit(struct StackLL* stack){
    stack->top = NULL;
}

void StackPush(struct StackLL* stack, int data){
    struct LL* newNode = (struct LL*)malloc(sizeof(struct LL));
    if(newNode==NULL){
        printf("Memory allocation for a linked list failed!\n");
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("New LL node pushed!");
}

int isLLEmpty(struct StackLL* stack){
    return (stack->top == NULL);
}

int Stackpeek(struct StackLL* stack){
    if(isLLEmpty(stack)){
        printf("Stacked Linked Lists is full\n");
        return 1;
    }
    else{
        return stack->top->data;
    }
}

struct TreeNode{
   int data;
   struct TreeNode* left;
   struct TreeNode* right;
};

struct TreeNode* createNewTNode(int data){

   struct TreeNode* NewTNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
   if(NewTNode == NULL){
       printf("Malloc Failed!\n");
       exit(1);
   }
   NewTNode->data = data;
   NewTNode->left = NULL;
   NewTNode->right = NULL;
   return NewTNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int data){

   if(root == NULL){
       root = createNewTNode(data);

   } 
   else if(data < root->data){
       root->left = insertNode(root->left,data);
   }

   else{
       root->right = insertNode(root->right,data);
   }

   return root;
}

void inorder(struct TreeNode* root){

   if(root != NULL){
       inorder(root->left);
       printf("%d-",root->data);
       inorder(root->right);
   }

}

struct TreeNode* findMin(struct TreeNode* root){
   while (root->left != NULL){
       root = root->left;
   }
   return root;
}

struct TreeNode* deleteTNode(struct TreeNode* root, int data){

   if(root==NULL){
       return root;
   }

   if(data<root->data){

       root->left = deleteNode(root->left,data);
   } else if(data>root->data){
      root->right = deleteNode(root->right,data);
   } else{

       if(root->left == NULL){
           struct TreeNode* temp = root->right;
           free(root);
           return temp;
       } else if(root->right == NULL){
           struct TreeNode* temp = root->left;
           free(root);
           return temp;
       }

       struct TreeNode* temp = findMin(root->right);

       root->data = temp->data;

       root->right = deleteNode(root->right,temp->data);

   }
   




#endif
