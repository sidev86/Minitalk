SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: libft client server

client: client.o
	gcc -o $@ $< -no-pie libft/libft.a

server: server.o
	gcc -o $@ $< -no-pie libft/libft.a

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f client server
	make -C libft fclean

re: fclean all

.PHONY: all bonus libft clean fclean re
