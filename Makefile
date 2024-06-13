# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 14:29:25 by nfararan          #+#    #+#              #
#    Updated: 2024/06/13 17:13:16 by nfararan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	client
CLIENT_SRC	=	ft_client.c utils.c utils_2.c
CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)
SERVER	=	server
SERVER_SRC	=	ft_server.c utils.c utils_2.c
SERVER_OBJS	=	$(SERVER_SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror -g
CC	=	cc

all: client server

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(CLIENT):	$(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

$(SERVER):	$(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean:	clean
	rm -f $(CLIENT) $(SERVER)

re:	clean all

.PHONY: all clean fclean re
