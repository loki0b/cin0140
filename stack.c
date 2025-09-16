#ifndef STACK
#define STACK

typedef struct node node;
typedef struct stack stack;

node* create_node(node* next_node, int data);
stack* create_stack();
int free_stack(stack* s);
int iter_sequence(stack* s);
int size(stack* s);
int top_value(stack* s);
int push(stack* s, int x);
int pop(stack* s);

#endif

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct stack {
    node* top;
    int size;
} stack;

node* create_node(node* next_node, int data) {
    node* n;

    n = (node*) malloc(sizeof(node));
    if (n == NULL) return NULL;

    n->data = data;
    n->next = next_node;

    return n;
}

stack* create_stack() {
    stack* s;

    s = (stack*) malloc(sizeof(stack));
    if (s == NULL) return NULL;

    s->top = NULL;
    s->size = 0;

    return s;
}

int free_stack(stack* s) {
    if (s == NULL) return 1;

    node* n;

    n = s->top;
    while (n != NULL) {
        s->top = s->top->next;
        free(n);
        n = s->top;
    }

    free(s);

    return 0;
}

int iter_sequence(stack* s) {
    if (s == NULL) return 1;

    node* tmp;

    tmp = s->top;
    printf("---top---\n");
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    printf("---------\n");
    
    return 0;
}

int size(stack* s) {
    if (s == NULL) return -1;

    return s->size;
};

int top_value(stack* s) {
    if (s->size > 0) {
        return s->top->data;
    }
    
    return -1;
}

int push(stack* s, int x) {
    if (s == NULL) return 1;

    node* n;

    n = create_node(s->top, x);
    if (n == NULL) return 1;

    s->top = n;
    s->size++;

    return 0;
}

int pop(stack* s) {
    if (s == NULL || s->top == NULL) return -1;

    node* n;
    int ret;

    n = s->top;
    ret = n->data;
    s->top = s->top->next;
    s->size--;
    free(n);

    return ret;
}