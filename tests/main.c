#include "libasm.h"

int main()
{
    // ft_strlen //
    char *strlen_test_string = "Hello World 42";
    printf("ft_strlen(%s) = %li\n" ,strlen_test_string, ft_strlen(strlen_test_string));

    // ft_write //
    ft_write(1, "Hello World 42\n", 15);

    // ft read //
    char read_buffer[100]; 
    const int  fd = open("tests/test.txt", O_RDONLY);
    printf("%i", fd);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }
    int bytes_read = ft_read(fd, read_buffer, sizeof(read_buffer));
    if (bytes_read < 0) {
        close(fd);
        return 1;
    }
    printf("ft_read read %d bytes: %s\n", bytes_read, read_buffer);
    close(fd);

    // ft_strcpy //
    char *strcpy_test_string = "Hello World 42";
    char strcpy_test_empty[100] = "";
    printf("strcpy_test_empty after ft_strlen(%s, %s) = " , strcpy_test_empty, strcpy_test_string);
    ft_strcpy(strcpy_test_empty, strcpy_test_string);
    printf("%s\n", strcpy_test_empty);


    // ft_strdup //
    char *strdup_test_string = "Hello World 42";
    char *strdup_result = ft_strdup(strdup_test_string);
    if (strdup_result)
    {
        printf("ft_strdup(%s) = %s\n", strdup_test_string, strdup_result);
        free(strdup_result);
    }
    else
    {
        printf("ft_strdup failed\n");
    }

    // ft_strcmp //
    char *str1 = "Hello";
    char *str2 = "Hello";
    printf("ft_strcmp(%s, %s) = %d\n", str1, str2, ft_strcmp(str1, str2));
    printf("strcmp(%s, %s) = %d\n", str1, str2, strcmp(str1, str2));

    printf("\n");

    char *str1a = "Hello";
    char *str2a = "Hellooooooo";
    printf("ft_strcmp(%s, %s) = %d\n", str1a, str2a, ft_strcmp(str1a, str2a));
    printf("strcmp(%s, %s) = %d\n", str1a, str2a, strcmp(str1a, str2a));

    printf("\n");

    char *str1b = "Hello";
    char *str2b = "World";
    printf("ft_strcmp(%s, %s) = %d\n", str1b, str2b, ft_strcmp(str1b, str2b));
    printf("strcmp(%s, %s) = %d\n", str1b, str2b, strcmp(str1b, str2b));

    printf("\n");

    char *str1c = "Hello";
    char *str2c = "";
    printf("ft_strcmp(%s, %s) = %d\n", str1c, str2c, ft_strcmp(str1c, str2c));
    printf("strcmp(%s, %s) = %d\n", str1c, str2c, strcmp(str1c, str2c));

    printf("\n");

    char *str1d = "";
    char *str2d = "";
    printf("ft_strcmp(%s, %s) = %d\n", str1d, str2d, ft_strcmp(str1d, str2d));
    printf("strcmp(%s, %s) = %d\n", str1d, str2d, strcmp(str1d, str2d));

    printf("\n");

    char *str1e = "ABC";
    char *str2e = "ABD";
    printf("ft_strcmp(%s, %s) = %d\n", str1e, str2e, ft_strcmp(str1e, str2e));
    printf("strcmp(%s, %s) = %d\n", str1e, str2e, strcmp(str1e, str2e));

    printf("\n");

    char *str1f = "ABE";
    char *str2f = "ABD";
    printf("ft_strcmp(%s, %s) = %d\n", str1f, str2f, ft_strcmp(str1f, str2f));
    printf("strcmp(%s, %s) = %d\n", str1f, str2f, strcmp(str1f, str2f));
}