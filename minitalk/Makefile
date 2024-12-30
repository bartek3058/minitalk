# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 09:46:20 by brogalsk          #+#    #+#              #
#    Updated: 2024/12/28 09:46:21 by brogalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c
SRCC = client.c
OBJS = $(SRCS:.c=.o) $(SRCC:.c=.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: $(FT_PRINTF_LIB) server client

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: $(SRCS:.c=.o)
	$(CC) $(CFLAGS) $^ $(FT_PRINTF_LIB) -o $@

client: $(SRCC:.c=.o)
	$(CC) $(CFLAGS) $^ $(FT_PRINTF_LIB) -o $@

clean:
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@rm -f server client

re: fclean all

.PHONY: all clean fclean re
