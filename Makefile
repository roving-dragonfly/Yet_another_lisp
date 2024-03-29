NAME= yal
SRC_PATH= src/
SRC_FILES= main.c

SRC= $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ_PATH= obj/
OBJ_FILES= $(SRC_FILES:.c=.o)
OBJ= $(addprefix $(OBJ_PATH),$(OBJ_FILES))
HDR_PATH= include/
HDR_FILES= yal.h
HDR= $(addprefix $(HDR_PATH),$(HDR_FILES))
CC= clang
CC_FLAGS= -v -Ofast -Weverything -Wall  -Wextra -g3  -fsanitize=address -fsanitize-blacklist=my_ignores.txt #-Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDR)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) -I$(HDR_PATH) -o $@ -c $<
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
