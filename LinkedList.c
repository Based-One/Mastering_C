#include <stdio.h>
#include <stdlib.h>

struct Node {
    void* data;
    struct Node *next;
};

struct LinkedList {
    int size;
    struct Node *head;
};

struct LinkedList* initLinkedList() {
    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    if (list == NULL) {
        printf("Error: Memory allocation for linked list failed\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

bool isEmpty(const struct LinkedList *list) {
    return list->head == NULL;
}

struct Node* newNode(void* data) {
    struct Node* temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Error: Memory allocation for new node failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertAtBeginning(struct LinkedList* list, void* data) {
    if (data == NULL) {
        printf("Error: Data is NULL\n");
        return;
    }
    struct Node* temp = newNode(data);
    temp->next = list->head;
    list->head = temp;
    list->size++;
}

void insertAtEnd(struct LinkedList* list, void* data) {
    if (data == NULL) {
        printf("Error: Data is NULL\n");
        return;
    }
    struct Node* temp = newNode(data);
    if (list->head == NULL) {
        list->head = temp;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL)
            current = current->next;
        current->next = temp;
    }
    list->size++;
}

void deleteNode(struct LinkedList* list, void* data) {
    if (isEmpty(list)) {
        printf("Error: List is empty\n");
        return;
    }
    struct Node* current = list->head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Data not found in list\n");
        return;
    }
    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    list->size--;
}

void* search(const struct LinkedList* list, int index) {
    int counter = 0;
    struct Node* current = list->head;
    while (counter<index) {
        current = current->next;
        counter++;
    }
    return current->data;;
}

void displayLinkedList(const struct LinkedList* list, void (*printData)(void*)) {
    struct Node* current = list->head;
    while (current != NULL) {
        printData(current->data);
        current = current->next;
    }
    printf("\n");
}

void freeLinkedList(struct LinkedList* list) {
    if (list == NULL) return;
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
