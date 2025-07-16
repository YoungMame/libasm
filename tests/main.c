#include "libasm.h"

int main()
{
    // // ft_strlen //
    char *strlen_test_string = "Hello World 42";
    printf("ft_strlen(%s) = %li\n" ,strlen_test_string, ft_strlen(strlen_test_string));

    // // ft_write //
    ft_write(1, "Hello World 42\n", 15);

    int write_invalid_fd = 42;
    int write_result = ft_write(write_invalid_fd, "Hello World 42\n", 15);
    if (write_result < 0) {
        printf("ft_write failed, errno: %i\n", errno);
    } else {
        printf("ft_write wrote %d bytes\n", write_result);
    }

    // printf("\n");

    // // ft read //
    char read_buffer[100]; 
    const int  fd = open("tests/test.txt", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }
    int bytes_read = ft_read(fd, read_buffer, sizeof(read_buffer));
    if (bytes_read < 0) {
        close(fd);
        printf("ft_read failed, errno: %i\n", errno);
    }
    else {
        read_buffer[bytes_read] = '\0';
        printf("ft_read read %d bytes: %s\n", bytes_read, read_buffer);
        close(fd);
    }


    int invalid_fd = 42;
    bytes_read = ft_read(invalid_fd, read_buffer, sizeof(read_buffer));
    if (bytes_read < 0) {
        printf("ft_read failed with invalid fd %d, errno: %i\n", invalid_fd, errno);
    } else {
        printf("ft_read read %d bytes from invalid fd: %s\n", bytes_read, read_buffer);
    }

    printf("\n");

    // // ft_strcpy //
    char *strcpy_test_string = "Hello World 42";
    char strcpy_test_empty[100] = "";
    printf("strcpy_test_empty after ft_strlen(%s, %s) = " , strcpy_test_empty, strcpy_test_string);
    ft_strcpy(strcpy_test_empty, strcpy_test_string);
    printf("%s\n", strcpy_test_empty);


    // ft_strdup //
    // char *strdup_test_string = "more simple";
    // char *strdup_result = ft_strdup(strdup_test_string);
    // if (strdup_result)
    // {
    //     printf("ft_strdup(%s) = %s\n", strdup_test_string, strdup_result);
    //     free(strdup_result);
    // }
    // else
    // {
    //     printf("ft_strdup failed\n");
    //     printf("Error, errno: %i\n", errno);
    // }

    char *strdup_test_string2 = "Hello World 42";
    char *strdup_result2 = ft_strdup(strdup_test_string2);
    if (strdup_result2)
    {
        printf("ft_strdup(%s) = %s\n", strdup_test_string2, strdup_result2);
        if (strcmp(strdup_test_string2, strdup_result2) != 0)
        {
            printf("strdup_result2 is NOT equal to strdup_test_string2\n");
        }
        free(strdup_result2);
    }
    else
    {
        printf("ft_strdup failed\n");
        printf("Error, errno: %i\n", errno);
    }

    char *strdup_test_string3 = "sahth r re  td sa  rye tu  j j635 4 35243 66 432 ";
    char *strdup_result3 = ft_strdup(strdup_test_string3);
    if (strdup_result3)
    {
        printf("ft_strdup(%s) = %s\n", strdup_test_string3, strdup_result3);
        strdup_result3[0] = '4';
        strdup_result3[1] = '2';
        strdup_result3[2] = 'L';
        strdup_result3[3] = 'H';
        strdup_result3[4] = '\0';
        printf("Modified strdup_result3: %s\n", strdup_result3);
        printf("Original strdup_test_string2: %s\n", strdup_test_string3);
        free(strdup_result3);
    }
    else
    {
        printf("ft_strdup failed\n");
        printf("Error, errno: %i\n", errno);
    }

    printf("\n");

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