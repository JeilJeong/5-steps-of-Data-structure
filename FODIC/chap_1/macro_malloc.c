#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
	if (((p) = malloc(s)))
