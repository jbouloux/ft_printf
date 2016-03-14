NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LDFLAGS = -I ./includes/

SRC = ft_adrtostr.c \
	  ft_atoi.c \
	  ft_inttohexa.c \
	  ft_ulongtooctal.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_litoa.c \
	  ft_longlen.c \
	  ft_printf.c \
	  ft_printf_display.c \
	  ft_printf_display2.c \
	  ft_printf_display3.c \
	  ft_printf_display4.c \
	  ft_printf_format.c \
	  ft_printf_tools.c \
	  ft_printf_tools2.c \
	  ft_putchar.c \
	  ft_putlong.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_putunsint.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strnew.c \
	  ft_unsintlen.c \
	  ft_mintomaj.c \
	  ft_putwchar.c \
	  ft_putwstr.c \
	  ft_ulitoa.c \
	  ft_isupper.c \
	  ft_wcharlen.c \
	  ft_wstrlen.c \
	  ft_strndup.c \
	  ft_wstrndup.c \
	  ft_wstrnew.c


OBJ = $(SRC:.c=.o)
	SRC_PATH	= ./srcs/
	OBJ_PATH	= ./objs/
	SRCS		= $(addprefix $(SRC_PATH), $(SRC))
	OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Compilation of $(NAME) : DONE ! \n"

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mv $(OBJ) $(OBJ_PATH)

clean:
	@rm -f $(OBJS)
		@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re