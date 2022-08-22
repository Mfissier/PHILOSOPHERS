SRCS += ft_philo.c
SRCS += ft_utils2.c
SRCS += ft_utils.c
SRCS += ./ft_error.c 
SRCS += ./ft_init.c


CC = gcc -Wall -Werror -Wextra -g

NAME = philo.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	gcc -o philo $(NAME) -lpthread

$(OBJS) :
	$(CC) -c $(SRCS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf philo

re : fclean all

.phony : fclean all re clean
