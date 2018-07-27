NAME		=	avm
# FLAGS		= 	-Wall -Werror -Wextra
COMPILER	=	g++ -std=c++11

DIR_INC		=	./includes/
DIR_INC_T	=	$(DIR_INC)types/
DIR_SRC		=	./source/
DIR_SRC_T	=	$(DIR_SRC)types/
DIR_OBJ		= 	./obj/

#-------------------------- Header files ---------------------------------------
HEAD_AVM	=	IOperand.interface.hpp Exceptions.namespace.hpp Base.class.hpp\
				Regex.macroses.hpp Factory.class.hpp

HEAD_AVM_T	=	Int8.class.hpp\
				Int16.class.hpp\
				Int32.class.hpp\
				Float.class.hpp\
				Double.class.hpp
#-------------------------------------------------------------------------------

#-------------------------- Source files ---------------------------------------
SRC_AVM		=	main.cpp Exceptions.namespace.cpp Base.class.cpp\
				Factory.class.cpp

SRC_AVM_T	=	Int8.class.cpp\
				Int16.class.cpp\
				Int32.class.cpp\
				Float.class.cpp\
				Double.class.cpp
#-------------------------------------------------------------------------------

INC_PATH 	= 	$(addprefix $(DIR_INC), $(HEAD_AVM))
INC_PATH_T 	= 	$(addprefix $(DIR_INC_T), $(HEAD_AVM_T))

OBJ 		= 	$(addprefix $(DIR_OBJ), $(SRC_AVM:.cpp=.o) $(SRC_AVM_T:.cpp=.o))
INC 		= 	$(addprefix -I, $(DIR_INC) $(DIR_INC_T))

all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

#-------------------------- Compil Block ---------------------------------------
$(NAME): $(OBJ)
	@$(COMPILER) -o $(NAME) $(OBJ)
	@echo "Compiling" [ $(NAME) ]
#-------------------------------------------------------------------------------

#-------------------------- Link Block -----------------------------------------
#source
$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp $(INC_PATH)
	@$(COMPILER) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#types
$(DIR_OBJ)%.o: $(DIR_SRC_T)%.cpp $(INC_PATH_T)
	@$(COMPILER) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]
#-------------------------------------------------------------------------------

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files avm ]"

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files avm ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all
