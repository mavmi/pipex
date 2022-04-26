NAME		=	pipex


LIBFT_DIR	=	libft
LIBFT_HDR	=	$(LIBFT_DIR)/libft.h
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	$(LIBFT_DIR)/Makefile


SRCS		= 	pipex.c input_handler.c paths.c utils.c
OBJS		=	$(SRCS:.c=.o)
HDRS		=	pipex.h


FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc
GCC			=	$(CC) $(FLAGS)


all:			$(NAME)

%.o:			%.c $(HDRS) $(LIBFT_HDR)
				$(GCC) -c -o $@ $<
 
$(NAME):		$(OBJS) $(LIBFT_HDR)
				cd $(LIBFT_DIR) && $(MAKE)
				$(GCC) $(OBJS) $(LIBFT) -o $(NAME)

clean:				
				rm -f $(OBJS)
				cd $(LIBFT_DIR) && make clean

fclean:			clean
				cd $(LIBFT_DIR) && make fclean
				rm -f $(NAME)				

re:				fclean $(NAME)

.PHONY:			all clean fclean re
