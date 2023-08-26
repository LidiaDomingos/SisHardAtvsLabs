#include <stdlib.h>

#include "vec_int.h"

typedef struct _vec_int {
    int *data;
    int size;
    int capacity;
} vec_int;

vec_int *vec_int_create() {
    vec_int *p;
    p = malloc(sizeof(vec_int));
    (*p).size = 0;
    (*p).capacity = 2;
    (*p).data = malloc(((*p).capacity) * sizeof(int));
    return p;
}

void vec_int_destroy(vec_int **_v) {
    free((**_v).data);
    free(*_v);
    *_v = NULL;
}

int vec_int_size(vec_int *v) {
    return (*v).size;
}

int vec_int_at(vec_int *v, int pos, int *val) {
    if ((*v).size > 0) {
        if (pos >= 0 && pos < (*v).size) {
            (*val) = ((*v).data)[pos];
            return 1;
        }
    }
    return 0;
}

int vec_int_insert(vec_int *v, int pos, int val) {
    if (pos >= 0 && pos <= (*v).size) {
        if ((*v).size == (*v).capacity - 1) {
            int *p;
            p = realloc((*v).data, ((*v).capacity) * sizeof(int) * 2);
            if (p == NULL) {
                return 0;
            }
            (*v).data = p;
            (*v).capacity = 2 * (*v).capacity;
        }
        for (int i = ((*v).size - 1); i >= pos; i--) {
            ((*v).data)[i + 1] = ((*v).data)[i];
        }
        ((*v).data)[pos] = val;
        (*v).size = (*v).size + 1;
        return 1;
    }
    return 0;
}

int vec_int_remove(vec_int *v, int pos) {
    if (pos >= 0 && pos < (*v).size) {
        if ((*v).size == (*v).capacity/4) {
            int *p;
            p = realloc((*v).data, ((*v).capacity) * sizeof(int) / 2);
            if (p == NULL) {
                return 0;
            }
            (*v).data = p;
            (*v).capacity = (*v).capacity/2;
        }
        for (int i = pos; i < ((*v).size - 1); i++) {
            ((*v).data)[i] = ((*v).data)[i + 1];
        }
        (*v).size = (*v).size - 1;
        return 1;
    }
    return 0;
}
