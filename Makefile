NAME = ft_ssl

SRC = srcs/main.c srcs/md5.c srcs/sha256.c

FLAGS = -Wall -Wextra -Werror

OBJ = main.o

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC) $(SRC2)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc $(FLAGS) -I ./include/ -L ./lib -lft -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(OBJ)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
