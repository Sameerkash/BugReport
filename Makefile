cc=gcc      // this is the variable which is used in the target.
MAKE=make
RM =rm

#targets .
run: 
	gcc -o bug bug.c
	./a.out	
	

clean: 
	$(RM) bugs.txt
# clean:server client
# 	$(RM) server
# 	$(RM) client