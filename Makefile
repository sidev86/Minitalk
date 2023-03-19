SOURCES 			= server.c client.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS			= -Wall -Wextra -Werror

all: client server

bonus: client server

client: client.o libft
	gcc -o $@ $< -Llibft -lft

server: server.o libft
	gcc -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean: 
	rm -f $(OBJECTS) 
	make -C libft clean

fclean: clean
	rm -f client server libft/libft.a

re: fclean all


.PHONY: all bonus libft clean fclean re 