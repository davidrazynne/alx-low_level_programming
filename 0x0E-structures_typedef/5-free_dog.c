#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - this fxn will release the memory allocated for the .struct dog
 * @d: this indicates the struct dog to release
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
