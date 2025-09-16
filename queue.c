#ifndef QUEUE
#define QUEUE

typedef struct node node;
typedef struct queue queue;
node* create_node(node* next_node, int data);
queue* create_queue();
int length(queue* q);
int iter_sequence(queue* q);
int free_queue(queue* q);
int enqueue(queue* q, int x);
int dequeue(queue* q);
int front_value(queue* q);

#endif

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct queue {
    node* front;
    node* rear;
    int size;
} queue;

node* create_node(node* next_node, int data) {
    node* n;

    n = (node*) malloc(sizeof(node));
    if (n == NULL) return NULL;

    n->data = data;
    n->next = next_node;

    return n;
}

queue* create_queue() {
    queue* q;

    q = (queue*) malloc(sizeof(queue));
    if (q == NULL) return NULL;

    q->front = q->rear = create_node(NULL, 0);
    q->size = 0;

    return q;
}

int length(queue* q) {
    if (q == NULL) return -1;

    return q->size;
}

int iter_sequence(queue* q) {
    if (q == NULL) return 1;

    node* n;

    n = q->front->next;
    printf("[");
    while (n != NULL) {
        if (n->next == NULL) printf("%d]\n", n->data);
        else printf("%d, ", n->data);
        n = n->next;
    }

    return 0;
}

int free_queue(queue* q) {
    if (q == NULL) return 1;

    node* n;

    n = q->front->next;
    while (n != NULL) {
        q->front->next = q->front->next->next;
        free(n);
        n = q->front->next;
    }
    free(q);

    return 0;
}

int enqueue(queue* q, int x) {
    if (q == NULL) return 1;

    node* n;

    n = create_node(NULL, x);
    if (q == NULL) return 2;

    q->rear->next = n;
    q->rear = q->rear->next;
    q->size++;

    return 0;
}

int dequeue(queue* q) {
    if (q == NULL) return -1;

    if (q->size <= 0) return -2;

    int ret;
    node* n;

    ret = q->front->next->data;
    n = q->front->next;
    q->front->next = q->front->next->next;

    if (q->front->next == NULL) {
        q->rear = q->front;
    }
    
    q->size--;
    free(n);

    return ret;
}

int front_value(queue* q) {
    if (q == NULL) return -1;

    if (q->size <= 0) return -2;

    return q->front->next->data;
}