#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    void* data;
    struct Node *next;
};
struct Queue {
    int size;
    struct Node *front,*rear;

};

struct Queue* initQueue() {
    struct Queue* q =  malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;


}
bool isEmpty(const struct Queue *queue) {
    return queue->front ==NULL;
}

struct Node* newNode(void* item) {
    struct Node* temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Error: Memory allocation for new node");
        return NULL;
    }
    temp->data = item;
    temp->next = NULL;
    return temp;
}
void enqueue(struct Queue* q, void* k) {
    if(k == NULL) {
        printf("Can't do that mate\n");
        return;
    }
    struct Node* temp = newNode(k);


    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

void* dequeue(struct Queue* q) {
    if (!isEmpty(q)) {
        struct Node *temp = q->front;
        void* data = temp->data;
        q->front = q->front->next;

        if (q->front == NULL)
            q->rear =NULL;
        free(temp);
        q->size--;
        return data;
    }
    printf("???");
    return NULL;
}
void* peek(const struct Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->front->data;
    }
    return NULL;

}

void freeQueue(struct Queue* queue) {
    if (queue == NULL) return;

    while (queue->front != NULL) {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;

        free(temp);
    }
    free(queue);
}




/*
int main() {
    struct Queue* q = initQueue();

    int* data1 = malloc(sizeof(int));
    *data1 = 10;
    enqueue(q, data1);

    int* data2 = malloc(sizeof(int));
    *data2 = 20;
    enqueue(q, data2);

    int* frontData = peek(q);
    if (frontData != NULL) {
        printf("Front element: %d\n", *frontData);
    }

    int* dequeuedData = dequeue(q);
    if (dequeuedData != NULL) {
        printf("Dequeued element: %d\n", *dequeuedData);
        free(dequeuedData); // Caller frees the data
    }

    freeQueue(q);
    return 0;
}
*/
