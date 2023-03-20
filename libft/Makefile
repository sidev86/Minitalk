PRINTF_DIR			= ./ft_printf

SRCFILES			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_striteri.c\
					ft_memmove.c ft_putnbr_fd.c ft_strlen.c ft_strdup.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c

BSRCFILES			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF_FILES			= $(addprefix $(PRINTF_DIR)/, ft_printf.c ft_print_utils.c ft_print_ptr.c \
						ft_print_hex.c ft_print_base10.c)

PRINTF_HEADER			= ft_printf/ft_printf.h

OBJECTS			= $(SRCFILES:.c=.o)
BOBJECTS		= $(BSRCFILES:.c=.o)
PRINTF_OBJECTS		= $(PRINTF_FILES:%.c=%.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJECTS) $(PRINTF_OBJECTS) $(PRINTF_HEADER)
				ar -r $(NAME) $(OBJECTS) $(PRINTF_OBJECTS)
bonus:			$(OBJECTS) $(BOBJECTS)
				ar -r $(NAME) $(OBJECTS) $(BOBJECTS)

clean:
				$(RM) $(OBJECTS) $(BOBJECTS) $(PRINTF_OBJECTS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all bonus clean fclean re