all:
	g++ -o fcgi-out main.cpp FCgiIO.cpp -lfcgi -lcgicc -lfcgi++

run: fcgi-out
	spawn-fcgi -a 127.0.0.1 -n -p 65432 -F 1 -- fcgi-out /tmp

clean:
	rm fcgi-out
