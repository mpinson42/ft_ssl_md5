NAME = ft_ssl

SRC = srcs/main.c srcs/md5.c srcs/sha256.c srcs/lib.c srcs/printing.c srcs/manang.c srcs/sha224.c srcs/escape_norme.c

FLAGS = -Wall -Wextra -Werror

OBJ = main.o md5.o sha256.o lib.o printing.o manang.o sha224.o

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
