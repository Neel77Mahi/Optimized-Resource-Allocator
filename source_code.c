#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for each server to store max and current capacities
typedef struct {
    int max_capacity;
    int current_capacity;
    int server_id;
} Server;

// Comparator for max-heap behavior (descending order of current_capacity)
int compare_servers(const void *a, const void *b) {
    return ((Server *)b)->current_capacity - ((Server *)a)->current_capacity;
}

// Comparator for sorting requests in descending order
int compare_requests(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// First-Fit Decreasing with Priority Queue
void first_fit_decreasing_priority_queue(int requests[], int n, Server servers[], int m) {
    // Sort requests in descending order
    qsort(requests, n, sizeof(int), compare_requests);

    // Create a heap (array) copy of servers
    Server heap[m];
    for (int i = 0; i < m; i++) {
        heap[i] = servers[i];
    }

    // Sort servers by current capacity (descending)
    qsort(heap, m, sizeof(Server), compare_servers);

    for (int i = 0; i < n; i++) {
        int allocated = 0;

        // Try to allocate current request
        for (int j = 0; j < m; j++) {
            if (heap[j].current_capacity >= requests[i]) {
                heap[j].current_capacity -= requests[i];
                printf("Request %d (demand %d) allocated to Server %d\n", i + 1, requests[i], heap[j].server_id);
                allocated = 1;

                // Re-sort servers to maintain max-heap behavior
                qsort(heap, m, sizeof(Server), compare_servers);
                break;
            }
        }

        if (!allocated) {
            printf("Request %d (demand %d) could not be allocated\n", i + 1, requests[i]);
        }
    }
}

int main() {
    int n, m;

    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];

    for (int i = 0; i < n; i++) {
        printf("Request %d demand: ", i + 1);
        scanf("%d", &requests[i]);
    }

    printf("Enter the number of servers: ");
    scanf("%d", &m);
    Server servers[m];

    for (int i = 0; i < m; i++) {
        printf("Enter max capacity for Server %d: ", i + 1);
        scanf("%d", &servers[i].max_capacity);
        servers[i].current_capacity = servers[i].max_capacity;
        servers[i].server_id = i + 1;
    }

    clock_t start = clock();

    first_fit_decreasing_priority_queue(requests, n, servers, m);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}

