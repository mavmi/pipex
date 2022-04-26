SRCS		= 	ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	libft.h

FLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

GCC			=	$(CC) $(FLAGS)

NAME		=	libft.a

all:		$(NAME)

%.o:		%.c $(INCLUDES)
			$(GCC) -c -o $@ $<

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

libft:		$(NAME)

clean:
			rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean bonus re
