NAME			= libftprintf.a

SRCS 	   = ft_printf.c \
			 ft_putchar.c \
			 ft_puthex.c \
			 ft_putint.c \
			 ft_putptr.c \
			 ft_putstr.c \
			 ft_putunsigned.c

# B_SRCS     = 

HEADERS 		= ft_printf.h

OBJS 			= $(SRCS:.c=.o)

B_OBJS 			= $(B_SRCS:.c=.o)

CC				= cc
FLAGS			= -Wall -Werror -Wextra

AR				= ar -rsc

RM				= rm -f

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

all:			$(NAME)

# bonus:			$(OBJS) $(B_OBJS)
# 				$(AR) $(NAME) $(OBJS) $(B_OBJS)

%.o:%.c
				$(CC) -I $(HEADERS) $< -o $(<:.c=.o) -c $(FLAGS)

clean:
				$(RM) $(OBJS) $(B_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
