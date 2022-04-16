# Section Settings

NAME		=	sdl_window.out
# TEST_NAME	=	unit_test

OBJ_DIR		=	obj/
SRC_DIR		=	src/
INCL_DIR	=	incl/
# TEST_DIR	=	unit_tests/

MAIN		?=	$(SRC_DIR)main.cpp
CLASSES		=	Vector2\
				Renderer\
				InputHandler

OBJS		=	$(CLASSES:%=$(OBJ_DIR)%.o)
HPPS		=	$(CLASSES:%=$(INCL_DIR)%.hpp)

CC			=	g++
CFLAGS		=	-Wall -Wextra -pedantic
TEST_CFLAGS	=	$(CFLAGS)

INCLUDE		=	-I $(INCL_DIR)
LINK		=	-lSDL2

# TEST_SRC	=	


# Section Rules

all: $(NAME)

$(NAME): $(OBJS) $(HPPS) $(MAIN)
	$(CC) -o $(NAME) $(OBJS) $(MAIN) $(INCLUDE) $(LINK) $(CFLAGS)

# local_test: $(TEST_SRC) $(OBJS)
#	 $(CC) -D TEST=1 -o $(TEST_NAME) $(TEST_SRC) $(OBJS) $(LINKING) -lcriterion -L ~/.brew/lib -I ~/.brew/include -std=c++11
#	 ./$(TEST_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HPPS)
	$(CC) $(CFLAGS) $(LINK) $(INCLUDE) -c $< -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

re: fclean all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TEST_NAME)
	rm -f $(NAME)

.PHONY: all clean fclean re
