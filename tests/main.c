#include "libasm.h"

int main()
{
    // ft_strlen //
    char *strlen_test_string = "Hello World 42";
    printf("ft_strlen(%s) = %li\n" ,strlen_test_string, ft_strlen(strlen_test_string));

    // ft_write //
    ft_write(1, "Hello World 42\n", 15);

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
}