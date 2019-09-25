default: all

get-deps:
	# Assuming Debian or Ubuntu here
	sudo apt-get install -y build-essential check

dictionary.o: dictionary.c dictionary.h
	gcc -Wall -c $^

spell.o: spell.c
	gcc -Wall -c $^

test.o: test_main.c
	gcc -Wall -c $^

main.o: main.c
	gcc -Wall -c $^

test: dictionary.o spell.o test_main.o
	gcc -Wall $^ -lcheck -lm -lrt -lpthread -lsubunit -o test

all: test
	./test

clean:
	rm -f dictionary.o spell.o main.o test *.gch
