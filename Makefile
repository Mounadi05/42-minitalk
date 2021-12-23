server = server 
client = client
server_bonus = server_bonus
client_bonus = client_bonus

all : $(client) $(server) 

$(server) :
	@gcc   server.c utils.c -o $(server)  
	@echo "\033[1;32m server is ready"
$(client) :
	@gcc   client.c utils.c -o $(client)  
	@echo "\033[1;32m client is ready"

bonus : $(client_bonus) $(server_bonus) 
	
$(client_bonus) :
	@gcc -Wall -Wextra -Werror client_bonus.c utils.c ft_itoa.c -o $(client_bonus)
	@echo "\033[1;32m client_bonus is ready"
$(server_bonus) :
	@gcc -Wall -Wextra -Werror server_bonus.c utils.c ft_itoa.c -o $(server_bonus)
	@echo "\033[1;32m server_bonus is ready"

clean :
	rm -rf client server
	rm -rf client_bonus server_bonus

fclean : clean
	rm -rf clien server
	rm -rf client_bonus server_bonus

re:			fclean all
