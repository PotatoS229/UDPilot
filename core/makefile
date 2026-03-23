CC = g++
all: ../release_project/main

../release_project/main: ../release_project/main.o
	mkdir -p ../release_project
	${CC} -o $@ $^

../release_project/main.o: src/main.cpp
	mkdir -p ../release_project
	${CC} -c $< -o $@

clean:
	rm -f ../release_project/main ../release_project/main.o

.PHONY: all clean