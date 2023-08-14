#ifndef DOG_H
#define DOG_H

/**
 * struct dog - this will contain a dog's basic information
 * @name: has a type char *
 * @age: has a type float
 *
 * @owner: has a type char * as well.
 *
 * Description: a more detailed description
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - this will be a typedef for struct dog above
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
