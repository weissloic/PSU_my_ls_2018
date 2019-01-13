/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** my_strcat
*/

#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int co = 0;
    int counter = 0;

    while (dest[co] != '\0') {
        co++;
    }
    while (src[counter] != '\0') {
        dest[co + counter] = src[counter];
        counter++;
    }
    dest[co + counter] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char *my_strncpy(char *dest, char *src, int n)
{
  int i;

  i = 0;
  while (n > 0 && *(src + i))
    {
      *(dest + i) = *(src + i);
      i++;
      n--;
    }
  if (n > 0)
    *(dest + i) = '\0';
  return (dest);
}