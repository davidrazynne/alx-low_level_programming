#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - this code will return the length of a string given
 *
 * @s: the actual string to evaluate in the code
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
/**
 * *_strcpy - this function copies the string pointed to by src
 *
 * which will include a terminating null byte: backslash zero
 *
 * @dest: pointer to the buffer in which we copy the string
 * @src: this indicates that string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - this fxn creates a new dog
 * @age: this indicates age of the dog
 * @owner: this indicates owner of the dog
 *
 * @name: this indicates name of the dog
 *
 * Return: a pointer to the new dog (Success), NULL is the alternative.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len1, len2;

	len1 = _strlen(name);
	len2 = _strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (len1 + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = malloc(sizeof(char) * (len2 + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}

