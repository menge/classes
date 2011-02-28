#include "strmemfuncs.h"

void * my_memcpy(void *dest, const void *src, size_t n) {
   for (size_t i = 0; i < n; i++) {
      ((char *) dest)[i] = ((char *) src)[i];
   }
   return dest;
}

void * my_memset(void *s, int c, size_t n) {
   for (size_t i = 0; i < n; i++) {
      ((char *) s)[i] = (char) c;
   }
   return s;
}

size_t my_strlen(const char *s) {
   size_t i = 0;
   for (; s[i] != '\0'; i++) {
   }
   return i - 1;
}

char * my_strcpy(char *dest, const char *src) {
   char *orig_dest = dest;
   while (src != '\0') {
      *dest = *src;
      dest++;
      src++;
   }
   *dest = '\0';

   return orig_dest;
}

char * my_strncpy(char *dest, const char *src, size_t n) {
   size_t i;
   for (i = 0; i < n && src[i] != '\0'; i++) {
      dest[i] = src[i];
   }
   my_memset(dest+i, '\0', n-i+1);

   return dest;
}

int my_strcmp(const char *s1, const char *s2) {
   while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
      s1++;
      s2++;
   }

   if (*s1 < *s2) {
      return -1;
   }
   else if (*s1 > *s2) {
      return 1;
   }
   return 0;
}

int my_strncmp(const char *s1, const char *s2, size_t n) {
   size_t i = 0;

   while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && i < n) {
      s1++;
      s2++;
      i++;
   }

   /* since we got through all the checks and through n characters, the strings are the same through n */
   if (i == n) {
      return 0;
   }

   if (*s1 < *s2) {
      return -1;
   }
   else if (*s1 > *s2) {
      return 1;
   }
   return 0;
}
