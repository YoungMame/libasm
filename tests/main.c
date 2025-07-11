#include "libasm.h"

int main()
{
    char *strlen_test_string = "Hello World 42";
    printf("ft_strlen(%s) = %li\n" ,strlen_test_string, ft_strlen(strlen_test_string));
}