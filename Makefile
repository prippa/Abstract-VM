NAME		=	avm
# FLAGS		= 	-Wall -Werror -Wextra
COMPILER	=	g++ -std=c++11

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_OBJ		= 	./obj/

HEAD_AVM	=	IOperand.interface.hpp Exceptions.namespace.hpp

SRC_AVM		=	main.cpp Exceptions.namespace.cpp

INC_PATH 	= 	$(addprefix $(DIR_INC), $(HEAD_AVM))

OBJ 		= 	$(addprefix $(DIR_OBJ), $(SRC_AVM:.cpp=.o))
INC 		= 	$(addprefix -I, $(DIR_INC))

all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

$(NAME): $(OBJ)
	@$(COMPILER) -o $(NAME) $(OBJ)
	@echo "Compiling" [ $(NAME) ]

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp $(INC_PATH)
	@$(COMPILER) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files avm ]"

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files avm ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all
