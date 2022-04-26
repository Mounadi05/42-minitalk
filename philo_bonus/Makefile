NAME = philo_bonus

SRC = philo.c ft_routine.c ft_time.c linkedlist.c parsing.c

FLAGS = -Wextra -Wall -Werror 

OBJ = $(SRC:.c=.o) 

RM = rm -f

all : $(NAME)

$(NAME) : 	$(OBJ)
			gcc $(FLAGS) $(OBJ) -o $(NAME)
$(.c:.o) :
			gcc  $(FLAGS) $(SRC) -c $<
clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all
