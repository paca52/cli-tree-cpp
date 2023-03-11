
GXX = g++
FLAGS = -std=c++20 -Wall -Wextra -pedantic

main: main.cpp
	$(GXX) $< -o $@ $(FLAGS)

clean:
	rm $(OBJ).exe
