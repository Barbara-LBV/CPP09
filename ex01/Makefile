# Variables
COMP 	= c++
FLAGS 	= -Wall -Wextra -Werror -std=c++98 -g3
NAME	= RPN

# Source files list
SRCS_DIR 	= src/
SRCS_NAME 	= main.cpp \
			RPN.cpp

SRCS		= $(wildcard $(SRCS_DIR)*.cpp)

OBJS_DIR	= objs/
OBJS_NAME	= $(patsubst %.cpp, %.o, $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_DIR), $(OBJS_NAME))

DEPS		= $(addprefix $(OBJS_DIR), $(SRCS_NAME:%.cpp=%.d))

# Headers list
HEADER_DIR	:=	/lib/
HEADER		:=	-I.$(HEADER_DIR)

COLOR		= \e[1;36m
BLUE		= \e[32;1m
BOLD 		= "\033[1m"
GREEN 		= "\033[92m"
NC 			= "\033[0m"

# Target
all: $(NAME)

# Target to build the executable
$(NAME): $(OBJS) title
	@$(COMP) $(FLAGS) ${HEADER} ${OBJS} -o $(NAME)
	@echo ${GREEN}${BOLD}Compilation ${NC}[${GREEN}OK${NC}]
	
$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@$(COMP) $(FLAGS) $(HEADER) -c $< -o $@ 
	@echo ${BOLD}Object Files Creation ${NC}[${GREEN}OK${NC}]

# Target to clean the object files
clean:
	@rm -rf $(OBJS_DIR)
	@echo ${GREEN}${BOLD}Objects cleaned${NC}

fclean : clean
		@rm -rf $(NAME)
		@echo ${GREEN}${BOLD}Cleanning ${NC}[${GREEN}OK${NC}]

re : fclean all

-include $(DEPS)

.SECONDARY: $(OBJS) 

.PHONY: all clean fclean re

define TITLE 
${COLOR}
	🭽🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🭾
	┃┃                                                                                         ┃┃
	┃┃  ▓▓▓▓▓▓▓▓   ▓▓▓▓▓▓▓    ▓▓▓▓▓▓▓    ▓▓▓▓▓▓▓▓▓   ▓▓▓▓▓▓▓▓▓       //  ▓▓▓▓▓▓▓▓▓      ▓▓     ┃┃
	┃┃  ▓▓    ▓▓  ▓▓     ▓▓  ▓▓     ▓▓   ▓▓     ▓▓   ▓▓     ▓▓      //   ▓▓     ▓▓     ▓▓▓     ┃┃
	┃┃  ▒▒        ▒▒     ▒▒  ▒▒     ▒▒   ▒▒     ▒▒   ▒▒     ▒▒     //    ▒▒     ▒▒   ▒▒ ▒▒     ┃┃
	┃┃  ▒▒        ▒▒▒▒▒▒▒    ▒▒▒▒▒▒▒     ▒▒     ▒▒   ▒▒▒▒▒▒▒▒▒    //     ▒▒     ▒▒      ▒▒     ┃┃
	┃┃  ▒▒        ▒▒         ▒▒          ▒▒     ▒▒          ▒▒   //      ▒▒     ▒▒      ▒▒     ┃┃
	┃┃  ░░    ░░  ░░         ░░          ░░     ░░          ▒▒  //       ░░     ░░      ░░     ┃┃
	┃┃  ░░░░░░░░  ░░         ░░          ░░░░░░░░░   ░░░░░░░░░ //        ░░░░░░░░░   ░░░░░░░   ┃┃
	┃┃                                                                                         ┃┃
	🭼🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🮀🭿
${COLOR}                                                                                                          
endef
export TITLE

title :
	clear
	@echo "$$TITLE" ${NC}