all:
	gcc -o fcgi-out main.c -lfcgi

run: fcgi-out
	spawn-fcgi -a 127.0.0.1 -n -p 65432 -F 1 -- fcgi-out /tmp

clean:
	rm fcgi-out
