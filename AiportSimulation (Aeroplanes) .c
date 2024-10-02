#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h> // Added for time-based seeding of random number generator
//Macros
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
    }                                                                  \
    void enqueue_##TYPENAME(Queue_##TYPENAME* q, TYPE value) {         \
        Node_##TYPENAME* temp = createNode_##TYPENAME(value);          \
        if (q->front == NULL) {                                        \
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
DEFINE_QUEUE(int, int)

typedef struct {
    int id;
    double arrival_time;
    double service_time;
} Aeroplane;

typedef struct {
    bool occupied;
    double busy_until; // Changed to double for consistency
    int idAeroplane;
} RunWay;

double exponential(double mean) {
    double u;
    do
        u = rand() / (double)RAND_MAX;
    while (u == 0.0 || u == 1.0); // Ensure u is between 0 and 1 (non-inclusive)
    double result = -mean * log(u); // Changed from (1 - u) to u for proper exponential distribution
    // Cap the maximum interval at 3 times the mean to prevent excessively large intervals
    if (result > mean * 3) {
        result = mean * 3;
    }
    return result;
}

DEFINE_QUEUE(Aeroplane, Aeroplane)


#define AVERAGE_ARRIVAL_TIME 2
#define AVERAGE_SERVICE_TIME 5

void displayRunwaysAndQueue(RunWay run_way[], Queue_Aeroplane* aeroplaneQueue, int currentTime) {
    printf("\nTime: %d\n", currentTime);
    printf("Runways Status:\n");
    for (int i = 0; i < MAX_RUNWAYS; ++i) {
        if (run_way[i].occupied) {
            printf("Runway %d: [Aeroplane %d landing until time %.2f]\n", i + 1, run_way[i].idAeroplane, run_way[i].busy_until);
        } else {
            printf("Runway %d: [Available]\n", i + 1);
        }
    }
    printf("Waiting Queue: ");
    if (isEmpty_Aeroplane(aeroplaneQueue)) {
        printf("[No planes waiting]\n");
    } else {
        Node_Aeroplane* current = aeroplaneQueue->front;
        while (current != NULL) {
            printf("[Aeroplane %d] ", current->data.id);
            current = current->next;
        }
        printf("\n");
    }
    printf("--------------------------------------------------\n");
}

void startSimulation(int time) {
    printf("Starting simulation. Simulation Time: %d\n", time);
    printf("--------------------------------------------------\n");

    RunWay run_way[MAX_RUNWAYS];
    int plane_id_counter = 0;
    int currentTime = 0;
    int endingSimulation = time -10;
    Queue_Aeroplane* aeroplaneQueue = initQueue_Aeroplane();

    for (int i = 0; i < MAX_RUNWAYS; ++i) {
        run_way[i].busy_until = 0.0;
        run_way[i].occupied = false;
        run_way[i].idAeroplane = -1;
    }

    double nextArrival = exponential(AVERAGE_ARRIVAL_TIME);
    printf("First arrival scheduled at time %.2f\n", nextArrival);

    while (currentTime <= time) {
        displayRunwaysAndQueue(run_way, aeroplaneQueue, currentTime);
        // Check if any runways have become free
        for (int i = 0; i < MAX_RUNWAYS; ++i) {
            if (run_way[i].occupied && run_way[i].busy_until <= currentTime) {
                printf("Aeroplane %d has finished landing on Runway %d at time %d.\n", run_way[i].idAeroplane, i + 1, currentTime);
                run_way[i].occupied = false;
                run_way[i].busy_until = 0.0;
                run_way[i].idAeroplane = -1;
            }
        }

        if (!isEmpty_Aeroplane(aeroplaneQueue)) {
            for (int i = 0; i < MAX_RUNWAYS; i++) {
                if (!run_way[i].occupied) {
                    Aeroplane waiting_aeroplane = dequeue_Aeroplane(aeroplaneQueue);
                    run_way[i].occupied = true;
                    run_way[i].idAeroplane = waiting_aeroplane.id;
                    run_way[i].busy_until = currentTime + waiting_aeroplane.service_time;
                    printf("Aeroplane %d is now landing on Runway %d from queue at time %d.\n", waiting_aeroplane.id, i + 1, currentTime);
                    break; // Assign one plane per time unit
                }
            }
        }
if( currentTime < endingSimulation) {
    while (nextArrival <= currentTime) {

        Aeroplane aeroplane;
        aeroplane.arrival_time = currentTime;
        aeroplane.id = plane_id_counter++;
        aeroplane.service_time = exponential(AVERAGE_SERVICE_TIME);
        if (aeroplane.service_time >time) {
            freeQueue_Aeroplane(aeroplaneQueue);
            for (int i = 0; i < MAX_RUNWAYS; ++i) {
                if (run_way[i].occupied) {
                    
                }
                run_way[i].occupied = false;
            }
        }

        printf("Aeroplane %d has arrived at time %d.\n", aeroplane.id, currentTime);

            bool aeroplaneAssigned = false;
            for (int i = 0; i < MAX_RUNWAYS; ++i) {
                if (!run_way[i].occupied) {
                    run_way[i].occupied = true;
                    run_way[i].busy_until = aeroplane.service_time + currentTime;
                    run_way[i].idAeroplane = aeroplane.id;
                    aeroplaneAssigned = true;
                    printf("Aeroplane %d is landing on Runway %d at time %d.\n", aeroplane.id, i + 1, currentTime);
                    break;
                }

            }

            if (!aeroplaneAssigned) {
                enqueue_Aeroplane(aeroplaneQueue, aeroplane);
                printf("Aeroplane %d has queued at time %d. All runways are occupied.\n", aeroplane.id, currentTime);
            }

            nextArrival += exponential(AVERAGE_ARRIVAL_TIME);
            printf("Next arrival scheduled at time %.2f\n", nextArrival);

    }
}
        else {
            printf("No more new arrivals. Ending simulation");
        }

        // Simple animation: simulate time passing with dots
        printf("Time advancing");
        for (int i = 0; i < 2; ++i) {
            printf(".");
            // Simple delay (not accurate timing)
            for (volatile int j = 0; j < 10000000; ++j);
        }
        printf("\n");

        currentTime++;
    }

    freeQueue_Aeroplane(aeroplaneQueue);
    printf("Simulation ended.\n");
}

int main() {
    srand(time(NULL));

    startSimulation(200);

    return 0;
}
