SOURCES 			= server.c client.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS			= -Wall -Wextra -Werror

all: libft client server

bonus: client server

client: client.o 
	gcc -o $@ $< libft/libft.a

server: server.o
	gcc -o $@ $< libft/libft.a

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