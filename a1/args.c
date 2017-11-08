#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// This prints all arguments.
int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}

	printf("PROGRAM NAME IS: %s\n", argv[0]);
}
