#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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

#define MAX_RUNWAYS 3
#define
DEFINE_QUEUE(int, int)

typedef struct {
    int id;
    double arrival_time;
    double service_time;
} Aeroplane;

typedef struct {
    bool occupied;
    int busy_until;
    int idAeroplane;
} RunWay;

double exponential(double mean) {
    double u = rand() / (double) RAND_MAX;
    return -mean * log(1 - u);
}

DEFINE_QUEUE(Aeroplane, Aeroplane)
#define Average_Time 5
#define MEDIAN_WAIT_TIME 8
#define MEDIAN_ARRIVAL_TIME 4
void startSimulation(int time) {
    printf("Starting simulation. Simulation Time: %d",time);
    printf("--------------------------------------------");
    RunWay run_way[MAX_RUNWAYS];
    int plane_id_counter = 0;
    int currentTime = 0;
    Queue_Aeroplane *aeroplaneQueue = initQueue_Aeroplane();
    aeroplaneQueue = initQueue_Aeroplane();

    int total_planes_arrived = 0;
    int total_planes_serviced = 0;
    for (int i = 0; i < MAX_RUNWAYS; ++i) {
        if (!run_way[i].occupied) {
            run_way[i].busy_until = 0;
            run_way->occupied = false;
            run_way->idAeroplane = -1;
        }
    }
    while (currentTime<=time) {
        for (int i = 0; i < MAX_RUNWAYS; ++i) {
            if (run_way->occupied && run_way->busy_until<= currentTime) {
                run_way->occupied = false;

            }

        }

    //Simulation variables

    int nextArrival = (int)exponential(Average_Time);

        if(nextArrival == currentTime) {
            Aeroplane aeroplane* = nullptr;
            aeroplane->arrival_time =nextArrival;
            aeroplane->id = plane_id_counter++;
            aeroplane->service_time = exponential(MEDIAN_WAIT_TIME );
            for (int i = 0; i < MAX_RUNWAYS; ++i) {
                if (run_way[i].occupied) {
                    enqueue_Aeroplane(aeroplaneQueue,*aeroplane);
                    printf("Aeroplane %d has queued. All runways are occupied",aeroplane->id);
                }
                run_way[i].occupied = true;
                run_way->busy_until = aeroplane->service_time +currentTime;
                run_way->idAeroplane = aeroplane->id;
            }
        }
        if (!isEmpty_Aeroplane(aeroplaneQueue)) {

        }








        currentTime++;
    }


}

int main() {
    Queue_int* hola = initQueue_int();
    Queue_Aeroplane* plane_queue = initQueue_Aeroplane();

    Aeroplane plane1 = {1, 10.0, 5.0};
    Aeroplane plane2 = {2, 15.0, 4.0};

    enqueue_Aeroplane(plane_queue, plane1);
    enqueue_Aeroplane(plane_queue, plane2);

    Aeroplane dequeued_plane = dequeue_Aeroplane(plane_queue);
    printf("Dequeued plane id: %d\n", dequeued_plane.id);

    freeQueue_Aeroplane(plane_queue);
    freeQueue_int(hola);

    return 0;
}
