#include <stdio.h>

#include <stdlib.h>


typedef struct Node {

int data;

struct Node* prev;

struct Node* next;

} Node;

Node* createNode(int value) {

Node* newNode = (Node*)malloc(sizeof(Node));

newNode->data = value;
newNode->prev = NULL;

newNode->next = NULL;

return newNode;

}


void displayList(Node* head) {

Node* temp = head;

printf("\nDoubly Linked List Structure:\n");

printf("-------------------------------------------------------------\n");

printf("| %-10s | %-10s | %-5s | %-10s |\n", "Node Addr", "Prev Addr", "Data", "Next Addr");

printf("-------------------------------------------------------------\n");

while (temp != NULL) {

printf("| %-10p | %-10p | %-5d | %-10p |\n",

      (void*)temp,

      (void*)temp->prev,

      temp->data,

      (void*)temp->next);

temp = temp->next;

}

printf("-------------------------------------------------------------\n");

}


void search_next(Node *head, int data) {
if (!head) {
printf("Empty list.\n");
return;
}

Node *current = head;
int i = 0, flag = 0;

while (current != NULL) {
if (current->data == data) {
flag = 1;
break;
}
current = current->next;
i++;
}

if (!flag) {
printf("Data not found\n");
} else
printf("%d found at index %d\n", current->data, i);
}

void search_prev(Node *head, int data) {
    if (!head) {
printf("Empty list.\n");
return;
}

Node *current = head;
int i = 0, flag = 0;

while (current->next != NULL){
   current = current->next;
}

while (current != NULL) {
if (current->data == data) {
flag = 1;
break;
}
current = current->prev;
i++;
}

if (!flag) {
printf("Data not found\n");
} else
printf("%d found at index %d\n", current->data, i);
}


int main() {



Node* N1 = createNode(1);

Node* N2 = createNode(2);

Node* N3 = createNode(3);

Node* N4 = createNode(4);

Node* N5 = createNode(5);

N1->next = N2;

N2->prev = N1;

N2->next = N3;

N3->prev = N2;

N3->next = N4;

N4->prev = N3;

N4->next = N5;

N5->prev = N4;


displayList(N1);

int choice, data;
printf("Search type\n1. Next\n2. Prev\nEnter Choice: ");
scanf("%d", &choice);
printf("Search Data: ");
scanf("%d", &data);

switch (choice) {
case 1:
search_next(N1, data);
break;

case 2:
search_prev(N5, data);
break;

default:
printf("Invalid Input\n");
break;
}



free(N1);

free(N2);

free(N3);

free(N4);

free(N5);

return 0;
}
