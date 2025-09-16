#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node node;
typedef struct linked_list linked_list;

node* create_node(node* next_node, int data);
linked_list* create_linked_list();
int free_linked_list(linked_list* list);
int iter_sequence(linked_list* list);
int length(linked_list* list);

int get_at(linked_list* list, int n);
int get_first(linked_list* list);
int get_last(linked_list* list);

int set_at(linked_list* list, int n, int x);
int set_first(linked_list* list, int x);
int set_last(linked_list* list, int x);

int insert_at(linked_list* list, int n, int x);
int insert_first(linked_list* list, int x);
int insert_last(linked_list* list, int x);

int delete_at(linked_list* list, int n);
int delete_first(linked_list* list);
int delete_last(linked_list* list);

#endif 

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct linked_list {
    node* head;
    node* tail;
    node* curr;
    int size;
} linked_list;

node* create_node(node* next_node, int data) {
    node* n;

    n = (node*) malloc(sizeof(node));
    if (n == NULL) return NULL;

    n->next = next_node;
    n->data = data;

    return n;
}

linked_list* create_linked_list() {
    linked_list* l;

    l = (linked_list*) malloc(sizeof(linked_list));
    if (l == NULL) return NULL;

    l->head = l->tail = l->curr = create_node(NULL, 0);
    l->size = 0;

    return l;
}

int free_linked_list(linked_list* list) {
    if (list == NULL) return 1;

    list->curr = list->head->next;
    while (list->curr != NULL) {
        list->head->next = list->curr->next;
        free(list->curr);
        list->curr = list->head->next;
    }

    free(list->head);
    free(list);

    return 0;
}

int iter_sequence(linked_list* list) {
    if (list == NULL) return 1;
    
    list->curr = list->head->next;
    printf("[");
    while (list->curr != NULL) {
        if (list->curr->next == NULL) printf("%d]\n", list->curr->data);
        else printf("%d, ", list->curr->data);
        
        list->curr = list->curr->next;
    }
    list->curr = list->head;

    return 0;
}

int length(linked_list* list) {
    if (list == NULL) return -1;

    return list->size;
}

int get_at(linked_list* list, int n) {
    if (list == NULL) return -1;

    if (n < 0 || n >= list->size) return -2;
    
    int i, ret;

    i = 0;
    while (i < n) {
        list->curr = list->curr->next;
        i++;
    }

    ret = list->curr->next->data;
    list->curr = list->head;

    return ret;
}

int get_first(linked_list* list) {
    if (list == NULL) return -1;

    if (list->size == 0) return -2;

    return list->head->next->data;
}

int get_last(linked_list* list) {
    if (list == NULL) return -1;

    if (list->size == 0) return -2;

    return list->tail->data;
};

int set_at(linked_list* list, int n, int x) {
    if (list == NULL) return 1;

    if (n < 0 || n >= list->size) return 2;

    int i;

    i = 0;
    while (i < n) {
        list->curr = list->curr->next;
        i++;
    }
    list->curr->next->data = x;
    list->curr = list->head;

    return 0;
}

int set_first(linked_list* list, int x) {
    if (list == NULL) return 1;

    if (list->size == 0) return 2;

    list->head->next->data = x;

    return 0;
}

int set_last(linked_list* list, int x) {
    if (list == NULL) return 1;

    if (list->size == 0) return 2;

    list->tail->data = x;

    return 0;
}

int insert_at(linked_list* list, int n, int x) {
    if (list == NULL) return 1;

    if (n < 0 || n > list->size) return 2;

    node* new_node;
    int i;

    i = 0;
    while (i < n) {
        list->curr = list->curr->next;
        i++;
    }
    
    new_node = create_node(list->curr->next, x);
    if (new_node == NULL) return 3;
    
    list->curr->next = new_node;
    if (list->tail == list->curr) {
        list->tail = list->curr->next;
    }
    list->size++;
    list->curr = list->head;

    return 0;
}

int insert_first(linked_list* list, int x) {
    if (list == NULL) return 1;

    list->head->next = create_node(list->head->next, x);
    if (list->tail == list->head) {
        list->tail = list->head->next;
    }
    list->size++;

    return 0;
}

int insert_last(linked_list* list, int x) {
   return insert_at(list, list->size, x);
}

int delete_at(linked_list* list, int n) {
    if (list == NULL) return 1;

    if (n < 0 || n >= list->size) return 2;

    int i;
    node* tmp;

    i = 0;
    while (i < n) {
        list->curr = list->curr->next;
        i++;
    }

    tmp = list->curr->next;
    list->curr->next = list->curr->next->next;
    free(tmp);
    list->curr = list->head;
    list->size--;
    if (list->head->next == NULL) {
        list->tail = list->head;
    } 

    return 0;
}

int delete_first(linked_list* list) {
    if (list == NULL) return 1;

    if (list->head->next == NULL) return 2;

    list->curr = list->curr->next;
    list->head->next = list->curr->next;
    free(list->curr);
    list->curr = list->head;
    list->size--;
    if (list->head->next == NULL) { 
        list->tail = list->head;
    }

    return 0;
}

int delete_last(linked_list* list) {
    return delete_at(list, list->size - 1);
}