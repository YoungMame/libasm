#pragma once
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

// libasm
size_t ft_strlen(const char *str);
char  *ft_strcpy(char *dest, const char *src);
int ft_write(int fd, char *str, int len);
int ft_read(int fd, char *buf, size_t count);
char  *ft_strdup(const char *s1);
int ft_strcmp(const char *s1, const char *s2);

// tester
int ft_strlen_test(char *str);