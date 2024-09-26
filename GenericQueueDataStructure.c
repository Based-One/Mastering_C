#define DEFINE_QUEUE(TYPE, TYPENAME)                                   \
    typedef struct Node_##TYPENAME {                                   \
        TYPE data;                                                     \
        struct Node_##TYPENAME* next;                                  \
    } Node_##TYPENAME;                                                 \
                                                                       \
    typedef struct Queue_##TYPENAME {                                  \
        int size;                                                      \
        Node_##TYPENAME* front;                                        \
        Node_##TYPENAME* rear;                                         \
    } Queue_##TYPENAME;                                                \
                                                                       \
    Queue_##TYPENAME* initQueue_##TYPENAME() {                         \
        Queue_##TYPENAME* q = malloc(sizeof(Queue_##TYPENAME));        \
        if (q == NULL) {                                               \
            fprintf(stderr, "Memory allocation failed\n");             \
            exit(EXIT_FAILURE);                                        \
        }                                                              \
        q->front = q->rear = NULL;                                     \
        q->size = 0;                                                   \
        return q;                                                      \
    }                                                                  \
                                                                       \
    bool isEmpty_##TYPENAME(Queue_##TYPENAME* queue) {                 \
        return queue->front == NULL;                                   \
    }                                                                  \
    Node_##TYPENAME* createNode_##TYPENAME(TYPE value) {               \
        Node_##TYPENAME* temp = malloc(sizeof(Node_##TYPENAME));       \
        if (temp == NULL) {                                            \
            fprintf(stderr, "Memory allocation failed\n");             \
            exit(EXIT_FAILURE);                                        \
        }                                                              \
        temp->data = value;                                            \
        temp->next = NULL;                                             \
        return temp;                                                   \
}                                                                      \
void enqueue_##TYPENAME(Queue_##TYPENAME* q, TYPE value) {             \
        Node_##TYPENAME* temp = createNode_##TYPE(value);              \
        if (q->front == NULL) {                                         \
            q->front = q->rear = temp;                                 \
        } else {                                                       \
            q->rear->next = temp;                                      \
            q->rear = temp;                                            \
        }                                                              \
        q->size++;                                                     \
    }                                                                  \
                                                                       \
    TYPE dequeue_##TYPENAME(Queue_##TYPENAME* q) {                     \
        if (isEmpty_##TYPENAME(q)) {                                   \
            fprintf(stderr, "Queue is empty\n");                       \
            exit(EXIT_FAILURE);                                        \
        }                                                              \
        Node_##TYPENAME* temp = q->front;                              \
        TYPE data = temp->data;                                        \
        q->front = q->front->next;                                     \
        if (q->front == NULL)                                          \
            q->rear = NULL;                                            \
        free(temp);                                                    \
        q->size--;                                                     \
        return data;                                                   \
    }                                                                  \
                                                                       \
    void freeQueue_##TYPENAME(Queue_##TYPENAME* q) {                   \
        while (!isEmpty_##TYPENAME(q)) {                               \
            dequeue_##TYPENAME(q);                                     \
        }                                                              \
        free(q);                                                       \
    }
