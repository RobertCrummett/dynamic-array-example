#ifndef DARR_H
#define DARR_H

#include <stddef.h>

typedef struct darr_t darr_t;
struct darr_t {
	size_t size;
	size_t capacity;
	int *data;
};

extern int darr_malloc(darr_t **array, size_t size);
extern int darr_realloc(darr_t **array, size_t size);

extern int darr_push(darr_t **array, int elem);
extern int darr_grow(darr_t **array, int elem);

extern void darr_print(darr_t **array);

#endif
