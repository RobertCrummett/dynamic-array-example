#include <stdio.h>

#include "darr.h"

int main(void) {
	size_t size = 32;
	darr_t* array = NULL;

	if (darr_malloc(&array, size)) {
		fprintf(stderr, "Failed to allocate dynamic array!\n");
		return 1;
	}

	darr_print(&array);
	while (darr_grow(&array, 1) == 0 && array->capacity < 1024)
		;
	darr_print(&array);

	if (darr_realloc(&array, 2 * array->size)) {
		fprintf(stderr, "Failed to reallocate dynamic array!\n");
		return 1;
	}
	darr_print(&array);

	darr_free(&array);

	return 0;
}
