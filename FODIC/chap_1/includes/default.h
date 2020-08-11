#ifndef DEFAULT_H
# define DEFAULT_H

#include <stdlib.h>

#define MALLOC(p, s) \
	if (!((p) = malloc((s) * (DEFAULT_SIZE)))) \
	{ \
		fprintf(stderr, "Insuffienct memory\n"); \
		exit(EXIT_FAILURE); \
	}
#define DEFAULT_SIZE 100

#endif
