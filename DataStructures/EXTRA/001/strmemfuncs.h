#ifndef _STRMEMFUNCS_
#define _STRMEMFUNCS_

#include <stdlib.h>

void * my_memcpy(void *dest, const void *src, size_t n);
void * my_memset(void *s, int c, size_t n);
size_t my_strlen(const char *s);
char * my_strcpy(char *dest, const char *src);
char * my_strncpy(char *dest, const char *src, size_t n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);

#endif
