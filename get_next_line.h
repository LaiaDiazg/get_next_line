#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

char *get_next_line(int fd);

// Joins 2 strings into one. Used for multiple calls to read() to accumulate data into the buffer
char *ft_strjoin_gnl(char const *s1, char const *s2);

// Searches for a specific char within a string. Check if the buffer contains a newline char (indicates a complete line)
char *ft_strchr_gnl(const char *s, int c);

// Sets n chars of mem block to 0
void ft_bzero_gnl(void *s, size_t n);

// Allocates memory and ensures it isnt initialized to random values
void *ft_calloc_gnl(size_t nmemb, size_t size);

size_t ft_strlen_gnl(const char *s);

#endif