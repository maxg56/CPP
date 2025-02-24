# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: max <max@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 10:15:47 by max               #+#    #+#              #
#    Updated: 2025/02/12 22:56:40 by max              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME        = 


INCLUDE     = include

TMP 	   = .tmp/
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

RM          = rm -f
MKDIR       = mkdir


# **************************************************************************** #
#                                   Colors                                     #
# **************************************************************************** #

DEF_COLOR           =   \033[0;39m
GRAY                =   \033[0;90m
RED                 =   \033[0;91m
GREEN               =   \033[0;92m
YELLOW              =   \033[0;93m
BLUE                =   \033[0;94m
MAGENTA	            =   \033[0;95m
CYAN                =   \033[0;96m
WHITE               =   \033[0;97m
BOLD                =   $'\x1b[1m'
END                 =   $'\x1b[0m'
TERM_UP             =   \033[1A
TERM_CLEAR_LINE     =   \033[2K\r

# **************************************************************************** #
#                                   Sources                                    #
# **************************************************************************** #

SRC = ./src/main.cpp 


OBJ_DIR       = $(TMP)obj/
OBJ           = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRC))

DEPS            = $(OBJ:.o=.d)

# **************************************************************************** #
#                             progress_update                                  #
# **************************************************************************** #

COMPILED_COUNT  = 0

TOTAL_FILES     = $(words $(SRC)) 
define progress_update
    @if [ ! -f .compiled_count ]; then \
        echo 0 > .compiled_count; \
        printf "\n"; \
    fi; \
    COMPILED_COUNT=$$(cat .compiled_count); \
    COMPILED_COUNT=$$((COMPILED_COUNT + 1)); \
    echo $$COMPILED_COUNT > .compiled_count; \
    printf "$(TERM_UP)$(TERM_CLEAR_LINE)$(CYAN)Compilation progress: \
        $$((COMPILED_COUNT * 100 / $(TOTAL_FILES)))%% $(BLUE) ->$(1) $(DEF_COLOR)\n"; \
    if [ $$COMPILED_COUNT -eq $(TOTAL_FILES) ]; then \
        rm -f .compiled_count; \
    fi
endef
# **************************************************************************** #\
#                                   Rules                                      #
# **************************************************************************** #

all: $(NAME)
	

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -lreadline  $(OBJ) -o $(NAME)
	@printf "$(GREEN)%s compiled!\n$(DEF_COLOR)" $(NAME)



$(OBJ_DIR)%.o: %.cpp | $(OBJF)
	@mkdir -p $(dir $@)
	$(call progress_update,$(notdir $@))
	@$(CC) $(CFLAGS)  -I $(INCLUDE) -c $< -o $@

-include $(DEPS)

%.d: %.cpp
	@$(CC) $(CFLAGS) -MM $< -MF $@

$(OBJF):
	@$(MKDIR) -p $(OBJ_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		$(RM) -r $(OBJ_DIR); \
		printf "$(YELLOW)Removing %d objects from \"%s\" folder.\n$(DEF_COLOR)" $(words $(OBJ)) $(OBJ_DIR);\
	fi

fclean: clean
	@if [ -e $(LIBFT) ]; then \
		printf "$(YELLOW)Removing \"%s\"...\n$(DEF_COLOR)" $(LIBFT);\
		$(RM) $(LIBFT);\
	fi
	@if [ -e $(LIBFT_INC_H) ]; then \
		printf "$(YELLOW)Removing \"%s\"...\n$(DEF_COLOR)" $(INC_DIR)/$(LIBFT_INC_H); \
		$(RM) $(LIBFT_INC_H);\
	fi
	@if [ -e $(NAME) ]; then \
		printf "$(YELLOW)Removing \"%s\"...\n$(DEF_COLOR)" $(NAME);\
		$(RM) -r $(NAME);\
	fi

re: fclean all

.PHONY: all clean fclean re 
