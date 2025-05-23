# /* ************************************************************************** */
# /*                                                                            */
# /*                                                        :::      ::::::::   */
# /*   Makefile                                           :+:      :+:    :+:   */
# /*                                                    +:+ +:+         +:+     */
# /*   By: pstrohal <pstrohal@42.heilbronn.de>        #+#  +:+       +#+        */
# /*                                                +#+#+#+#+#+   +#+           */
# /*   Created: 2024-12-19 22:07:15 by pstrohal          #+#    #+#             */
# /*   Updated: 2024-12-19 22:07:15 by pstrohal         ###   ########.fr       */
# /*                                                                            */
# /* ************************************************************************** */

NAME = BaseGenerator

CC = c++


SRC_DIR := ./src/
OBJ_DIR = ./obj
INC_DIR := ./inc
DEP_DIR := $(OBJ_DIR)


vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INC_DIR)
vpath %.d $(DEP_DIR)


FILES =	main.cpp\
		Base.cpp


SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ =	$(addprefix $(OBJ_DIR)/, $(FILES:%.cpp=%.o))

DEP:= $(OBJ:.o=.d)
DEPFLAGS = -MMD -MP
FLAGS = -Wall -Wextra -Werror -std=c++17
INCLUDES = -I$(INC_DIR)

all: $(NAME)
-include $(DEP)


$(NAME):$(OBJ)
	@$(CC) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re