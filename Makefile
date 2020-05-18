cc=gcc      // this is the variable which is used in the target.
MAKE=make
RM =rm

#targets .
all: 
	gcc -o client client.c	
	gcc -o server server.c
	gnome-terminal -t server --working-directory=/home/cls/dev/Client-Server -- "./server"
	sleep 10s 
	$(MAKE) client_target	


#another target for client
client_target:
	./client  


# clean:server client
# 	$(RM) server
# 	$(RM) client