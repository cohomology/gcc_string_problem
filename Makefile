FLAGS= -std=gnu++11 -fvisibility=hidden 
CC = g++ $(FLAGS)
LINK = g++ -L. -lstdc++ $(FLAGS)

main: main.cpp dll
	$(CC) -c $< -o $@.o
	$(LINK) -ldll -o $@ $@.o  

dll: dll.cpp
	$(CC) -c $< -fPIC -o $@.o
	$(LINK) -shared -o lib$@.so $@.o

.PHONY: clean
clean:
	rm -f *.o *.so main > /dev/null 2>&1 

