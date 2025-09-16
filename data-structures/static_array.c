#ifndef STATIC_ARRAY
#define STATIC_ARRAY

typedef struct static_array static_array;

static_array* create_static_array(int* iterable, int size);
int delete_static_array(static_array* sa);
int length(static_array* sa);
int iter_sequence(static_array* sa);
int get_at(static_array* sa, int n);
int set_at(static_array* sa, int n, int x);

#endif

#include <stdlib.h>
#include <stdio.h>

typedef struct static_array {
    int* array;
    int size;
} static_array;

static_array* create_static_array(int* iterable, int size) {
    static_array* l;
    
    l = (static_array*) malloc(sizeof(static_array));
    if (l == NULL) {
        return NULL;
    }

    int* array;
    int n;
    
    array = (int*) malloc(sizeof(int) * size);
    if (array == NULL) {
        return NULL;
    }

    n = 0;
    while (n < size) {
        array[n] = iterable[n];
        n++;
    }

    l->array = array;
    l->size = size;

    return l;
}

int delete_static_array(static_array* sa) {
    if (sa == NULL) return 1;

    free(sa->array);
    free(sa);

    return 0;
}

int length(static_array* sa) {
    if (sa == NULL) return -1;

    return sa->size;
};

int iter_sequence(static_array* sa) {
    if (sa == NULL) return 1;

    int n;

    n = 0;
    printf("[");
    while (n < sa->size) {
        if (n == sa->size - 1) printf("%d]\n", sa->array[n]);
        else printf("%d, ", sa->array[n]);
        n++;
    }


    return 0;
}

int get_at(static_array* sa, int n) {
    if (sa == NULL) return -1;

    if (n < 0 || n >= sa->size) return -2;

    return sa->array[n];
}

int set_at(static_array* sa, int n, int x) {
    if (sa == NULL) return 1;

    if (n < 0 || n > sa->size) return 2;

    sa->array[n] = x;

    return 0;
}