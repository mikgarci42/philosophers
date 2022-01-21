FILES = main		\
      initdata		\
      checkinput	\
	  utils			\
      
NAME = philo_bonus

CC = clang

INC = -I inc/

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address 

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(addprefix $(SRC_DIR), $(addsuffix _bonus.c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix _bonus.o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

#$(OBJ): $(SRC) | $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean :
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)
	$(RM) -r *.dSYM

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : clean fclean all re
