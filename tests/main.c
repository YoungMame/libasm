#include "libasm.h"

int main()
{
    char *strlen_test_string = "Hello World 42";
    printf("ft_strlen_test(%s) = %i\n" ,strlen_test_string, ft_strlen_test(strlen_test_string));
}