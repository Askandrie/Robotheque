ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

SHELL := /bin/bash

# Couleurs et style
BLINK_GREEN	:=	\033[5;32m
BGREEN		:=	\033[1;32m
BHYEL		:=	\033[1;93m
BOLD		:=	\033[1m
NC			:=	\033[0m

# Nom du programme
NAME := Robotheque

# Dossiers sources et objets
SRC_DIR := src
INC_DIR := include
OBJ_DIR := .build

# Fichiers source
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Objets et dépendances
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Compilateur et flags
CC := cc
CFLAGS	:=	-Wall -Werror -Wextra  -MMD -MP -I$(INC_DIR) -I/usr/include

LDFLAGS	:=	-lcsv


# Règles principales
all: title $(NAME)
	@echo -e "\t$(BLINK_GREEN)$(NAME) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NAME)$(NC) is located in $(BOLD)$(shell find . -iname "$(NAME)")$(NC) !\n"

# Linkage
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) && echo -e "$(BGREEN)[✔]$(NC)\tLinking:\t$(BOLD)$@$(NC)\n"

# Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ && echo -e "$(BGREEN)[✔]$(NC)\tCompiling:\t$(BOLD)$(notdir $<)$(NC)"

# Inclusion des dépendances
-include $(DEPS)

# Nettoyage
clean:
	@rm -rf $(OBJ_DIR) && printf "Cleaning: $(OBJ_DIR)\n"

fclean: clean
	@rm -f $(NAME) && printf "Cleaning: $(NAME)\n"

re: fclean all

# Affichage joli du titre
title:
	@echo -e ""
	@echo -e "\t\t$(BHYEL)┍━━━━━━━━━━━»•» 🌸 «•«━┑$(NC)"
	@echo -e "\t\t$(BHYEL) ROBOTHEQUE COMPILATION $(NC)"
	@echo -e "\t\t$(BHYEL)┕━»•» 🌸 «•«━━━━━━━━━━━┙$(NC)"
	@echo -e ""

# Cibles phony
.PHONY: all clean fclean re title