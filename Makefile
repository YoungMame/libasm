NAME             = libasm.a
TEST_PROGRAM     = libasm_tester
AR_RCS             = ar rcs

NASM = nasm
NASM_FLAGS = -felf64 -DPIC
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -Iincludes -fPIE

SRC_PATH         = srcs/
SRCS             = ft_strlen.s

TEST_PATH        = tests/
TESTS             = main.c test_ft_strlen.c

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

test: $(TEST_OBJS) $(SRCS_OBJS)
	$(CC) $(CC_FLAGS) -o $(TEST_PROGRAM) $^

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TEST_PROGRAM)

re: fclean all

.PHONY: all clean fclean re test