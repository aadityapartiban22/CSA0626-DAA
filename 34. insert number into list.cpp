#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertNumber(struct Node* head, int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int num, listSize, element;

    printf("Enter the size of the list: ");
    scanf("%d", &listSize);

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < listSize; i++) {
        scanf("%d", &num);
        head = insertNumber(head, num);
    }

    printf("Enter the number to insert into the list: ");
    scanf("%d", &element);

    head = insertNumber(head, element);

    printf("Updated List: ");
    displayList(head);

    return 0;
}

