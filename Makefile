#* ************************************************************************** */
#*                                                                            */
#*                                                        :::      ::::::::   */
#*   Makefile                                           :+:      :+:    :+:   */
#*                                                    +:+ +:+         +:+     */
#*   By: gmarra <gmarra@student.42firenze.it>       +#+  +:+       +#+        */
#*                                                +#+#+#+#+#+   +#+           */
#*   Created: 2024/12/18 16:15:29 by gmarra            #+#    #+#             */
#*   Updated: 2024/12/18 17:30:28 by gmarra           ###   ########.fr       */
#*                                                                            */
#* ************************************************************************** */

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
SRCS = ft_printf.c ft_printf_utils_parsing.c ft_printf_utils.c \
	ft_printf_utils_str.c ft_printf_utils_conv.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
	@echo "%                                            %"
	@echo "% Libreria $(NAME) creata con successo %"
	@echo "%                                            %"
	@echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

bonus: all

clean:
	@rm -f $(OBJS)
	@echo "%%%%%%%%%%%%%%%%%%%%%"
	@echo "%                   %"
	@echo "% File OBJS rimossi %"
	@echo "%                   %"
	@echo "%%%%%%%%%%%%%%%%%%%%%"

fclean: clean
	@rm -f $(NAME)
	@echo "%                   %"
	@echo "%    ALL CLEAN      %"
	@echo "%                   %"
	@echo "%%%%%%%%%%%%%%%%%%%%%"

re: fclean all

.PHONY: all clean fclean re
