default: all

get-deps:
	# Assuming Debian or Ubuntu here
	sudo apt-get install -y build-essential check

dictionary.o: dictionary.c dictionary.h
	gcc --coverage -Wall -c $^

spell.o: spell.c
	gcc --coverage -Wall -c $^

test_main.o: test_main.c
	gcc --coverage -Wall -c $^ 

main.o: main.c
	gcc --coverage -Wall -c $^

test: dictionary.o spell.o test_main.o
	gcc -ftest-coverage --coverage -Wall $^ -lcheck -lm -lrt -lpthread -lsubunit -o test

main: dictionary.o spell.o main.o
	gcc --coverage -Wall $^ -lcheck -lm -lrt -lpthread -lsubunit -o main

all: test main
	./test
	./main

clean:
	rm -f *.o test *.gch main
