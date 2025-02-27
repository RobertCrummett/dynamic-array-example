#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "darr.h"

#define DARR_SCALE 2

int darr_malloc(darr_t **array, size_t size) {
	if (size == 0)
		return 1;

	if (array == NULL)
		return 1;
	
	*array = malloc(sizeof **array);
	if (*array == NULL)
		return 1;

	(*array)->data = malloc(size * sizeof *((*array)->data));
	if ((*array)->data == NULL)
		return 1;

	(*array)->capacity = 0;
	(*array)->size = size;
	return 0;
}

int darr_push(darr_t **array, int elem) {
	if (array == NULL || *array == NULL)
		return 1;

	if ((*array)->size == (*array)->capacity)
		return 1;

	(*array)->data[(*array)->capacity++] = elem;
	return 0;
}

int darr_realloc(darr_t **array, size_t size) {
	if (array == NULL || *array == NULL)
		return 1;

	if ((*array)->data == NULL)
		return 1;

	if (size < (*array)->capacity)
		return 1;
	else if (size == (*array)->capacity)
		return 0;

	int* data = malloc(size * sizeof *data);
	if (data == NULL)
		return 1;

	memcpy(data, (*array)->data, (*array)->capacity * sizeof *((*array)->data));
	
	free((*array)->data);

	(*array)->data = data;
	(*array)->size = size;

	return 0;
}

int darr_grow(darr_t **array, int elem) {
	if (array == NULL || *array == NULL)
		return 1;

	if ((*array)->capacity == (*array)->size)
		if (darr_realloc(array, (*array)->size * DARR_SCALE))
			return 1;

	(*array)->data[(*array)->capacity++] = elem;
	return 0;
}

void darr_print(darr_t **array) {
	printf("array{size=%zu, capacity=%zu, data=%p}\n", (*array)->size, (*array)->capacity, (*array)->data);
}
