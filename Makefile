NAME             = libasm.a
TEST_PROGRAM     = libasm_tester
AR_RCS             = ar rcs

NASM = nasm
NASM_FLAGS = -felf64
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -Iincludes

SRC_PATH         = srcs/
SRCS             = ft_strlen.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s ft_strcmp.s

TEST_PATH        = tests/
TESTS             = main.c

OBJS_DIR        = ./.obj/
SRCS_OBJS       = $(patsubst %.s, $(OBJS_DIR)%.o, $(SRCS))
TEST_OBJS       = $(patsubst %.c, $(OBJS_DIR)%.o, $(TESTS))

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(AR_RCS) $@ $^

$(OBJS_DIR)%.o : $(SRC_PATH)%.s
	mkdir -p $(dir $@)
	$(NASM) $(NASM_FLAGS) $< -o $@

$(OBJS_DIR)%.o : $(TEST_PATH)%.c
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(TEST_PROGRAM): $(TEST_OBJS) $(SRCS_OBJS)
	$(CC) $(CC_FLAGS) -no-pie -o $(TEST_PROGRAM) $^

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TEST_PROGRAM)

re: fclean all

.PHONY: all clean fclean re test