CC := gcc
NAME := ft_ls
CFLAGS := -Wall -Wextra -Werror
LIBFT := libft/libft.a
SOURCE :=	srcs/ft_ls.c srcs/structstuff.c srcs/sort.c srcs/moresortingstuff.c srcs/checks.c\
			srcs/errors.c srcs/checksaswell.c srcs/prints.c srcs/evenmorechecks.c srcs/othersort.c\
			srcs/args.c srcs/moreprints.c srcs/statreads.c srcs/blocks.c srcs/couplemoreprints.c\
			srcs/paddings.c srcs/pathandler.c srcs/brotheseprintstho.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

debug:
	$(CC) $(CFLAGS) -g $(SOURCE) $(LIBFT) -o $(NAME)

sanitize:
	$(CC) $(CFLAGS) -fsanitize=address $(SOURCE) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJECTS)

sclean:
	rm -f $(OBJECTS)

fclean: dclean
	rm -f $(NAME)
	rm -f $(LIBFT)

dclean: clean
	rm -rf $(NAME).dSYM

re: fclean all

sre: sclean all
