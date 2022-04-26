server = server 
client = client
server_bonus = server_bonus
client_bonus = client_bonus
server_src = server.c utils.c
client_src = client.c utils.c
server_bonus_src = server_bonus.c utils.c ft_itoa.c
client_bonus_src = client_bonus.c utils.c ft_itoa.c

GCC		= gcc

FLGS	= -Wall -Wextra -Werror

server_obj = $(server_src:.c=.o)
client_obj = $(client_src:.c=.o)
server_bonus_obj = $(server_bonus_src:.c=.o)
client_bonus_obj = $(client_bonus_src:.c=.o)

all : $(client) $(server)
	
$(client) : $(client_obj) 
		$(GCC) $(FLGS) $(client_obj) -o $(client)  
$(server) : $(server_obj)
		$(GCC) $(FLGS) $(server_obj) -o $(server)  
.c.o:
			$(GCC) $(FLGS) -c $<


bonus : $(client_bonus) $(server_bonus) 
	
$(client_bonus) : $(client_bonus_obj)
		$(GCC) $(FLGS) $(client_obj) -o $(client_bonus)  
$(server_bonus) : $(server_bonus_obj)
		$(GCC) $(FLGS) $(server_obj) -o $(server_bonus)  

clean :
	rm -rf *.o

fclean : clean
	rm -rf client server
	rm -rf client_bonus server_bonus

re:			fclean all
