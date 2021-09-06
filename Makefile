.PHONY:	clean fclean re all

INC			= includes

_HEADERS= ft_printf.h libft.h

HEADERS = $(patsubst %, $(INC)/%,$(_HEADERS))

SRCS		= count_width/count_digits.c count_width/count_digits_unsigned_base.c \
					count_width/count_digits_ptr.c count_width/count_width.c \
					parser/parser.c parser/parse_item.c parser/parser_utils.c \
					print/print.c print/print_d.c print/print_p.c \
					print/print_s.c print/print_u.c print/print_c.c \
					print/supplement.c \
					read/read_value.c read/read_value_utils.c \
					miscellanea/in.c miscellanea/ft_putstr_n.c miscellanea/minmax.c \
					miscellanea/repeat_chr.c \
					parser/parse_item.c parser/parser_utils.c parser/parser.c \
					ft_printf.c

OBJS		= $(patsubst %.c,%.o,$(SRCS))

_FTSRCS	= ft_atoi.c ft_bzero.c ft_calloc.c \
		  ft_isalnum.c ft_isalpha.c ft_isascii.c \
		  ft_isdigit.c ft_isprint.c ft_memcpy.c \
		  ft_memchr.c ft_memcmp.c ft_memmove.c \
		  ft_memset.c ft_strchr.c ft_strdup.c \
		  ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		  ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		  ft_tolower.c ft_toupper.c ft_memccpy.c \
		  ft_substr.c ft_strjoin.c ft_strtrim.c \
		  ft_split.c ft_itoa.c ft_strmapi.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
			ft_lstdelone.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c ft_putchar.c ft_putstr.c \
			ft_putnbr.c ft_putnbr_unsigned_base.c \
			convert.c ft_putptr.c

FTSRCS	= $(patsubst %,$(LIBFTDIR)/%,$(_FTSRCS))

FTOBJS  = $(patsubst %.c,%.o,$(FTSRCS))

NAME		= libftprintf.a

CC			= gcc

CFLAGS	= -Wall -Wextra -Werror

RM			= rm -f

LIBFTDIR= libft

LIBFTBIN= libft.a

MAKE		= make

all:	$(NAME)

%.o : %.c $(HEADERS)
			$(CC) $(CFLAGS) -I $(INC) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(FTOBJS)
			$(MAKE) -C $(LIBFTDIR)
			cp $(LIBFTDIR)/$(LIBFTBIN) $(NAME)
			ar rc $(NAME) $(OBJS)

clean:
			$(MAKE) -C libft clean
			$(RM) $(OBJS)

fclean:	clean
			$(MAKE) -C libft fclean
			$(RM) $(NAME)

re:		fclean all
