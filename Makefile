gui	: gui.c 
	 cc -g -Wall -o $@ $^ `pkg-config --libs --cflags gtk+-3.0`
str_rev : str_rev.c 
	cc -g -Wall -o $@ $^ 
pthread1 : pthread1.c 
	cc -g -Wall -o $@ $^ -lpthread

tgstrdup : tgstrdup.c 
	cc -g -Wall -o $@ $^ 
better-sleep : better-sleep.c 
	cc -g -Wall -o $@ $^

math : math.c
	cc -g -Wall -o $@ $^ -lm

clean :
	@ rm -rf *.o  gui str_rev tgstrdup better-sleep *.c~ *.h~ 
