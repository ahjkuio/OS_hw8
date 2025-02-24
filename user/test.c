#include "kernel/types.h"
#include "user.h"

void assert(char val) {
	if (!val) {
		printf("assertion failed!\n");
		exit(0);
	}
}

int main() {
	int size = 2;
	int* arr = malloc(size * sizeof(int));
	
	arr[1] = 3;
	int res = pgaccess(arr, size * sizeof(int));
	assert(res == 1);
	
	res = pgaccess(arr, size * sizeof(int));
	assert(res == 0);

	arr[0] = 1;
	res = pgaccess(arr, size * sizeof(int));
	assert(res == 1);

	free(arr);

	int arr2[size];

	arr2[0] = 1;
	res = pgaccess(arr2, size * sizeof(int));
	assert(res == 1);

	res = pgaccess(arr2, size * sizeof(int));
	assert(res == 0);

	char* c = malloc(sizeof(char));
	
	*c = 1;
	res = pgaccess(c, sizeof(char));
	assert(res == 1);

	res = pgaccess(c, sizeof(char));
	assert(res == 0);

	free(c);

	printf("Test passed!\n");

	return 0;
}